#include <iostream>
#include "Windows.h"
#include "Cont.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Container c;
	c.read_from_file("data.txt");
	cout << c.calc_total_cost("Kovalcheyko 1") << endl;
	

	return 0;
}