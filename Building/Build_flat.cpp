#include "Building.h"
#include <iostream>

Building::Building(std::string name, double area_, int rooms_) : street(name), rooms(rooms_), area(area_) {}

void Building::printOn(std::ostream& out) const {
	out << "st. " << street << " - " << rooms << " rooms. (" << area << " sq.un.)";
}

bool Building::removeRoom(double removed_area) {
	if (rooms > 1 && area - removed_area>0) {
		area -= removed_area;
		rooms--;
		return true;
	}
	std::cout << "cant take last room" << std::endl;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Building& c) {
	c.printOn(out);
	return out;
}

void Building::writeTo(std::ofstream& out) const {
	out << area << ' ' << rooms << ' ' << street << '\n';
}
