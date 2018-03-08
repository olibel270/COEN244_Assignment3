#ifndef VIPCUSTOMER_H_
#define VIPCUSTOMER_H_

#include "Customer.h"
class VIPCustomer:
	public Customer
{

public:
	VIPCustomer();									//Declaring Default Constructor
	VIPCustomer(int, string, string, string);		//Declaring Constructor
	VIPCustomer(const VIPCustomer &);				//Declaring Copy Constructor
	virtual ~VIPCustomer();							//Declaring Virtual Destructor Constructor

	static void setPrivilege(int);					//Function to set Privileges
	static int getPrivilege();						//Function to get Privileges
	virtual string getCustomerType() const;			//Function to get CustomerType
	virtual void printInfo() const;					//Function to printInformation

private:
	static int privilege = 45;						//Initializing the priviliges
};

#endif
