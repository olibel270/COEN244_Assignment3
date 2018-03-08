#pragma once
#include <string>
using namespace std;

class Car
{
	friend class CarRentalManagement;		//Making CarRentalManagement a friend so it can access private memebers

public:
	Car();									//Declairing Default Constructor for Car
	Car(int, string, bool);					//Declairing Constructor for Car
	Car(const Car &);						//Declairing Copy Constructor for Car
	~Car();									//Declairing Destructor for Car

	int getID() const;						//Declaring  getID for Car
	string getCarType() const;				//Declaring  getCarType for Car
	bool getAvailability() const;			//Declaring  getAvailability for Car
	void setAvailability(bool);				//Declaring  setAvailability for Car

	void printCarInfo();					//Declaring  printCarInfo for Car

private:
	int id;									//Declaring id
	string carType;							//Declaring carType
	bool availability;						//Declaring availability
};
