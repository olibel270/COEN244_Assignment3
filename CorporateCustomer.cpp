#include "CorporateCustomer.h"
#include <iostream>
#include <iomanip>

CorporateCustomer::CorporateCustomer():Customer(){
	companyName = "No Name";
	companyAddress = "No Address";
	customerType = "Corporate";
}

CorporateCustomer::CorporateCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel, string CrprtCstmrCmpnyName, string CrprtCstmrCmpnyAddress):Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel){
	companyName = CrprtCstmrCmpnyName;
	companyAddress = CrprtCstmrCmpnyAddress;
	customerType = "Corporate";
}

CorporateCustomer::CorporateCustomer(const CorporateCustomer & CopyCorperateCustomer):Customer(CopyCorperateCustomer){
	companyName = getCompanyName();
	companyAddress = getCompanyName();
	customerType = CopyCorperateCustomer.customerType;
}

CorporateCustomer::~CorporateCustomer(){

}

int CorporateCustomer::privilege = 35;

string CorporateCustomer::getCompanyName() const{
	return companyName;
}

string CorporateCustomer::getCompanyAddress() const{
	return companyAddress;
}

void CorporateCustomer::setPrivilege(int usrPrivilege){
	privilege = usrPrivilege;
}

int CorporateCustomer::getPrivilege(){
	return privilege;
}

string CorporateCustomer::getCustomerType() const{
	return customerType;
}

void CorporateCustomer::printInfo() const{
	cout<<setw(6)<<getId()<<setw(20)<<getName()<<setw(30)<<getCarsRented()<<setw(30)<<getAddress()<<setw(20)<<getTel()<<setw(16)<<getCustomerType()<<setw(20)<<getCompanyName()<<setw(30)<<getCompanyAddress();
}
