#pragma once
#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class VipAccount : public Customer
{
public:
	VipAccount();
	VipAccount(Customer* cus);
	~VipAccount();
	string toString();

};

