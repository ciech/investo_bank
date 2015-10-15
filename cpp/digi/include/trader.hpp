#ifndef TRADER_HPP
#define TRADER_HPP

#include "itrader.hpp"
#include "ibroker.hpp"
#include "ilog_storage.hpp"

#include <vector>
#include <memory>

namespace digi
{

  class Trader: public ITrader
  {
    public:

      Trader(const std::vector<std::unique_ptr<IBroker>> & brokers,
             ILogStorage & storage):brokers_(brokers), storage_(storage){};

      virtual double execute_order(const Order & order);
      virtual ~Trader(){};

    private:

      double get_amount_for_best_price(const Order & order);

      const std::vector<std::unique_ptr<IBroker>> & brokers_;
      ILogStorage &storage_;

  };
}

#endif
