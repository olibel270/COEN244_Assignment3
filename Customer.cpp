#include "Customer.h"
#include <iostream>
#include <iomanip>

Customer::Customer() 	//privilege assigned statically Function to ()
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

unsigned Customer::getId() const							// Function to get Id
{
	return id;
}

string Customer::getName() const							// Function to get Name
{
	return name;
}

string Customer::getAddress() const							// Function to get Address
{
	return address;
}

string Customer::getTel() const								// Function to get Tel
{
	return tel;
}

string Customer::getCarsRented() const						// Function to get CarsRented
{
	string carsRented = "";

	for (unsigned j = 0; j < carRented.size(); j++)
	{
		carsRented += " " + to_string( carRented[j] ) + ';';
	}

	return carsRented;
}

void Customer::setCarsRented(int carToAdd)					// Function to set CarsRented
{
	carRented.push_back(carToAdd);
}
