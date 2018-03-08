#include "CorporateCustomer.h"
#include <iostream>
#include <iomanip>

CorporateCustomer::CorporateCustomer():
	Customer(),
	companyName( "No Name"),
	companyAddress( "No Address"),
	customerType( "Corporate")
{
}

CorporateCustomer::CorporateCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel, string CrprtCstmrCmpnyName, string CrprtCstmrCmpnyAddress):
	Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel),
	companyName(CrprtCstmrCmpnyName),
	companyAddress(CrprtCstmrCmpnyAddress),
	customerType("Corporate")
{
}

CorporateCustomer::CorporateCustomer(const CorporateCustomer & CopyCorperateCustomer):Customer(CopyCorperateCustomer):
	companyName(getCompanyName()),
	companyAddress(getCompanyName()),
	customerType(CopyCorperateCustomer.customerType)
{
}

CorporateCustomer::~CorporateCustomer()
{
}


string CorporateCustomer::getCompanyName() const
{
	return companyName;
}

string CorporateCustomer::getCompanyAddress() const
{
	return companyAddress;
}

void CorporateCustomer::setPrivilege(int usrPrivilege)
{
	privilege = usrPrivilege;
}

int CorporateCustomer::getPrivilege()
{
	return privilege;
}

string CorporateCustomer::getCustomerType() const
{
	return customerType;
}

void CorporateCustomer::printInfo() const
{
	cout<< "Id: " << getId() << endl;
	cout<< "Name: " << getName() << endl;
	cout<< "CarsRented: " << getCarsRented() << endl;
	cout<< "Address: " << getAddress() << endl;
	cout<< "Tel: " << getTel() << endl;
	cout<< "CustomerType: " << getCustomerType() << endl;
	cout<< "CompanyName: " << getCompanyName() << endl;
	cout<< "CompanyAddress: " << getCompanyAddress();
}