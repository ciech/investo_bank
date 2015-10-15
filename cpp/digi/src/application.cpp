#include <application.hpp>
#include <broker.hpp>
#include <trader.hpp>
#include <memory>

namespace digi
{

    TradeApplication::TradeApplication():brokers_(),
                                         storage_(new Storage()),
                                         trader_(new Trader(brokers_, *storage_)),
                                         reporter_(new Reporter(*storage_))
    {
        using namespace std;
        brokers_.push_back(move(Broker::factory("Broker1", Broker::Commission::CONSTANT)));
        brokers_.push_back(move(Broker::factory("Broker2", Broker::Commission::VOLUME_BASED)));
    }

    double TradeApplication::execute_order(const Order &order)
    {
        return trader_->execute_order(order);
    }

    double TradeApplication::get_client_net_position(const std::string & client_name) const
    {
        return reporter_->get_client_net_position(client_name);
    }

    int TradeApplication::get_broker_total_volume(const std::string & broker_name) const
    {
        return reporter_->get_broker_total_volume(broker_name);
    }

    const std::set<std::string> & TradeApplication::get_broker_names() const
    {
        return storage_->get_broker_names();
    }

    const std::set<std::string> & TradeApplication::get_client_names() const
    {
        return storage_->get_client_names();
    }


}
