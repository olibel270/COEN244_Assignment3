#pragma once
#include <string>
using namespace std;

class Car
{
	friend class CarRentalManagement;
public:
	Car();
	Car(int, string, bool);
	Car(const Car &);
	~Car();

	int getID() const;
	string getCarType() const;
	bool getAvailability() const;
	void setAvailability(bool);

	void printCarInfo();

private:
	int id;
	string carType;
	bool availability;
};
