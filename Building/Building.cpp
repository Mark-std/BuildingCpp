#include <iostream>
#include "Rent.h"
#include "Windows.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Rent r(5, 100, "��������", 100, 3);
	Building mm[5];
	for (int k = 3; k < 5; k++) {
		mm[k] = Rent(5, 100, "��������", 100, 3);
	}
	//cout << dynamic_cast<Rent>(mm[1]);
	cout << r << endl;
	cout << "�������� �������: " << r.getTotalCost() << endl;
	r += 3;
	cout << "�������� �������: " << r.getTotalCost() << endl;

	return 0;
}