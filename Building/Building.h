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
	virtual void printOn(std::ostream&) const;

	bool operator==(const std::string& street) const {
		return this->street == street;
	}
	friend std::ostream& operator<<(std::ostream& out, const Building& c) {
		c.printOn(out); return out;
	}

};


#endif