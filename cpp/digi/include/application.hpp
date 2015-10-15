#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "order.hpp"
#include "ibroker.hpp"
#include "itrader.hpp"
#include "storage.hpp"
#include "reporter.hpp"
#include <string>

namespace digi
{

    class TradeApplication
    {
        public:
            static TradeApplication & instance()
            {
                static TradeApplication singleton;
                return singleton;
            }

            double execute_order(const Order &order);
            double get_client_net_position(const std::string & client_name) const;
            int get_broker_total_volume(const std::string & broker_name) const;
            const std::set<std::string> & get_broker_names() const;
            const std::set<std::string> & get_client_names() const;

        private:
            TradeApplication();
            ~TradeApplication(){};

            TradeApplication(const TradeApplication &);
            TradeApplication &operator=(const TradeApplication& );

            std::vector<std::unique_ptr<IBroker>> brokers_;
            std::unique_ptr<Storage> storage_;
            std::unique_ptr<ITrader> trader_;
            std::unique_ptr<Reporter> reporter_;
  };
}

#endif
