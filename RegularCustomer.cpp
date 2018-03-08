#include "RegularCustomer.h"
#include <iostream>
#include <iomanip>

//Privilege defined statically
RegularCustomer::RegularCustomer():																		//Defining Default Constructor for RegularCustomer
	Customer()
	customerType("Regular")
{
}

RegularCustomer::RegularCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel):	//Defining Constructor for RegularCustomer
	Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel),
	customerType("Regular")
{
}

RegularCustomer::RegularCustomer(const RegularCustomer & CopyRegularCustomer):							//Defining Copy Constructor for RegularCustomer
	Customer(CopyRegularCustomer),
	customerType(CopyRegularCustomer.customerType)
{
}

RegularCustomer::~RegularCustomer()																		//Defining Destructor for RegularCustomer
{
}

void RegularCustomer::setPrivilege(int usrPrivilege):													//Function to set Privilege
	privilege(usrPrivilege)
{
}

int RegularCustomer::getPrivilege()																		//Function to get Privilege
{
	return privilege;
}

string RegularCustomer::getCustomerType() const															//Function to get CustomerType
{
	return customerType;
}

void RegularCustomer::printInfo() const																	//Function to printInformation
{
	cout<< "Id: " <<getId()<<endl;
	cout<< "Name: " <<getName()<<endl;
	cout<< "CarsRented: " <<getCarsRented()<<endl;
	cout<< "Address: " <<getAddress()<<endl;
	cout<< "Tel: " <<getTel()<<endl;
	cout<< "CustomerType: " <<getCustomerType()<<endl;
	// <<"------"<<endl;
	// <<"------";endl
}
