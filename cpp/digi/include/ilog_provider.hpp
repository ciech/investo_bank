#ifndef ILOG_PROVIDER_HPP
#define ILOG_PROVIDER_HPP

#include <string>
#include <order.hpp>
#include <memory>
#include <vector>
#include <set>

namespace digi
{
  struct ClientLog
  {
    ClientLog(const std::string &name,
              const Order::Type &type,
              const int &volume,
              const double &amount):
              name(name), type(type), volume(volume), amount(amount){};
    ~ClientLog(){}

    const std::string name;
    const Order::Type type;
    const int volume;
    const double amount;
  };

  struct BrokerLog
  {
    BrokerLog(const std::string &name, const int &volume):
    name(name), volume(volume){};
    ~BrokerLog(){};

    const std::string name;
    const int volume;
  };

  class ILogProvider
  {
      public:
          virtual const std::set<std::string> & get_broker_names() const = 0 ;
          virtual const std::set<std::string> & get_client_names() const = 0;
          virtual const std::vector<std::unique_ptr<ClientLog>> & get_client_logs() const = 0;
          virtual const std::vector<std::unique_ptr<BrokerLog>> & get_broker_logs() const = 0;
          virtual ~ILogProvider(){};

  };
}

#endif
