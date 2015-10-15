#ifndef ORDER_HPP
#define ORDER_HPP
#include <string>

namespace digi
{

  class Order
  {
    public:
      enum Type
      {
        SELL,
        BUY
      };

      Order(const std::string& client_name,
            const Type & type,
            const int volume):client_name_(client_name), type_(type), volume_(volume)
      {
          if (volume_ % 10 != 0) throw std::string("Not multiple of 10");
          if (volume  <= 0 ) throw std::string("Volume to small");
      };
      const std::string& client_name() const { return client_name_; };
      const int volume() const { return volume_; };
      const Type type() const { return type_; };
      Order(const Order & order) = default;
      ~Order(){};

    private:
      const std::string client_name_;
      const Type type_;
      const int volume_;

  };
}

#endif
