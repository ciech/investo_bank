#ifndef IBROKER_HPP
#define IBROKER_HPP

#include <string>
#include "order.hpp"

namespace digi
{
    class IBroker
    {
        public:
            virtual double quote(const Order & order) const = 0;
            virtual const std::string& name() const = 0;
            virtual ~IBroker(){};
    };
}

#endif
