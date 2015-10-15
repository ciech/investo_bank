#include <broker_with_volume_based_commission.hpp>

namespace digi
{
    double BrokerWithVolumeBasedCommission::calculate_commission(const Order & order) const
    {
        const int volume = order.volume();
        if (volume <= 40)
        {
            return 0.03;
        }
        else if (volume <= 80)
        {
            return 0.025;
        }
        return 0.02;
    }
}
