#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RentalShop.h"
#include "MovieRecords.h"
#include "Interface.h"

using namespace std;

int main()
{
    ifstream fileinItem;
    ifstream fileinCustomer;
    fileinCustomer.open("nhap.txt");
    fileinItem.open("items.txt");
    if (!fileinItem || !fileinCustomer) {
        cout << "CANNOT open the file";
    }
    else {
        RentalShop* rt = new RentalShop(fileinItem, fileinCustomer);
        Interface display;
        bool exit = false;
        int choice = 0;
        do {
            display.menu();
            choice = display.takeChoice(11);
            if (choice == 11) {
                exit = true;
            }
            else {
                display.option(choice, &rt);
            }
        } while (!exit);

        rt->deletePointerVector();
        // initialize seven variables to store
    }
    fileinItem.close();
    fileinCustomer.close();
    return 0;
}