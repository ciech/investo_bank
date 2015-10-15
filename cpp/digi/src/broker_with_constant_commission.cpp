#include <broker_with_constant_commission.hpp>

namespace digi
{
    double BrokerWithConstantCommission::calculate_commission(const Order & order) const
    {
        return 0.05;
    }
}
