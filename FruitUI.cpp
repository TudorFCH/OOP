#include "FruitUI.h"

FruitUI::FruitUI(){}

void FruitUI::displayMenu() {
    std::cout<<"=== Fruit Shop Menu ==="<<std::endl;
    std::cout<<"1. Add Fruit"<<std::endl;
    std::cout<<"2. Delete Fruit"<<std::endl;
    std::cout<<"3. Find Fruits"<<std::endl;
    std::cout<<"4. List Fruits in Short Supply"<<std::endl;
    std::cout<<"5. List Fruits Sorted by Expiry Date"<<std::endl;
    std::cout<<"6. Exit"<<std::endl;
    std::cout<<"Enter your choice: ";
}

void FruitUI::processInput() {
    int choice;
    std::cin>>choice;
    if (std::cin.fail() || choice < 1 || choice > 6) {
        std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
        std::cin.clear();
        return;
    }

    switch(choice){
        case 1: {
            std::string name, origin, expiryDate;
            int quantity, price;
            std::cout<<"Enter name: ";
            std::cin>>name;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Name must be a string." << std::endl;
                break;
            }
            std::cout<<"Enter origin: ";
            std::cin>>origin;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Origin must be a string." << std::endl;
                break;
            }
            std::cout<<"Enter expiry date: ";
            std::cin>>expiryDate;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Expiry date must be a string." << std::endl;
                break;
            }
            std::cout<<"Enter quantity: ";
            std::cin>>quantity;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Quantity must be an integer." << std::endl;
                break;
            }
            std::cout<<"Enter price: ";
            std::cin>>price;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Price must be an integer." << std::endl;
                break;
            }
            fruitController.addFruit(name, origin, expiryDate, quantity, price);
            std::cout<<"Fruit added successfully."<<std::endl;
            break;
        }
        case 2: {
            std::string name;
            std::cout<<"Enter name of the fruit to delete: ";
            std::cin>>name;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Name must be a string." << std::endl;
                break;
            }
            fruitController.deleteFruit(name);
            std::cout<<"Fruit deleted successfully. "<<std::endl;
            break;
        }
        case 3: {
            std::cout<<"Enter search string: ";
            std::cin.ignore();
            std::string searchString;
            std::getline(std::cin, searchString);
            if(searchString.empty()){
                std::cout<<"Displaying all fruits:"<<std::endl;
                std::vector<Fruit> allFruits = fruitController.findFruits(searchString);
                for(const auto& fruit : allFruits){
                    std::cout<<"Name: "<<fruit.getName()<<", Origin: "<<fruit.getOrigin()
                    <<", Expiry Date: "<<fruit.getExpiryDate()<<", Quantity: "<<fruit.getQuantity()
                    <<", Price: "<<fruit.getPrice()<<std::endl;
                }
            }
            else{
                std::cout<<"Search results:"<<std::endl;
                std::vector<Fruit> foundFruits = fruitController.findFruits(searchString);
                if(foundFruits.empty()){
                    std::cout<<"No fruits found."<<std::endl;
                }
                else{
                    for(const auto& fruit : foundFruits){
                        std::cout<<"Name: "<<fruit.getName()<<", Origin: "<<fruit.getOrigin()
                        <<", Expiry Date: "<<fruit.getExpiryDate()<<", Quantity: "<<fruit.getQuantity()
                        <<", Price: "<<fruit.getPrice()<<std::endl;
                    }
                }
            }
            break;
        }
        case 4: {
            int threshold;
            std::cout<<"Enter threshold quantity: ";
            std::cin>>threshold;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Threshold must be an integer." << std::endl;
                break;
            }
            std::vector<Fruit> shortSupplyFruits = fruitController.getShortSupplyFruits(threshold);
            if (shortSupplyFruits.empty()) {
                std::cout << "No fruits in short supply." << std::endl;
            } else {
                std::cout << "Fruits in short supply:" << std::endl;
                for (const auto& fruit : shortSupplyFruits) {
                    std::cout << "Name: " << fruit.getName() << ", Quantity: " << fruit.getQuantity() << std::endl;
                }
            }
            break;
        }
        case 5: {
            std::vector<Fruit> sortedFruits = fruitController.getFruitsSortedByExpiry();
            if (sortedFruits.empty()) {
                std::cout << "No fruits available." << std::endl;
            } else {
                std::cout << "Fruits sorted by expiry date:" << std::endl;
                for (const auto& fruit : sortedFruits) {
                    std::cout << "Name: " << fruit.getName() << ", Expiry Date: " << fruit.getExpiryDate() << std::endl;
                }
            }
            break;
        }
        case 6: {
            std::cout<<"Exiting..."<<std::endl;
            exit(0);
            break;
        }
        default:
            std::cout<<"Invalid choice. Please try again."<<std::endl;
    }
}