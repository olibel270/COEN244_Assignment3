#include "Car.h"
#include <iostream>

Car::Car(){
	id = -1;
	carType = "NOT SET";
	availability = true;
}

Car::Car(int nmbr, string CrTyp, bool avlble){
	id = nmbr;
	carType  = CrTyp;
	availability = avlble;
}

Car::Car(const Car & CopyCar){
	id = CopyCar.getID();
	carType = CopyCar.getCarType();
	availability = CopyCar.getAvailability();
}


Car::~Car()
{
}

int Car::getID() const
{
	return id;
}

string Car::getCarType() const
{
	return carType;
}

bool Car::getAvailability() const{
	return availability;
}

void Car::setAvailability(bool newAvailability){
	availability = newAvailability;
}

void Car::printCarInfo(){
	cout<<id<<" "<<carType<<" "<<availability<<endl;
}
