
from digi.broker import BrokerProvider
from digi.reporter import Reporter
from digi.trader import Trader
from digi.transaction_storage import TransactionStorage

class Application(object):

    def __init__(self):
        self.__brokers = [\
            BrokerProvider.provide(broker) for broker in\
                BrokerProvider.get_available_brokers_id()
                         ]
        self.__storage = TransactionStorage()
        self.__trader = Trader(self.__brokers, self.__storage)
        self.__reporter = Reporter(self.__storage)

    def process_order(self, order):
        return self.__trader.process_order(order)

    def report_brokers_volume(self):
        return self.__reporter.get_brokers_transacted_volume()

    def report_clients_net_position(self):
        return self.__reporter.get_clients_net_position()
