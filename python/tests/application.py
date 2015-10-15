import unittest
from digi.application import Application
from digi.order import Order

class ApplicationTestCase(unittest.TestCase):

    def test_default(self):
        trader = Application()
        test_data = [("A", "BUY", 10),
                     ("B", "BUY", 40),
                     ("A", "BUY", 50),
                     ("B", "BUY", 100),
                     ("B", "SELL", 80),
                     ("C", "SELL", 70),
                     ("A", "BUY", 130),
                     ("B", "SELL", 60)]

        results = [ 15.645,
                    62.58,
                    77.9,
                    155.04,
                    124.64,
                    109.06,
                    201.975,
                    93.48]

        for i in range(len(test_data)):
            _, _, _, amount = trader.process_order(Order(*test_data[i]))
            self.assertTrue(amount == results[i])

if __name__ == '__main__':
    unittest.main()
