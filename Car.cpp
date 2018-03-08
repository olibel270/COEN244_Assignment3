#include "Car.h"
#include <iostream>

Car::Car()												//Defaut Constructor for Car
{
	id = -1;
	carType = "NOT SET";
	availability = true;
}

Car::Car(int nmbr, string CrTyp, bool avlble)			//Constructor for Car
{
	id = nmbr;
	carType  = CrTyp;
	availability = avlble;
}

Car::Car(const Car & CopyCar)							//Copy Constructor for Car
{
	id = CopyCar.getID();
	carType = CopyCar.getCarType();
	availability = CopyCar.getAvailability();
}


Car::~Car()												//Destructor for Car
{
}

int Car::getID() const 									//Function to get car ID
{
	return id;
}

string Car::getCarType() const 							//Function to get the car Type
{
	return carType;
}

bool Car::getAvailability() const  						//Function to get car avalibility
{
	return availability;
}

void Car::setAvailability(bool newAvailability)			//Function to set car avalibility
{
	availability = newAvailability;
}

void Car::printCarInfo()								//Function to display Car details
{
	cout<<id<<" "<<carType<<" "<<availability<<endl;
}
