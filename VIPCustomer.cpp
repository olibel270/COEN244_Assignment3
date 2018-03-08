#include "VIPCustomer.h"
#include <iostream>
#include <iomanip>

//privilege defined statically
VIPCustomer::VIPCustomer():																			//Defining Default Constructor
	Customer(),
	customerType("VIP")
{
}

VIPCustomer::VIPCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel):		//Defining Constructor
	Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel),
	customerType("VIP")
{
}

VIPCustomer::VIPCustomer(const VIPCustomer & CopyVIPCustomer):										//Defining Copy Constructor
	Customer(CopyVIPCustomer),
	customerType("VIP")
{
}

VIPCustomer::~VIPCustomer()																			//Defining Destructor
{
}

void VIPCustomer::setPrivilege(int usrPrivilege):													//Function to set Privilege
	customerType("VIP")
{
}

int VIPCustomer::getPrivilege()																		//Function to get Privilege
{
	return privilege;
}

string VIPCustomer::getCustomerType() const															//Function to get CustomerType
{
	return customerType;
}

void VIPCustomer::printInfo() const																	//Function to printInformation
{
	cout << "Id: " << getId()<< endl;
	cout << "Name: " << getName()<< endl;
	cout << "CarsRented: " << getCarsRented()<< endl;
	cout << "Address: " << getAddress()<< endl;
	cout << "Tel: " << getTel()<< endl;
	cout << "CustomerType: " << getCustomerType()<< endl;
}
