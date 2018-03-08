#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include "Car.h"
using namespace std;

class Customer
{
	friend class CarRentalManagement;						//Making CarRentalManagement a friend so it can access private memebers

public:
	Customer();
	Customer(int, string, string, string);
	Customer(const Customer&);
	virtual ~Customer();

	unsigned getId() const;									//Declaring getId | Type: unsigned
	string getName() const;									//Declaring getName | Type: string
	string getAddress() const;								//Declaring getAddress | Type: string
	string getTel() const;									//Declaring getTel | Type: string
	string getCarsRented() const;							//Declaring getCarsRented | Type: string
	void setCarsRented(int);								//Declaring setCarsRented | Type: void
	virtual string getCustomerType() const = 0;				//Declaring virtual function getCustomerType | Type: virtual string
	virtual void printInfo() const = 0; 					//printInfo() prints the values of the data members (for use by printCustomerList() of CarRentalManagement).


protected:
	unsigned id;											//Declaring id | Type: unsigned
	string name;											//Declaring name | Type: string
	string address;											//Declaring address | Type: string
	string tel;												//Declaring tel | Type: string
	vector <int> carRented;									//carRented contains the cars rented by the customer. The default "No car" is defined as -1
	string customerType;									//Type: Regular, Corporate, or VIP
};

#endif