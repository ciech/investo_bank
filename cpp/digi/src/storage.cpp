#include <storage.hpp>
#include <memory>

namespace digi
{
    void Storage::store_client_log(const std::string & client_name,
                               const Order::Type & type,
                               const int & volume,
                               const double & amount)
    {
      auto client_log = std::unique_ptr<ClientLog>(
          new ClientLog(client_name, type, volume, amount)
      );
      client_logs_.push_back(std::move((client_log)));
      std::string name = std::string(client_name);
      client_names_.insert(name);
    }

    void Storage::store_broker_log(const std::string & broker_name,
                        const int & volume)
    {
      auto broker_log = std::unique_ptr<BrokerLog>(new BrokerLog(broker_name, volume));
      broker_logs_.push_back(std::move(broker_log));
      broker_names_.insert(broker_name);
    }

    const std::set<std::string> & Storage::get_broker_names() const
    {
        return broker_names_;
    }
    const std::set<std::string> & Storage::get_client_names() const
    {
        return client_names_;
    }
    const std::vector<std::unique_ptr<ClientLog>> & Storage::get_client_logs() const
    {
        return client_logs_;
    }
    const std::vector<std::unique_ptr<BrokerLog>> & Storage::get_broker_logs() const
    {
        return broker_logs_;
    }
}
