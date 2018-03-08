#include "Customer.h"
#include "RegularCustomer.h"
#include "CorporateCustomer.h"
#include "VIPCustomer.h"
#include "CarRentalManagement.h"
#include "Car.h"

#include <iostream>
#include <array>

using namespace std;

int main()
{
//First create a rental management object named COEN244Cars

	CarRentalManagement COEN244Cars;

//Let's quickly create 12 cars, 7 regular cars, and 5 luxury,and add them to the inventory
	for (unsigned i = 0;i<12;i++)
	{
		if (i<7)
			COEN244Cars.addCar(Car(i+1,"Regular", true));
		else
			COEN244Cars.addCar(Car(i+1,"Luxury", true));
	}

	//Verifying the fleet is right
	COEN244Cars.printInventory();

	//Removing a car from the inventory
	COEN244Cars.removeCar(5);

	//Verifying the fleet is right
	COEN244Cars.printInventory();

//Create 12 customers
		RegularCustomer r1(1, "Alan Alamos", "1 Ashton Street","111-111-1111");
		RegularCustomer r2(2, "Britney Brown", "2 Bell Street","222-222-2222");
		RegularCustomer r3(3, "Courtney Court", "3 Call Street","333-333-3333");
		RegularCustomer r4(4, "Denis Dickson", "4 Dalton Street","444-444-4444");

		CorporateCustomer c1(5, "Eric Erickson", "5 Elementary Street","555-555-5555","Electrical Corp", "5 Electrical Avenue");
		CorporateCustomer c2(6, "Fabrizia Faillon", "6 Fournier Street","666-666-6666","Flip Fabrik","6 Flip Avenue");
		CorporateCustomer c3(7, "Georgia Golem", "7 Gall Street","777-777-7777","Georgia Tech","7 Georgia Avenue");
		CorporateCustomer c4(8, "Henry Holiday", "8 Holland Street","888-888-8888","Hollow Inc.","8 Hollow Avenue");

		VIPCustomer v1(9, "Indiana Illinois", "9 Iroquois Street","999-999-9999");
		VIPCustomer v2(10, "Janet Jackson", "10 Jolicoeur Street","101-010-1010");
		VIPCustomer v3(11, "Kid Koala", "11 Kangaroo Street","110-110-1101");
		VIPCustomer v4(12, "Leo Leonard", "12 Latvia Street","121-212-1212");

//Add Customers to customer List
	COEN244Cars.addCustomer(r1);
	COEN244Cars.addCustomer(r2);
	COEN244Cars.addCustomer(r3);
	COEN244Cars.addCustomer(r4);
	COEN244Cars.addCustomer(c1);
	COEN244Cars.addCustomer(c2);
	COEN244Cars.addCustomer(c3);
	COEN244Cars.addCustomer(c4);
	COEN244Cars.addCustomer(v1);
	COEN244Cars.addCustomer(v2);
	COEN244Cars.addCustomer(v3);
	COEN244Cars.addCustomer(v4);

//Check customer list
	COEN244Cars.printCustomerList();

//Remove 10th customer to test removeCustomer()
	COEN244Cars.removeCustomer(10);

//Check customer list
	COEN244Cars.printCustomerList();

//rent a car
	COEN244Cars.rentCar(3,"Luxury");
	COEN244Cars.rentCar(3,"Luxury");

//Check if Car info appears under customer name
	COEN244Cars.printCustomer(3);

//Check Inventory to see if First Luxury Car has been set to unavailable
	COEN244Cars.printInventory();

//Return the car to inventory and update availability
	COEN244Cars.returnCar(3,8);

//Check if car returned successfully. Availability should be set to available, and customer cars rented updated.
	COEN244Cars.printInventory();
	COEN244Cars.printCustomer(3);

//Test the getPrivileges() Function on customer with ID 2, 5, and 11
	cout<<"*******************************************************"<<endl
		<<"Testing getPrivileges(): "<<endl<<endl
		<<"Privileges of customer with ID 2 (Regular): "<<COEN244Cars.getPrivileges(2)<<endl
		<<"Privileges of customer with ID 5 (Corporate): "<<COEN244Cars.getPrivileges(5)<<endl
		<<"Privileges of customer with ID 11 (VIP): "<<COEN244Cars.getPrivileges(11)<<endl;

//Test the changePrivileges() Function with new privileges 25,40 and 50
	cout<<"*******************************************************"<<endl
		<<"Testing changePrivileges(25,40,50)"<<endl<<endl;
	COEN244Cars.changePrivileges(25,40,50);
	cout<<"Privileges of customer with ID 2 (Regular): "<<COEN244Cars.getPrivileges(2)<<endl
		<<"Privileges of customer with ID 5 (Corporate): "<<COEN244Cars.getPrivileges(5)<<endl
		<<"Privileges of customer with ID 11 (VIP): "<<COEN244Cars.getPrivileges(11)<<endl;

	cout<<"CONGRATS"<<endl;
	return 0;
}
