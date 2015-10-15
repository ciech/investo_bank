#include <reporter.hpp>

#include <vector>
#include <numeric>
#include <iostream>

namespace digi
{
      double Reporter::get_client_net_position(const std::string & client_name) const
      {
          const auto & client_orders = log_provider_.get_client_logs();
          auto total_volume = 0L;
          std::vector<double> prices = {};
          auto is_negative = []( const Order::Type type)->int { return (type==Order::SELL)?-1:1;};
          for (const auto & client: client_orders)
          {
              if (client_name == client->name)
              {
                  total_volume  += is_negative(client->type)*client->volume;
                  prices.push_back(client->amount/client->volume);
              }
          }
          const auto avg_price = std::accumulate(prices.begin(),prices.end(), 0.0)/prices.size();
          return avg_price * total_volume;
      }

      int Reporter::get_broker_total_volume(const std::string & broker_name) const
      {
          const auto & broker_logs = log_provider_.get_broker_logs();
          int total_volume = 0;
          for (const auto &broker: broker_logs)
          {
              if (broker->name == broker_name)
              {
                  total_volume+=broker->volume;
              }
          }
          return total_volume;

      }

}
