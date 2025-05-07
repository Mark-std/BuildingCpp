#include "Rent.h"
std::ofstream& operator<<(std::ofstream& out, const Rent& c) {
	out << c.day << ' ' << c.price << ' ';
	c.writeTo(out);
	return out;
}