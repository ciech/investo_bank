from digi.broker import Broker

def get_brokers_without_given(brokers, broker_name):
    return [broker for broker in brokers if broker.name != broker_name]

def normalize_order_volume(orders):
    normalized_orders = []
    for order in orders:
        if order.volume <= Broker.max_volume():
            normalized_orders.append(order)
        else:
            normalized_orders.extend(normalize_order_volume(\
                order.split_on_volume(Broker.max_volume())))
    return normalized_orders

def process_order_with_brokers(order, brokers):
    if brokers is None:
        return None, None, None
    quotes = [(broker, broker.quote(order.volume)) for broker in brokers]
    broker_quote = lambda pair: pair[1]
    broker_with_best_quote_finder = \
        lambda quotes: min(quotes, key=broker_quote)[0]
    broker = broker_with_best_quote_finder(quotes)
    amount = broker.execute(order.volume)
    return broker, order.volume, round(amount, 3)


class Trader(object):

    def __init__(self, brokers, transaction_storage=None):
        self.__brokers = brokers
        self.__storage = transaction_storage
        self.__trans_id = 0

    def process_order(self, new_order):
        orders = normalize_order_volume([new_order])
        brokers = self.__brokers
        total_amount = 0
        total_volume = 0
        for order in orders:
            broker, volume, amount = process_order_with_brokers(order, brokers)
            if broker != None:
                brokers = get_brokers_without_given(brokers, broker.name)
                if self.__storage:
                    self.__storage.add(self.__trans_id,
                                       order.client_name,
                                       broker.name,
                                       order.type,
                                       volume,
                                       amount)
                total_volume += volume
                total_amount += amount
            else:
                break
        self.__trans_id += 1
        return new_order.client_name, new_order.type, total_volume, total_amount

    @property
    def trans_id(self):
        return self.__trans_id
