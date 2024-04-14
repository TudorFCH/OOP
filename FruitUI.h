#ifndef L4_POPA_TUDOR_FRUITUI_H
#define L4_POPA_TUDOR_FRUITUI_H

#include <iostream>
#include "FruitController.h"

class FruitUI{
private:
    FruitController fruitController;

public:
    FruitUI();

    void displayMenu();
    void processInput();
};

#endif //L4_POPA_TUDOR_FRUITUI_H
