#ifndef L4_POPA_TUDOR_FRUITREPO_H
#define L4_POPA_TUDOR_FRUITREPO_H

#include <vector>
#include "Fruit.h"

class FruitRepo{
private:
    std::vector<Fruit> fruits;

public:
    FruitRepo();
    void addFruit(const Fruit& fruit);
    void deleteFruit(const std::string& name);
    std::vector<Fruit> findFruits(const std::string& searchString) const;
    std::vector<Fruit> getShortSupplyFruits(int threshold) const;
    std::vector<Fruit> getFruitsSortedByExpiry() const;
};

#endif //L4_POPA_TUDOR_FRUITREPO_H
