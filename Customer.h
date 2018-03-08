#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <vector>
#include "Car.h"
using namespace std;

class Customer{
	friend class CarRentalManagement;
public:
	Customer();
	Customer(int, string, string, string);
	Customer(const Customer&);
	virtual ~Customer();

	unsigned getId() const;
	string getName() const;
	string getAddress() const;
	string getTel() const;
	string getCarsRented() const;
	void setCarsRented(int);
	virtual string getCustomerType() const = 0;
	virtual void printInfo() const = 0; 		//printInfo() prints the values of the data members (for use by printCustomerList() of CarRentalManagement).


protected:
	unsigned id;
	string name;
	string address;
	string tel;
	vector <int> carRented;		//carRented contains the cars rented by the customer. The default "No car" is defined as -1
	string customerType;	//Regular, Corporate, Or VIP
};

#endif
