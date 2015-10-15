#ifndef I_TRADER_HPP
#define I_TRADER_HPP

#include <string>
#include "order.hpp"

namespace digi
{
      class ITrader
      {
        public:
          virtual double execute_order(const Order & order) = 0;
          virtual ~ITrader(){};
      };
}

#endif
