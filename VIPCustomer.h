#ifndef VIPCUSTOMER_H_
#define VIPCUSTOMER_H_

#include "Customer.h"
class VIPCustomer :public Customer{

public:
	VIPCustomer();
	VIPCustomer(int, string, string, string);
	VIPCustomer(const VIPCustomer &);
	virtual ~VIPCustomer();

	static void setPrivilege(int);
	static int getPrivilege();
	virtual string getCustomerType() const;
	virtual void printInfo() const;

private:
	static int privilege;
};

#endif
