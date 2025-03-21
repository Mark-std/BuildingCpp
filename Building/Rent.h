#ifndef RENT_H
#define RENT_H

#include "Building.h"

class Rent : public Building {
private:
	int day;
	double price;
public:
	Rent() : day(0), price(0), Building() {}
	Rent(int day, double price, std::string street, double area, int rooms) : day(day), price(price), Building(street, area, rooms) {}
	~Rent() {};

	double getTotalCost() const { return price*day; }
	int getDay() const { return day; }
	void printOn(std::ostream& out) const override {
		Building::printOn(out);
		out << " - " << day << " днів (" << price << " грн/день)";
	}

	int operator+=(int days) {
		return day += days;
	}
};


#endif