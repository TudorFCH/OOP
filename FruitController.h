#ifndef L4_POPA_TUDOR_FRUITCONTROLLER_H
#define L4_POPA_TUDOR_FRUITCONTROLLER_H

#include "FruitRepo.h"

class FruitController{
private:
    FruitRepo fruitRepo;

public:
    FruitController();
    void addFruit(const std::string& name, const std::string& origin, const std::string& expiryDate, int quantity, int price);
    void deleteFruit(const std::string& name);
    std::vector<Fruit> findFruits(const std::string& searchString) const;
    std::vector<Fruit> getShortSupplyFruits(int threshold) const;
    std::vector<Fruit> getFruitsSortedByExpiry() const;
};

#endif //L4_POPA_TUDOR_FRUITCONTROLLER_H
