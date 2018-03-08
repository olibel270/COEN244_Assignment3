#include "VIPCustomer.h"
#include <iostream>
#include <iomanip>

VIPCustomer::VIPCustomer():Customer(){		//privilege defined statically
	customerType = "VIP";
}

VIPCustomer::VIPCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel):Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel){
	customerType = "VIP";
}

VIPCustomer::VIPCustomer(const VIPCustomer & CopyVIPCustomer):Customer(CopyVIPCustomer){
	customerType = CopyVIPCustomer.customerType;
}

VIPCustomer::~VIPCustomer(){
}

int VIPCustomer::privilege = 45;

void VIPCustomer::setPrivilege(int usrPrivilege){
	privilege = usrPrivilege;
}

int VIPCustomer::getPrivilege(){
	return privilege;
}

string VIPCustomer::getCustomerType() const{
	return customerType;
}

void VIPCustomer::printInfo() const{
	cout<<setw(6)<<getId()<<setw(20)<<getName()<<setw(30)<<getCarsRented()<<setw(30)<<getAddress()<<setw(20)<<getTel()<<setw(16)<<getCustomerType()<<setw(20)<<"------"<<setw(30)<<"------";
}
