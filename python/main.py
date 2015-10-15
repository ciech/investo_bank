from digi.application import Application
from digi.order import Order


def main():
    trader = Application()
    test_data = [("A", "BUY", 10),
                 ("B", "BUY", 40),
                 ("A", "BUY", 50),
                 ("B", "BUY", 100),
                 ("B", "SELL", 80),
                 ("C", "SELL", 70),
                 ("A", "BUY", 130),
                 ("B", "SELL", 60)]

    for i in range(len(test_data)):
        print trader.process_order(Order(*test_data[i]))

    for broker, volume in trader.report_brokers_volume():
        print broker, volume

    for client, net_position in trader.report_clients_net_position():
        print client, net_position

if __name__ == "__main__":
    main()
