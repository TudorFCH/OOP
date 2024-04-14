#include "FruitUI.h"
#include "Tests.h"

int main(){
    FruitUI fruitUI;
    testAll();

    while(true){
        fruitUI.displayMenu();
        fruitUI.processInput();
    }
    return 0;
}