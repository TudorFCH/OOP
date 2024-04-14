#include <iostream>
#include <cassert>
#include "Fruit.h"
#include "FruitController.h"
#include "FruitRepo.h"

void testFruit() {
    Fruit fruit("Apple", "Romania", "15.04.2024", 370, 6);
    assert(fruit.getName() == "Apple");
    assert(fruit.getOrigin() == "Romania");
    assert(fruit.getExpiryDate() == "15.04.2024");
    assert(fruit.getQuantity() == 370);
    assert(fruit.getPrice() == 6);
}

void testFruitController() {
    FruitController fruitController;

    fruitController.addFruit("Blackberry", "USA", "01.01.2025", 10, 2);
    fruitController.addFruit("Mango", "Brazil", "02.02.2025", 15, 3);

    std::vector<Fruit> foundFruits = fruitController.findFruits("Mango");
    assert(foundFruits.size() == 1);
    assert(foundFruits[0].getName() == "Mango");

    fruitController.deleteFruit("Mango");
    foundFruits = fruitController.findFruits("Mango");
    assert(foundFruits.empty());

    std::vector<Fruit> sortedFruits = fruitController.getFruitsSortedByExpiry();
    assert(sortedFruits.size() == 11);
    assert(sortedFruits[0].getName() == "Apple");
    fruitController.deleteFruit("Blackberry");
}

void testFruitRepo() {
    FruitRepo fruitRepo;

    std::vector<Fruit> allFruits = fruitRepo.findFruits("");
    assert(allFruits.size() == 10);

    std::vector<Fruit> shortSupplyFruits = fruitRepo.getShortSupplyFruits(500);
    assert(shortSupplyFruits.size() == 2);

    std::vector<Fruit> sortedFruits = fruitRepo.getFruitsSortedByExpiry();
    assert(sortedFruits.front().getName() == "Apple");

    std::vector<Fruit> foundFruits = fruitRepo.findFruits("an");
    assert(foundFruits.size() == 2);
}

void testAll(){
    testFruit();
    testFruitController();
    testFruitRepo();
    std::cout<<"All tests passed!"<<std::endl;
}