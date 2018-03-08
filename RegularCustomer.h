#ifndef REGULARCUSTOMER_H_
#define REGULARCUSTOMER_H_

#include "Customer.h"
class RegularCustomer:
	public Customer
{

public:
	RegularCustomer();								//Declaring Default Constructor
	RegularCustomer(int, string, string, string);	//Declaring Constructor
	RegularCustomer(const RegularCustomer &);		//Declaring Copy Constructor
	~RegularCustomer();								//Declaring Destructor

	static void setPrivilege(int);					//Declaring Function to set Privilege
	static int getPrivilege();						//Declaring Function to get Privilege
	virtual string getCustomerType() const;			//Declaring Function to get CustomerType
	virtual void printInfo() const;					//Declaring Function to printInformation

private:
	static int privilege = 20;						//Declaring privilege statically

};

#endif