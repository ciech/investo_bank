#include <broker.hpp>
#include <broker_with_constant_commission.hpp>
#include <broker_with_volume_based_commission.hpp>

static const double BROKER_WITH_CONSTANT_COMMISSION_PRICE = 1.49;
static const double BROKER_WITH_VALUE_BASED_COMMISSION_PRICE = 1.52;

namespace digi
{
    const std::string& Broker::name() const
    {
        return name_;
    }

    double Broker::quote(const Order & order) const
    {
        double const commission = 1 + calculate_commission(order);
        double const final_price = price_ * commission;
        return final_price * order.volume();
    }

    std::unique_ptr<Broker> Broker::factory(const std::string &name, const Commission &commission)
    {
        if (CONSTANT == commission)
        {
            return std::unique_ptr<Broker>
            (
              new BrokerWithConstantCommission(name, BROKER_WITH_CONSTANT_COMMISSION_PRICE)
            );
        }
        if (VOLUME_BASED == commission)
        {
            return std::unique_ptr<Broker>
            (
              new BrokerWithVolumeBasedCommission(name, BROKER_WITH_VALUE_BASED_COMMISSION_PRICE)
            );
        }
        return {};
    }
}
