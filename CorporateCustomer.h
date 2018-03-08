#ifndef CORPORATECUSTOMER_H_
#define CORPORATECUSTOMER_H_

#include "Customer.h"
class CorporateCustomer :public Customer
{

public:
	CorporateCustomer();
	CorporateCustomer(int, string, string, string, string, string);
	CorporateCustomer(const CorporateCustomer &);
	~CorporateCustomer();

	string getCompanyName() const;
	string getCompanyAddress() const;

	static void setPrivilege(int);
	static int getPrivilege();
	virtual string getCustomerType() const;
	virtual void printInfo() const;

private:
	string companyName;
	string companyAddress;
	static int privilege;
};

#endif
