#ifndef RENT_H
#define RENT_H

#include "Building.h"

class Rent : public Building {
private:
	int day;
	double price;
public:
	Rent(int day, double price, std::string street, double area, int rooms) : day(day), price(price), Building(street, area, rooms) {}
	~Rent() {};

	double getTotalCost() const { return price*day; }
	int getDay() const { return day; }

	int operator+(int days) {
		return day += days;
	}
};


#endif