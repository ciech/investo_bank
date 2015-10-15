#ifndef BROKER_HPP
#define BROKER_HPP

#include <memory>
#include "ibroker.hpp"

namespace digi
{

  class Broker : public IBroker
  {
    public:
      enum Commission
      {
          CONSTANT,
          VOLUME_BASED
      };

      Broker(const std::string &name, const double price):name_(name), price_(price){};
      Broker(Broker&&) = default;
      Broker& operator=(Broker&&) = default;
      const std::string& name() const;
      double quote(const Order & order) const;
      virtual ~Broker(){};

      static std::unique_ptr<Broker> factory(const std::string &name, const Commission &commission);

    protected:
      virtual double calculate_commission(const Order & order) const = 0;

    private:
      std::string name_;
      double price_;
  };
}

#endif
