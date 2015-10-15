

class Reporter(object):

    def __init__(self, transaction_storage):
        self.__storage = transaction_storage

    def get_brokers_transacted_volume(self):
        brokers = self.__storage.get_brokers()
        transacted_volume = []
        for broker in brokers:
            entries = self.__storage.get_entries_for_broker(broker)
            volumes = [entry['volume'] for entry in entries]
            transacted_volume.append((broker, sum(volumes)))
        return transacted_volume

    def get_clients_net_position(self):
        net_position = {}
        is_sell = lambda x: x is "SELL"
        get_sign = lambda x: -1 if is_sell(x) else 1
        clients = self.__storage.get_clients()
        for client in clients:
            trans = self.__storage.get_trans_for_client(client)
            volumes = []
            prices = []
            for tran in trans:
                volumes.append(tran['volume']*get_sign(tran['type']))
                prices.append(tran['amount']/tran['volume'])
            avg_price = sum(prices)/len(prices)
            net_position[client] = round(avg_price * sum(volumes), 3)
        return [(client, net_position[client]) for client in clients]
