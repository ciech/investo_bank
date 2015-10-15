#ifndef REPORTER_HPP
#define REPORTER_HPP

#include <ilog_provider.hpp>

namespace digi
{

    class Reporter
    {
        public:
            Reporter(const ILogProvider &provider):log_provider_(provider){};
            double get_client_net_position(const std::string & client_name) const;
            int get_broker_total_volume(const std::string & broker_name) const;

        private:
            const ILogProvider &log_provider_;
    };

}

#endif
