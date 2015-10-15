#include <trader.hpp>

#include <vector>
#include <memory>
namespace digi
{
      static void normalize_orders(std::vector<std::unique_ptr<Order>> & orders)
      {
          bool all_checked = false;
          while(!all_checked)
          {
              std::unique_ptr<Order> order_100 = {};
              std::unique_ptr<Order> order_rest = {};
              bool normalized = false;
              for(auto it = orders.begin(); it != orders.end(); it++)
              {
                   const Order & order = **it;
                   if (order.volume() > 100)
                   {
                       order_100  = std::unique_ptr<Order>(new Order(order.client_name(),
                                                                          order.type(),
                                                                          100));
                       order_rest = std::unique_ptr<Order>(new Order(order.client_name(),
                                                                          order.type(),
                                                                          order.volume()-100));

                       orders.erase(it);
                       normalized = true;
                       break;
                   }

                   if (it == orders.end()-1)
                   {
                       all_checked = true;
                   }
               }
               if (normalized)
               {
                   orders.push_back(std::move(order_100));
                   orders.push_back(std::move(order_rest));
               }
          }

      }

      double Trader::execute_order(const Order & order)
      {
          const double amount = get_amount_for_best_price(order);
          storage_.store_client_log(order.client_name(),
                                    order.type(),
                                    order.volume(),
                                    amount);
          return amount;
      }


      double Trader::get_amount_for_best_price(const Order & new_order)
      {
        std::vector<std::unique_ptr<Order>> orders;
        orders.push_back(std::unique_ptr<Order>(new Order(new_order)));
        normalize_orders(orders);
        double total_quote = 0;
        for (auto const &order: orders)
        {
            auto min_quote = 0.0;
            std::string broker_name;
            for(auto const & broker: brokers_)
            {
                const double quote = broker->quote(*order);
                if (0 == min_quote)
                {
                    min_quote = quote;
                    broker_name = broker->name();
                }
                else
                {
                    if (quote<min_quote)
                    {
                        min_quote = quote;
                        broker_name = broker->name();
                    }
                }
            }
            storage_.store_broker_log(broker_name, order->volume());
            total_quote+=min_quote;
        }
        return total_quote;
      }

}
