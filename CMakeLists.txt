cmake_minimum_required(VERSION 3.27)
project(L4_Popa_Tudor)

set(CMAKE_CXX_STANDARD 17)

add_executable(L4_Popa_Tudor
        Fruit.h
        FruitRepo.h
        FruitController.h
        FruitController.cpp
        FruitUI.h
        FruitUI.cpp
        Shop.cpp
        FruitRepo.cpp
        Fruit.cpp
        Tests.cpp)
