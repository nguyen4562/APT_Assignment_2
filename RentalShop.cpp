#include "RentalShop.h"
/*getter*/

vector<Customer*> RentalShop::getCustomers() {
    return this->customers;
}

vector<Item*> RentalShop::getItems() {
    return this->items;
}
/*setter*/
void RentalShop::setCustomers(vector<Customer*> customers) {
    this->customers = customers;
}
void RentalShop::setItems(vector<Item*> items) {
    this->items = items;
}

/*Constructor*/
RentalShop::RentalShop(ifstream& fileinItem, ifstream& fileinCustomer) {
    Validation* vl = new Validation(fileinItem, fileinCustomer);
    vector<Item*> items;
    vl->readFileItem(fileinItem, items);
    this->items = items;

    vector<Customer*> customers;
    vl->readFileCustomer(fileinCustomer, customers);
    this->customers = customers;
}
RentalShop::~RentalShop() {

}

/*Start Search*/
vector<Item*> RentalShop::searchNoCopy() {
    vector<Item*> result;
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i]->getNumOfCopy() == 0) {
            result.push_back(this->items[i]);
        }
    }
    return result;
}

vector<Item*> RentalShop::searchItemTitle(string title) {
    vector<Item*> result;
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i]->getTitle() == title) {
            result.push_back(this->items[i]);
        }
    }
    return result;
}

Item* RentalShop::searchItemID(string ID) {
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i]->getID() == ID) {
            return this->items[i];
        }
    }
    return NULL;
}

Customer* RentalShop::searchCusID(string ID) {
    int size = this->customers.size();
    for (int i = 0; i < size; i++) {
        if (this->customers[i]->getID() == ID) {
            return this->customers[i];
        }
    }
    return NULL;
}

vector<Customer*> RentalShop::searchCusName(string name) {
    vector<Customer*> result;
    int size = this->customers.size();
    for (int i = 0; i < size; i++) {
        if (this->customers[i]->getName() == name) {
            result.push_back(this->customers[i]);
        }
    }
    return result;
}
/*End Search*/

Customer* RentalShop::promoteCusID(string input, int type, int typeSearch) {
    int size = this->customers.size();
    string check;
    for (int i = 0; i < size; i++) {
        if (typeSearch == 0) {
            check = this->customers[i]->getID();
        }
        else if (typeSearch == 1) {
            check = this->customers[i]->getName();
        }
        if (check == input) {
            if (type == 0 && this->customers[i]->getcustomerType() == "Guest") {
                cout << "Successfully promote " << this->customers[i]->getName() << " to Regular member\n" << endl;
                this->customers[i]->setcustomerType("Regular");
                return this->customers[i];
            }
            else if (type == 0 && this->customers[i]->getcustomerType() == "Regular") {
                cout << "This is already Regular member\n" << endl;
                return this->customers[i];
            }
            else if (type == 0 && this->customers[i]->getcustomerType() == "VIP") {
                cout << "This is already VIP member can not promote to Regular\n" << endl;
                return this->customers[i];
            }
            if (type == 1 && this->customers[i]->getcustomerType() == "Regular") {
                cout << "Successfully promote " << this->customers[i]->getName() << " to VIP member\n" << endl;
                this->customers[i]->setcustomerType("VIP");
                return this->customers[i];
            }
            else if (type == 1 && this->customers[i]->getcustomerType() == "VIP") {
                cout << "This is already VIP member\n" << endl;
                return this->customers[i];
            }
            else if (type == 1 && this->customers[i]->getcustomerType() == "Guest") {
                cout << "This is Guest member can not promote to VIP member\n" << endl;
                return this->customers[i];
            }
        }
    }
    cout << "Your input does not existing in the database\n" << endl;
    return NULL;
}

/*delete pointer vector*/
void RentalShop::deletePointerVector() {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
    items.clear();
    for (int i = 0; i < customers.size(); i++) {
        delete customers[i];
    }
    customers.clear();
}

/*Start Display*/
void RentalShop::displayNoCopy() {
    int size = this->items.size();
    for (int i = 0; i < size; i++) {
        if (this->items[i]->getNumOfCopy() == 0) {
            cout << this->items[i]->toString() << '\n';
        }
    }
}

