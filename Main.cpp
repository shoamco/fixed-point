//
// Created by shoam on 10/10/19.
//
#include "TestPrice.h"

/*
 g++ -ansi -pedantic -Wall -Wconversion  Main.cpp Price.cpp Price.h TestPrice.cpp TestPrice.h -lgtest -lgtest_main -pthread -o test

 * */

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}