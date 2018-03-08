#include "RegularCustomer.h"
#include <iostream>
#include <iomanip>

RegularCustomer::RegularCustomer():Customer(){		//Privilege defined statically
	customerType = "Regular";
}

RegularCustomer::RegularCustomer(int cstmrID, string cstmrName, string cstmrAddress, string cstmrTel):Customer(cstmrID, cstmrName, cstmrAddress, cstmrTel){
	customerType = "Regular";
}

RegularCustomer::RegularCustomer(const RegularCustomer & CopyRegularCustomer):Customer(CopyRegularCustomer){
	customerType = CopyRegularCustomer.customerType;
}

RegularCustomer::~RegularCustomer(){
}

int RegularCustomer::privilege = 20;

void RegularCustomer::setPrivilege(int usrPrivilege){
	privilege = usrPrivilege;
}

int RegularCustomer::getPrivilege(){
	return privilege;
}

string RegularCustomer::getCustomerType() const{
	return customerType;
}

void RegularCustomer::printInfo() const{
	cout<<setw(6)<<getId()<<setw(20)<<getName()<<setw(30)<<getCarsRented()<<setw(30)<<getAddress()<<setw(20)<<getTel()<<setw(16)<<getCustomerType()<<setw(20)<<"------"<<setw(30)<<"------";
}

