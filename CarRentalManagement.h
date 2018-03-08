#include "Car.h"
#include "Customer.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "VIPCustomer.h"
#include <vector>

using namespace std;

class CarRentalManagement{

public:
	CarRentalManagement();
	~CarRentalManagement();

	void addCar(Car);
	void removeCar(int);
	void printInventory();	//To help keep track of cars in inventory and their status

	void addCustomer(RegularCustomer&);
	void addCustomer(CorporateCustomer&);
	void addCustomer(VIPCustomer&);
	void removeCustomer(unsigned);
	void printCustomer(unsigned);		//To help keep track of a single customer
	void printCustomerList();	//To help keep track of customers and their status

	void rentCar(int, string);
	void returnCar(int);
	void returnCar(int, int);

	int getPrivileges(unsigned);
	void changePrivileges(int, int, int);

	bool isCarRented(Car);
	bool hasCustomerRented(Customer*);
	string customerType(Customer*);

	void carTypesRentedByCustomerOfCompany(Customer*, string);


private:
	vector <Car> inventory;
	vector <Customer*> customerList;

//NECESSARY????
	void findCustomer(Customer*) const;
	void checkCarPresentInInventory(Car) const;
};
