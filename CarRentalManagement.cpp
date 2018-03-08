#include "CarRentalManagement.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "VIPCustomer.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//------------------Constructors and Destructors---------
CarRentalManagement::CarRentalManagement(){
}

CarRentalManagement::~CarRentalManagement(){
}

//=======================================================

//-------------------Car Management----------------------
void CarRentalManagement::addCar(Car carToAdd){
	inventory.push_back(carToAdd);
}

void CarRentalManagement::removeCar(int idOfCarToRemove){
	for (unsigned i=0;i<inventory.size();i++)		//Search the inventory for the car with given ID
		if(inventory.at(i).getID()==idOfCarToRemove)	//If IDs match
			inventory.erase(inventory.begin()+i);		//Erase Entry from inventory
}

void CarRentalManagement::printInventory(){
	cout<<"**************************************"<<endl
		<<"|              INVENTORY             |"<<endl
		<<"**************************************"<<endl;
	cout<<setw(6)<<"Car ID"<<setw(15)<<"Car Type"<<setw(15)<<"Availability"<<endl;
	for(unsigned int i = 0; i<inventory.size(); i++){
		cout<<setw(6)<<inventory.at(i).getID()
			<<setw(15)<<inventory.at(i).getCarType();
		if (inventory.at(i).getAvailability())
			cout<<setw(15)<<"Available"<<endl;
		else
			cout<<setw(15)<<"Unavailable"<<endl;
	}
	cout<<endl;
}

//=======================================================

//-------------------Customer Management-----------------
void CarRentalManagement::addCustomer(RegularCustomer& customerToAdd){
	Customer* customerPtr = &customerToAdd;
	customerList.push_back(customerPtr);
}

void CarRentalManagement::addCustomer(CorporateCustomer& customerToAdd){
	Customer* customerPtr = &customerToAdd;
	customerList.push_back(customerPtr);
}

void CarRentalManagement::addCustomer(VIPCustomer& customerToAdd){
	Customer* customerPtr = &customerToAdd;
	customerList.push_back(customerPtr);
}

void CarRentalManagement::removeCustomer(unsigned idToRemove){
	for(unsigned int i = 0; i<customerList.size(); i++)
		if(customerList.at(i)->getId()==idToRemove)
			customerList.erase(customerList.begin()+i);
}

void CarRentalManagement::printCustomer(unsigned customerId){
	cout<<"*******************************************************"<<endl
		<<"|                     Customer Info                   |"<<endl
		<<"*******************************************************"<<endl;
	unsigned positionInList = 999;

	for(unsigned i = 0; i<customerList.size(); i++)
		if(customerList.at(i)->getId() == customerId){
			positionInList = i;
			break;
		}
	cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(30)<<"Car Rented ID(s)"<<setw(30)<<"Address"<<setw(20)<<"Phone Number"<<setw(16)<<"Customer Type"
		<<setw(20)<<"Company Name"<<setw(30)<<"Company Address"<<endl;
	customerList.at(positionInList)->printInfo();
	cout<<endl<<endl;
}

void CarRentalManagement::printCustomerList(){
	cout<<"**************************************************************************************************************************************************"<<endl
		<<"|                                                                    Customer List                                                               |"<<endl
		<<"**************************************************************************************************************************************************"<<endl;
	cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(30)<<"Address"<<setw(20)<<"Phone Number"<<setw(16)<<"Customer Type"
			<<setw(20)<<"Company Name"<<setw(30)<<"Company Address"<<endl;
	for(unsigned int i = 0; i<customerList.size(); i++){
		customerList.at(i)->printInfo();
		cout<<endl;
	}
	cout<<endl;
}

//=======================================================

