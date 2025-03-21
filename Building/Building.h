#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <string>

class Building {
private:
	std::string street;
	double area;
	int rooms;
public:
	Building() : street("Unknown"), area(0), rooms(0) {}
	Building(std::string, double, int);
	virtual ~Building() {}

	bool removeRoom(double);
	virtual Building* clone() const = 0;
	virtual void printOn(std::ostream&) const;
	std::string getStreet() const { return street; }

	bool operator==(const std::string& street) const {
		return this->street == street;
	} 
};

std::ostream& operator<<(std::ostream& out, const Building& c);

#endif