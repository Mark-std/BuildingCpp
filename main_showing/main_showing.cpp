#include "Cont.h"
#include <iostream>
using namespace std;
int main()
{
	Container container;

	container.read_from_file("info.txt");

	container.add_rent(Rent(4, 55.4, "Kovalya 2", 56.4, 4));
	double total = container.calc_total_cost("Kovalcheyko 1");
	cout << "All rent building : " << endl;
	for (int i = 0; i < container.get_top(); i++)
	{
		cout << container[i] << '\n';
	}
	cout << "Total street cost: " << total << endl;
}

