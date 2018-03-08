#include "Customer.h"
#include <iostream>
#include <iomanip>

Customer::Customer() 	//privilege assigned statically
	id(0),
	name("No Name"),
	address("No Address"),
	tel("No Phone Number"),
	customerType("NOT SET")
{
}

Customer::Customer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel) //privilege assigned statically
	id(cstmrID),
	name(cstmrName),
	address(cstmrAddress),
	tel(cstmrTel),
	customerType("NOT SET")
{
}

Customer::Customer(const Customer & CopyCustomer) //privilege assigned statically
	id(CopyCustomer.getId()),
	name(CopyCustomer.getName()),
	address(CopyCustomer.getAddress()),
	tel(CopyCustomer.getTel()),
	customerType("NOT SET")
{
}

Customer::~Customer()
{
}

unsigned Customer::getId() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

string Customer::getAddress() const
{
	return address;
}

string Customer::getTel() const
{
	return tel;
}

string Customer::getCarsRented() const
{
	string carsRented = "";
	for (unsigned j = 0; j<carRented.size(); j++){
		carsRented +=" ";
		carsRented+=to_string(carRented.at(j));
		carsRented+=";";
	}

	return carsRented;
}

void Customer::setCarsRented(int carToAdd)
{
	carRented.push_back(carToAdd);
}
