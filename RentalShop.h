#pragma once
#include "Customer.h"
#include "Item.h"
#include <vector>
#include<iostream>
#include<string>
#include<fstream>
#include"MovieRecords.h"
#include"DVDs.h"
#include"Games.h"
#include "Customer.h"
#include "VipAccount.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
class RentalShop
{
private:
	//vector<Customer*> customers;
	vector<Item*> items;
	vector<Customer*> customers;
	/*Read one line of the Items.txt file to check which rental type the line is*/
	static void readOneItemInItemFile(ifstream& filein, Item* item, string& genre);
	static int checkTypeItem(Item* item);
	static void readFileItem(ifstream& filein, vector<Item*>& items);
	static void readOneCustomerInCustomerFile(ifstream& filein, Customer* customer);
	static void readFileCustomer(ifstream& filein, vector<Customer*>& customers);
public:
	
	RentalShop(ifstream& filein, ifstream& fileinCustomer);
	~RentalShop();
	/*getter*/
	vector<Customer*> getCustomers();
	vector<Item*> getItems();
	/*setter*/
	void setCustomers(vector<Customer*> customers);
	void setItems(vector<Item*> items);

	/*Search*/
	Item* searchItemID(string ID);
	Customer* searchCusID(string ID);
	vector<Item*> searchItemTitle(string title);
	vector<Customer*> searchCusName(string name);
	vector<Item*> searchNoCopy();

	/*Display*/
	void displayNoCopy();
	void display(vector<Item*> obj);
	void display(vector<Customer*> obj);
	void displayGroup(string groupType);
	void printAll();

	/*delete vector pointer*/
	void deletePointerVector();
	
	
};

