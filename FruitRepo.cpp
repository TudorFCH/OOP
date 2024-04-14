#include <algorithm>
#include "FruitRepo.h"

FruitRepo::FruitRepo() {
    fruits.push_back(Fruit("Apple", "Romania", "15.04.2024", 370, 6));
    fruits.push_back(Fruit("Pear", "Romania", "21.04.2024", 480, 11));
    fruits.push_back(Fruit("Banana", "Panama", "03.05.2024", 590, 7));
    fruits.push_back(Fruit("Cherry", "Romania", "10.05.2024", 700, 80));
    fruits.push_back(Fruit("Strawberry", "Romania", "18.05.2024", 810, 26));
    fruits.push_back(Fruit("Plum", "Romania", "26.05.2024", 920, 19));
    fruits.push_back(Fruit("Grape", "Romania", "02.06.2024", 1030, 22));
    fruits.push_back(Fruit("Blueberry", "Romania", "11.06.2024", 1140, 64));
    fruits.push_back(Fruit("Orange", "Spain", "20.06.2024", 1250, 6));
    fruits.push_back(Fruit("Peach", "Romania", "29.06.2024", 1360, 35));
}

void FruitRepo::addFruit(const Fruit& fruit){
    fruits.push_back(fruit);
}

void FruitRepo::deleteFruit(const std::string& name){
    for (auto it = fruits.begin(); it != fruits.end(); ++it){
        if(it->getName() == name){
            fruits.erase(it);
            break;
        }
    }
}

std::vector<Fruit> FruitRepo::getShortSupplyFruits(int threshold) const {
    std::vector<Fruit> shortSupplyFruits;
    for(const auto& fruit: fruits){
        if(fruit.getQuantity() < threshold){
            shortSupplyFruits.push_back(fruit);
        }
    }
    return shortSupplyFruits;
}

std::vector<Fruit> FruitRepo::getFruitsSortedByExpiry() const {
    std::vector<Fruit> sortedFruits = fruits;
    std::sort(sortedFruits.begin(), sortedFruits.end(), [](const Fruit& a, const Fruit& b){
        int dayA, monthA, yearA;
        int dayB, monthB, yearB;
        sscanf(a.getExpiryDate().c_str(), "%d.%d.%d", &dayA, &monthA, &yearA);
        sscanf(b.getExpiryDate().c_str(), "%d.%d.%d", &dayB, &monthB, &yearB);

        if(yearA != yearB){
            return yearA<yearB;
        }
        if(monthA != monthB){
            return monthA<monthB;
        }
        return dayA<dayB;
    });
    return sortedFruits;
}

std::vector<Fruit> FruitRepo::findFruits(const std::string& searchString) const{
    if(searchString.empty()){
        std::vector<Fruit> allFruits = fruits;
        std::sort(allFruits.begin(), allFruits.end(), [](const Fruit& a, const Fruit& b){
            return a.getName()<b.getName();
        });
        return allFruits;
    }
    else{
        std::vector<Fruit> foundFruits;
        for(const auto& fruit : fruits){
            if(fruit.getName().find(searchString) != std::string::npos){
                foundFruits.push_back(fruit);
            }
        }
        return foundFruits;
    }
}