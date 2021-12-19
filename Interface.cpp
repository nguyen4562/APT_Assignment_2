#include "Interface.h"

Interface::Interface() {
    this->menuChoice = 0;
}

void Interface::menu() {
    cout << "Welcome to Genie’s video store\n";
    cout << "Enter an option below\n";
    cout << "1.  Add a new item, update or delete an existing item\n";
    cout << "2.  Add new customer or update an existing customer\n";
    cout << "3.  Promote an existing customer\n";
    cout << "4.  Rent an item\n";
    cout << "5.  Return an item\n";
    cout << "6.  Display all items\n";
    cout << "7.  Display out-of-stock items\n";
    cout << "8.  Display all customers\n";
    cout << "9.  Display group of customers\n";
    cout << "10. Search items or customers\n";
    cout << "11. Exit\n";
    cout << "Your choice [1 - 11]: ";
}

void Interface::menu1() {
    cout << "1. Add item\n";
    cout << "2. Update item\n";
    cout << "3. Delete item\n";
    cout << "Your choice [1 - 3]: ";
    int subChoice = this->takeChoice(3);
}

void Interface::menu2() {
    cout << "1. Add customer\n";
    cout << "2. Update customer\n";
    cout << "Your choice [1 - 2]: ";
    int subChoice = this->takeChoice(2);
}

void Interface::menu3() {
    cout << "1. Promote custormer by ID\n";
    cout << "2. Promote custormer by Name\n";
    cout << "Your choice [1 - 2]: ";
    int subChoice = this->takeChoice(2);
    if (subChoice == 1) {
        cout << '\n';
        cout << "1. Promote customer from Guest to Regular\n";
        cout << "2. Promote customer from Regular to VIP\n";
        cout << "Your choice [1 - 2]: ";
        int subsubChoice = this->takeChoice(2);
        cout << '\n';
        string word;
        if (subsubChoice == 1) {
            while (true)
            {
                cout << "ID: ";
                getline(cin, word);
                cout << '\n';
                Customer* i1 = this->rs->promoteCusID(word, 0, 0);
                if (i1 != NULL) {
                    cout << i1->toString();
                    break;
                }
            }
        }
        else if (subsubChoice == 2) {
            while (true)
            {
                cout << "ID: ";
                getline(cin, word);
                cout << '\n';
                Customer* i1 = this->rs->promoteCusID(word, 1, 0);
                if (i1 != NULL) {
                    cout << i1->toString();
                    break;
                } 
            }
        }
    }
    if (subChoice == 2) {
        cout << '\n';
        cout << "1. Promote customer from Guest to Regular\n";
        cout << "2. Promote customer from Regular to VIP\n";
        cout << "Your choice [1 - 2]: ";
        int subsubChoice = this->takeChoice(2);
        cout << '\n';
        string word;
        if (subsubChoice == 1) {
            while (true)
            {
                cout << "Name: ";
                getline(cin, word);
                cout << '\n';
                Customer* i1 = this->rs->promoteCusID(word, 0, 1);
                if (i1 != NULL) {
                    cout << i1->toString();
                    break;
                }
            }
        }
        else if (subsubChoice == 2) {
            while (true)
            {
                cout << "Name: ";
                getline(cin, word);
                cout << '\n';
                Customer* i1 = this->rs->promoteCusID(word, 1, 1);
                if (i1 != NULL) {
                    cout << i1->toString();
                    break;
                }
            }
        }
    }
}

void Interface::menu4() {
    cout << "Not designed yet";
}

void Interface::menu5() {
    cout << "Not designed yet";
}

void Interface::menu6() {
    cout << "1. Sorted by Title\n";
    cout << "2. Sorted by ID\n";
    cout << "Your choice [1 - 2]: ";
    int subChoice = this->takeChoice(2);
    cout << '\n';
    cout << "1. Sorted assending\n";
    cout << "2. Sorted desending\n";
    cout << "Your choice [1 - 2]: ";
    if (subChoice == 1) {
        cout << '\n';
        int subsubChoice = this->takeChoice(2);
        if (subsubChoice == 1) {
            this->rs->printAllItemSortedName(0);
        }
        if (subsubChoice == 2) {
            this->rs->printAllItemSortedName(1);
        }
    }
    if (subChoice == 2) {
        cout << '\n';
        int subsubChoice = this->takeChoice(2);
        if (subsubChoice == 1) {
            this->rs->printAllItemSortedID(0);
        }
        if (subsubChoice == 2) {
            this->rs->printAllItemSortedID(1);
        }
    }
}

void Interface::menu7() {
    this->rs->displayNoCopy();
}

