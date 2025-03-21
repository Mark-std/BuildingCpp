#include "Building.h"
#include <iostream>

Building::Building(std::string name, double area_, int rooms_) : street(name), rooms(rooms_), area(area_) {}

void Building::printOn(std::ostream& out) const {
	out << "вул. " << street << " - " << rooms << " кімн. (" << area << "кв.м)";
}

bool Building::removeRoom(double removed_area) {
	if (rooms > 1) {
		area -= removed_area;
		rooms--;
		return true;
	}
	std::cout << "Не можливо забрати єдину кімнату!" << std::endl;
	return false;
}