#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RentalShop.h"
#include "MovieRecords.h"

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
        rt->printAll();

        cout << "\nSEARCH BY ID HERE\n";
        Item* i1 = rt->searchItemID("I007-2013"); // ID is unique -> return an Item
        cout << i1->toString();

        cout << "\nSEARCH BY ID HERE\n";
        Customer* c1 = rt->searchCusID("C003"); // ID is unique -> return a Customer
        cout << c1->toString();

        cout << "\nSEARCH BY Name HERE\n";
        vector<Customer*> c2 = rt->searchCusName("Linh Nguyen"); // Name can be the same -> return array
        rt->display(c2);

        cout << "\nSEARCH BY TITLE HERE\n";
        vector<Item*> i2 = rt->searchItemTitle("Halloween"); // Title can be the same -> return array
        rt->display(i2);

        cout << "\nDisplay Customer by Level\n";
        rt->displayGroup("Regular"); // Guest, Regular, VIP 

        rt->deletePointerVector();
        // initialize seven variables to store

    }
    fileinItem.close();
    fileinCustomer.close();
    return 0;
}