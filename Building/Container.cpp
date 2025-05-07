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
		arr[top++] = new Rent(r); return true;
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
		if (arr[i]->getStreet()==street) {
			sum += arr[i]->getTotalCost();
		}
	}
	return sum;
}
void Container::save_to_file(const std::string& filename) {
	std::ofstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
		return;
	}
	file << top; file << '\n';
	for (int k = 0; k < top; ++k) {
		file << *arr[k];
	}

	file.close();
}
void Container::delete_rent(const std::string& street) {
	if (top < 1) return;

	Rent* temp = nullptr;

	for (int i = 0; i < top; ++i) {
		if (arr[i]->getStreet() == street) {
			delete arr[i];
			for (int t = i + 1; t < top; ++t) {
				arr[t - 1] = arr[t];
			}
			std::cout << "deleted";
			top--;
			return;
		}
	}
}