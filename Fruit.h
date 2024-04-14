#ifndef L4_POPA_TUDOR_FRUIT_H
#define L4_POPA_TUDOR_FRUIT_H

#include <string>

class Fruit{
private:
    std::string name;
    std::string origin;
    std::string expiryDate;
    int quantity;
    int price;

public:
    Fruit(const std::string& name, const std::string& origin, const std::string& expiryDate, int quantity, int price);

    std::string getName() const;
    std::string getOrigin() const;
    std::string getExpiryDate() const;
    int getQuantity() const;
    int getPrice() const;
};

#endif //L4_POPA_TUDOR_FRUIT_H
