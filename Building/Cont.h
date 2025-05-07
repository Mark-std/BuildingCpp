#ifndef CONTAINER_H
#define CONTAINER_H

#include "Building.h"
#include "Rent.h"
#include <iostream>
#include <string>
class Container {
private:
	static const int MAX_SIZE = 100;
	Building** arr = new Building * [MAX_SIZE];
	int top;
public:
	Container() : top(0) {}
	~Container();

	bool add_rent(const Rent&);
	void read_from_file(const std::string&);
	int get_top() const { return top; }
	double calc_total_cost(const std::string&) const;
	void save_to_file(const std::string& filename);
	void delete_rent(int index);

	Building& operator[](int i) {
		return *arr[i];
	}
};

#endif