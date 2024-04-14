#include <regex>
#include <iostream>
#include "FruitController.h"

FruitController::FruitController() : fruitRepo(){}

void FruitController::addFruit(const std::string& name, const std::string& origin, const std::string& expiryDate, int quantity, int price){
    std::regex datePattern("\\d{2}.\\d{2}.\\d{4}");
    if (!std::regex_match(expiryDate, datePattern)) {
        std::cout << "Invalid expiry date format. Please use DD.MM.YYYY format." << std::endl;
        return;
    }

    Fruit fruit(name, origin, expiryDate, quantity, price);
    fruitRepo.addFruit(fruit);
}

void FruitController::deleteFruit(const std::string& name){
    fruitRepo.deleteFruit(name);
}

std::vector<Fruit> FruitController::findFruits(const std::string& searchString) const{
    return fruitRepo.findFruits(searchString);
}

std::vector<Fruit> FruitController::getShortSupplyFruits(int threshold) const {
    return fruitRepo.getShortSupplyFruits(threshold);
}

std::vector<Fruit> FruitController::getFruitsSortedByExpiry() const {
    return fruitRepo.getFruitsSortedByExpiry();
}