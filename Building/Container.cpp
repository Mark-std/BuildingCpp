#include "Cont.h"
#include <fstream>

Container::~Container() {
	for (int i = 0; i < top; ++i) {
		delete arr[i];
	}
	delete[] arr;
}

bool Container::add_rent(const Rent& r) {
	if (top < MAX_SIZE) {
		arr[top++] = r.clone(); return true;
	}
	return false;
}
void Container::read_from_file(const std::string& file_name) {
	std::ifstream file(file_name);
	if (!file.is_open()) {
		std::cout << "cant open file" << std::endl;
		return;
	}
	std::string street;
	double area, price;
	int rooms, day, size;
	file >> size; file.get();
	for (int k = 0; k < size; ++k) {
		file >> day >> price >> area >> rooms; file.get();
		getline(file, street);
		add_rent(Rent(day, price, street, area, rooms));
	}
	file.close();
}

double Container::calc_total_cost(const std::string& street) const {
	double sum = 0;
	for (int i = 0; i < top; ++i) {
		std::cout << "|" << arr[i]->getStreet() << "|";
		if (street == arr[i]->getStreet()) {
			sum += dynamic_cast<Rent*>(arr[i])->getTotalCost();
		}
	}
	return sum;
}