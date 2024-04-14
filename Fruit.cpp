#include "Fruit.h"

Fruit::Fruit(const std::string& name, const std::string& origin, const std::string& expiryDate, int quantity, int price)
:name(name), origin(origin), expiryDate(expiryDate), quantity(quantity), price(price){}

std::string Fruit::getName() const{
    return name;
}

std::string Fruit::getOrigin() const{
    return origin;
}

std::string Fruit::getExpiryDate() const {
    return expiryDate;
}

int Fruit::getQuantity() const {
    return quantity;
}

int Fruit::getPrice() const {
    return price;
}