//--------------------Rental Management------------------
void CarRentalManagement::rentCar(int customerID, string carType){	//When a customer desires a certain car type, one is assigned to him

	//Retrieve Customer
	unsigned customerListPosition = 999999;
	for (unsigned i = 0; i<customerList.size(); i++)
		if((int)customerList.at(i)->getId()==customerID){
			customerListPosition = i;
			break;
		}

	//Retrieve available car of desired type
	unsigned inventoryPosition = 999999;
	for (unsigned i = 0; i<inventory.size(); i++)
		if(inventory.at(i).getCarType()==carType && inventory.at(i).getAvailability()==true){
			inventoryPosition = i;
			break;
		}
	if (inventoryPosition == 999999){
		cout<<"No available car of desired type. Try another type."<<endl;
		return;
	}

	//Assign Car to Customer
	customerList.at(customerListPosition)->setCarsRented(inventory.at(inventoryPosition).getID());
	inventory.at(inventoryPosition).setAvailability(false);
}

void CarRentalManagement::returnCar(int customerID){
	//Retrieve Customer
	int carToRemoveId;

	for (unsigned i = 0; i<customerList.size(); i++)		//Select Right customer from customerList
		if((int)customerList.at(i)->getId()==customerID){
			if(customerList.at(i)->carRented.size()==1)		//If customer has only rented 1 car, automatically return the car
				customerList.at(i)->carRented.pop_back();
			}
			else{											//If More than one car, define car to return
				cout<<"More than one car rented. Which car should be returned?"<<endl;
				cout<<setw(6)<<"Car ID"<<setw(15)<<"Car Type"<<endl;
				for (unsigned j=0; j<customerList.at(i)->carRented.size(); j++){	//For each car rented by customer
					cout<<setw(6)<<customerList.at(i)->carRented.at(j);		//cout ID
					for (unsigned k=0;k<inventory.size();k++)		//Search the inventory for the car with given ID
						if(inventory.at(k).getID()==customerList.at(i)->carRented.at(j))	//If IDs match
							cout<<setw(15)<<inventory.at(k).getCarType()<<endl;		//cout Car Type
				}
				cout<<"Enter Car ID: ";
				cin>>carToRemoveId;

				for (unsigned j=0;j<inventory.size();j++)		//Search the inventory for the car with given ID
					if(inventory.at(j).getID() == carToRemoveId)
						inventory.at(j).setAvailability(true);

				for (unsigned j=0; j<customerList.at(i)->carRented.size(); j++)	//Search the rented Cars for car with given ID
					if (customerList.at(i)->carRented.at(j) == carToRemoveId)
						customerList.at(i)->carRented.erase(customerList.at(i)->carRented.begin()+j);	//Erase Entry
			}
}


void CarRentalManagement::returnCar(int customerID, int carToRemoveId){
	//Retrieve Customer
	for (unsigned i = 0; i<customerList.size(); i++)		//Select Right customer from customerList
		if ((int)customerList.at(i)->getId() == customerID)		//If customer ID matches
			for (unsigned j=0; j<customerList.at(i)->carRented.size(); j++)	//For each car rented by customer
				if(customerList.at(i)->carRented.at(j) == carToRemoveId)	//If IDs match
					customerList.at(i)->carRented.erase(customerList.at(i)->carRented.begin()+j);	//Erase Entry

	//Set car to available
	for (unsigned i=0;i<inventory.size();i++)		//Search the inventory for the car with given ID
		if(inventory.at(i).getID() == carToRemoveId)
			inventory.at(i).setAvailability(true);
}

//================================================================================================

//----------------------------------Privileges Management-----------------------------------------

int CarRentalManagement::getPrivileges(unsigned customerId){
	string type = "";

	for (unsigned i=0; i<customerList.size(); i++)		//Select Right customer from customerList
		if(customerList.at(i)->getId() == customerId)
			type = customerList.at(i)->getCustomerType();
	if(type == "Regular") return RegularCustomer::getPrivilege();
	if(type == "Corporate") return CorporateCustomer::getPrivilege();
	if(type == "VIP") return VIPCustomer::getPrivilege();

	return 0;
}

void CarRentalManagement::changePrivileges(int newRegularPrivilege, int newCorporatePrivilege, int newVIPPrivilege){
	RegularCustomer::setPrivilege(newRegularPrivilege);
	CorporateCustomer::setPrivilege(newCorporatePrivilege);
	VIPCustomer::setPrivilege(newVIPPrivilege);
}
