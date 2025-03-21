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
	Building(std::string, double, int);
	~Building() {}
	bool removeRoom(double);
	void printOn(std::ostream&) const;

	bool operator==(const std::string& street) const {
		return this->street == street;
	}
	friend std::ostream& operator<<(std::ostream& out, const Building& c) {
		c.printOn(out); return out;
	}

};


#endif