#ifndef BROKER_WITH_VALUE_BASED_COMMISSION_HPP
#define BROKER_WITH_VALUE_BASED_COMMISSION_HPP

#include <broker.hpp>

namespace digi
{
  class BrokerWithVolumeBasedCommission: public Broker
  {
      public:
          BrokerWithVolumeBasedCommission(const std::string &name, const double price):Broker(name, price){};
          ~BrokerWithVolumeBasedCommission(){};
      protected:
          virtual double calculate_commission(const Order & order) const;
  };
}

#endif
