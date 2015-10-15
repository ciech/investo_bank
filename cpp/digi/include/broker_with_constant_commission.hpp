#ifndef BROKER_WITH_CONSTANT_COMMISSION_HPP
#define BROKER_WITH_CONSTANT_COMMISSION_HPP

#include <broker.hpp>

namespace digi
{
  class BrokerWithConstantCommission: public Broker
  {
      public:
          BrokerWithConstantCommission(const std::string &name, const double price):Broker(name, price){};
          ~BrokerWithConstantCommission(){};
      protected:
          virtual double calculate_commission(const Order & order) const;
  };
}

#endif
