#pragma once

#include "RentalShop.h"
#include <iostream>
#include <string>

using namespace std;

class Interface {
private:
    int menuChoice;
    RentalShop* rs;
public:
    Interface();

    void menu();
    void menu1();
    void menu2();
    void menu3();
    void menu4();
    void menu5();
    void menu6();
    void menu7();
    void menu8();
    void menu9();
    void menu10();

    void option(int choice, RentalShop** rs);
    int takeChoice(int limit);
};