void RentalShop::display(vector<Item*> obj) {
    int size = obj.size();
    for (int i = 0; i < size; i++) {
        cout << obj[i]->toString() << '\n';
    }
}

void RentalShop::display(vector<Customer*> obj) {
    int size = obj.size();
    for (int i = 0; i < size; i++) {
        cout << obj[i]->toString() << '\n';
    }
}


void RentalShop::displayGroup(string groupType) {
    int size = this->customers.size();
    for (int i = 0; i < size; i++) {
        if (this->customers[i]->getcustomerType() == groupType) {
            cout << this->customers[i]->toString() << '\n';
        }
    }
}

void RentalShop::printAll() {
    for (int i = 0; i < customers.size(); i++) {
        cout << customers[i]->toString() << endl;
    }

    for (int i = 0; i < items.size(); i++) {
        cout << items[i]->toString() << endl;
    }
}

void RentalShop::printAllCustomerSortedName(int type) {
    int miniPos;
    if (type == 0) {
        for (unsigned int i = 0; i < customers.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < customers.size(); j++)
            {
                if (customers[j]->getName() < customers[miniPos]->getName()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Customer* temp = customers[miniPos];
            customers[miniPos] = customers[i];
            customers[i] = temp;
        }
    }
    if (type == 1) {
        for (unsigned int i = 0; i < customers.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < customers.size(); j++)
            {
                if (customers[j]->getName() > customers[miniPos]->getName()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Customer* temp = customers[miniPos];
            customers[miniPos] = customers[i];
            customers[i] = temp;
        }
    }

    for (unsigned int i = 0; i < customers.size(); i++) {
        cout << customers[i]->toString() << endl;
    }
    
}

void RentalShop::printAllCustomerSortedID(int type) {
    int miniPos;
    if (type == 0) {
        for (unsigned int i = 0; i < customers.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < customers.size(); j++)
            {
                if (customers[j]->getID() < customers[miniPos]->getID()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Customer* temp = customers[miniPos];
            customers[miniPos] = customers[i];
            customers[i] = temp;
        }
    }
    if (type == 1) {
        for (unsigned int i = 0; i < customers.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < customers.size(); j++)
            {
                if (customers[j]->getID() > customers[miniPos]->getID()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Customer* temp = customers[miniPos];
            customers[miniPos] = customers[i];
            customers[i] = temp;
        }
    }

    for (unsigned int i = 0; i < customers.size(); i++) {
        cout << customers[i]->toString() << endl;
    }

}

void RentalShop::printAllItemSortedName(int type) {
    int miniPos;
    if (type == 0) {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < items.size(); j++)
            {
                if (items[j]->getTitle() < items[miniPos]->getTitle()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Item* temp = items[miniPos];
            items[miniPos] = items[i];
            items[i] = temp;
        }
    }
    if (type == 1) {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < items.size(); j++)
            {
                if (items[j]->getTitle() > items[miniPos]->getTitle()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Item* temp = items[miniPos];
            items[miniPos] = items[i];
            items[i] = temp;
        }
    }

    for (unsigned int i = 0; i < items.size(); i++) {
        cout << items[i]->toString() << endl;
    }

}

void RentalShop::printAllItemSortedID(int type) {
    int miniPos;
    if (type == 0) {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < items.size(); j++)
            {
                if (items[j]->getID() < items[miniPos]->getID()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Item* temp = items[miniPos];
            items[miniPos] = items[i];
            items[i] = temp;
        }
    }
    if (type == 1) {
        for (unsigned int i = 0; i < items.size(); i++)
        {
            miniPos = i;
            for (unsigned int j = i + 1; j < items.size(); j++)
            {
                if (items[j]->getID() > items[miniPos]->getID()) //Change was here!
                {
                    miniPos = j;
                }
            }

            Item* temp = items[miniPos];
            items[miniPos] = items[i];
            items[i] = temp;
        }
    }

    for (unsigned int i = 0; i < items.size(); i++) {
        cout << items[i]->toString() << endl;
    }

}
/*End Display*/

