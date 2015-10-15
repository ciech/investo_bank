#include <order.hpp>
#include <application.hpp>
#include <iostream>
#include <vector>
#include <memory>

static void prepare_test_data(std::vector<std::unique_ptr<digi::Order>> & orders)
{
    using namespace std;
    using namespace digi;
    orders.push_back(move(unique_ptr<Order>(new Order("ClientA", Order::BUY, 10))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientB", Order::BUY, 40))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientA", Order::BUY, 50))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientB", Order::BUY, 100))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientB", Order::SELL, 80))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientC", Order::SELL, 70))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientA", Order::BUY, 130))));
    orders.push_back(move(unique_ptr<Order>(new Order("ClientB", Order::SELL, 60))));
}

int main(int argc, char *argv[])
{
    try
    {
        std::vector<std::unique_ptr<digi::Order>> orders;
        auto & trader = digi::TradeApplication::instance();
        prepare_test_data(orders);
        for(auto const & order: orders)
        {
            std::cout << trader.execute_order(*order) << std::endl;
        }
        auto const & client_names = trader.get_client_names();
        for (auto const &name: client_names)
        {
            std::cout << name << " " << trader.get_client_net_position(name) << " ";
        }
        std::cout << std::endl;
        auto const & broker_names = trader.get_broker_names();
        for (auto const &name: broker_names)
        {
            std::cout << name << " " << trader.get_broker_total_volume(name) << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    catch (std::string info)
    {
        std::cout << info << std:: endl;
    }
}
