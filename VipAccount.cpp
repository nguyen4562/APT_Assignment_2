#include "VipAccount.h"
VipAccount::VipAccount() {

}
VipAccount::VipAccount(Customer *cus) {
	this->id = cus->getID();
	this->address = cus->getAdress();
	this->name = cus->getName();
	this->phone = cus->getPhone();
	this->numOfRentals = cus->getnumOfRentals();
	this->customerType = cus->getcustomerType();
	this->listOfRentals = cus->getListOfRentals();
}
VipAccount::~VipAccount() {

}
string VipAccount::toString() {
	return Customer::toString() + "\nVipAccount object!";
}