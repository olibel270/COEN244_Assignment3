#ifndef REGULARCUSTOMER_H_
#define REGULARCUSTOMER_H_

#include "Customer.h"
class RegularCustomer :public Customer{

public:
	RegularCustomer();
	RegularCustomer(int, string, string, string);
	RegularCustomer(const RegularCustomer &);
	~RegularCustomer();

	static void setPrivilege(int);
	static int getPrivilege();
	virtual string getCustomerType() const;
	virtual void printInfo() const;

private:
	static int privilege;

private:

};
#endif
