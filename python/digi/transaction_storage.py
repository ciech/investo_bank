
def filter_list_of_dicts(sequence, key, match):
    return [s for s in sequence if s[key] is match]

class TransactionStorage(object):

    def __init__(self):
        self.__log = []
        self.__brokers = set()
        self.__clients = set()
        self.__trans = {}

    def add(self, tr_id, client_name, broker_name, trans_type, volume, amount):
        self.__log.append({'id': tr_id,
                           'client': client_name,
                           'broker': broker_name,
                           'type': trans_type,
                           'volume': volume,
                           'amount': amount})
        self.__brokers.add(broker_name)
        self.__clients.add(client_name)
        if self.__trans.get(tr_id, None) is not None:
            volume += self.__trans[tr_id]['volume']
            amount += self.__trans[tr_id]['amount']
        self.__trans[tr_id] = {'client': client_name,
                               'type': trans_type,
                               'volume': volume,
                               'amount': amount}

    def get_entries_for_broker(self, broker):
        return filter_list_of_dicts(self.__log, 'broker', broker)

    def get_trans_for_client(self, client):
        trans = [self.__trans[trans_id] for trans_id in self.__trans.keys()]
        return filter_list_of_dicts(trans, 'client', client)

    def get_brokers(self):
        return [broker for broker in sorted(self.__brokers)]

    def get_clients(self):
        return [client for client in sorted(self.__clients)]

    def get_transactions(self):
        return self.__trans
