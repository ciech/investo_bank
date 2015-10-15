#ifndef ILOG_STORAGE_HPP
#define ILOG_STORAGE_HPP
#include <string>
#include <order.hpp>

namespace digi
{
  class ILogStorage
  {
    public:
      virtual ~ILogStorage(){};
      virtual void store_client_log(const std::string & client_name,
                          const Order::Type & type,
                          const int & volume,
                          const double & amount) = 0;
      virtual void store_broker_log(const std::string & broker_name,
                          const int & volume) = 0;
  };
}

#endif
