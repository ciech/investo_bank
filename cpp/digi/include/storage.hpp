#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <ilog_provider.hpp>
#include <ilog_storage.hpp>

namespace digi
{
  class Storage: public ILogProvider, public ILogStorage
  {
    public:
      Storage():client_logs_(), broker_logs_(), client_names_(), broker_names_(){};
      virtual ~Storage(){};

      virtual void store_client_log(const std::string & client_name,
                          const Order::Type & type,
                          const int & volume,
                          const double & amount);
      virtual void store_broker_log(const std::string & broker_name,
                          const int & volume);

      virtual const std::set<std::string> & get_broker_names() const;
      virtual const std::set<std::string> & get_client_names() const;
      virtual const std::vector<std::unique_ptr<ClientLog>> & get_client_logs() const;
      virtual const std::vector<std::unique_ptr<BrokerLog>> & get_broker_logs() const;

    private:
      std::vector<std::unique_ptr<ClientLog>> client_logs_;
      std::vector<std::unique_ptr<BrokerLog>> broker_logs_;
      std::set<std::string> client_names_;
      std::set<std::string> broker_names_;
  };
}

#endif