void Interface::menu8() {
    cout << "1. Sorted by name\n";
    cout << "2. Sorted by ID\n";
    cout << "Your choice [1 - 2]: ";
    int subChoice = this->takeChoice(2);
    cout << '\n';
    cout << "1. Sorted assending\n";
    cout << "2. Sorted desending\n";
    cout << "Your choice [1 - 2]: ";
    if (subChoice == 1) {
        cout << '\n';
        int subsubChoice = this->takeChoice(2);
        if (subsubChoice == 1) {
            this->rs->printAllCustomerSortedName(0);
        }
        if (subsubChoice == 2) {
            this->rs->printAllCustomerSortedName(1);
        }
    }
    if (subChoice == 2) {
        cout << '\n';
        int subsubChoice = this->takeChoice(2);
        if (subsubChoice == 1) {
            this->rs->printAllCustomerSortedID(0);
        }
        if (subsubChoice == 2) {
            this->rs->printAllCustomerSortedID(1);
        }
    }
}

void Interface::menu9() {
    cout << "1. Guest\n";
    cout << "2. Regular\n";
    cout << "3. VIP\n";
    cout << "Your choice [1 - 3]: ";
    int subChoice = this->takeChoice(3);
    cout << '\n';

    const char* group[3] = { "Guest", "Regular", "VIP" };
    this->rs->displayGroup(group[subChoice - 1]);
}

void Interface::menu10() {
    cout << "1. Item\n";
    cout << "2. Customer\n";
    cout << "Your choice [1 - 2]: ";
    int subChoice = this->takeChoice(2);

    if (subChoice == 1) {
        cout << '\n';
        cout << "1. ID\n";
        cout << "2. Title\n";
        cout << "Your choice [1 - 2]: ";
        subChoice = this->takeChoice(2);

        this->menu10_1(subChoice);
    }
    else if (subChoice == 2) {
        cout << '\n';
        cout << "1. ID\n";
        cout << "2. Name\n";
        cout << "Your choice [1 - 2]: ";
        subChoice = this->takeChoice(2);

        this->menu10_2(subChoice);
    }
}

void Interface::menu10_1(int subChoice) {
    cout << '\n';
    string word;
    if (subChoice == 1) {
        Item* i1;
        while (true) {
            cout << "ID: ";
            getline(cin, word);
            cout << '\n';
            i1 = this->rs->searchItemID(word);
            if (i1 != NULL) {
                break;
            }
        }
        cout << i1->toString();
    }
    else if (subChoice == 2) {
        vector<Item*> i1;
        while (true) {
            cout << "Title: ";
            getline(cin, word);
            cout << '\n';
            i1 = this->rs->searchItemTitle(word);
            if (i1.size() != 0) {
                break;
            }
        }
        this->rs->display(i1);
    }
}

void Interface::menu10_2(int subChoice) {
    cout << '\n';
    string word;
    if (subChoice == 1) {
        Customer* c1;
        while (true) {
            cout << "ID: ";
            getline(cin, word);
            cout << '\n';
            c1 = this->rs->searchCusID(word);
            if (c1 != NULL) {
                break;
            }
        }
        cout << c1->toString();
    }
    else if (subChoice == 2) {
        vector<Customer*> c1;
        while (true) {
            cout << "Name: ";
            getline(cin, word);
            cout << '\n';
            c1 = this->rs->searchCusName(word);
            if (c1.size() != 0) {
                break;
            }
        }
        this->rs->display(c1);
    }
}

void Interface::option(int menuChoice, RentalShop** rs) {
    this->rs = *rs;
    this->menuChoice = menuChoice;
    cout << '\n';

    switch (menuChoice)
    {
    case 1:
        this->menu1();
        break;
    case 2:
        this->menu2();
        break;
    case 3:
        this->menu3();
        break;
    case 4:
        this->menu4();
        break;
    case 5:
        this->menu5();
        break;
    case 6:
        this->menu6();
        break;
    case 7:
        this->menu7();
        break;
    case 8:
        this->menu8();
        break;
    case 9:
        this->menu9();
        break;
    case 10:
        this->menu10();
        break;
    default:
        break;
    }
    cout << '\n';
}

int Interface::takeChoice(int limit) {
    /*
    Choices are between 1 and limit [1 - limit]
    @param limit: the maximum choice for the input (e.g limit = 3 -> 3 choices)
    */
    while (true) {
        string input;
        int choice;
        getline(cin, input);

        while (cin.fail() || cin.eof() || input.find_first_not_of("0123456789") != string::npos || input.size() == 0) {
            cout << "Require number in range [1 - " << limit << "]: ";
            if (input.find_first_not_of("0123456789") == string::npos || input.size() == 0) {
                cin.clear();
                //cin.ignore(256, '\n');
                //cout << "REACH" << '\n';
            }
            getline(cin, input);
        }

        string::size_type st;
        choice = stoi(input, &st);
        if (choice >= 1 && choice <= limit) {
            return choice;
        }
        else {
            cout << "Number must be in range [1 - " << limit << "]: ";
        }
    }
}