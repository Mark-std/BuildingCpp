﻿#include "../Building/Cont.h"
#include <iostream>
using namespace std;
int main()
{
    Container container;

    container.read_from_file("data.txt");

    container.add_rent(Rent(4, 55.4, "Kovalya 2", 56.4, 4));
    double total = container.calc_total_cost("Kovalcheyko 1");
    cout << "All rent building : " << endl;
    for (int i = 0; i < container.get_top(); i++)
    {
        cout << container[i] << '\n';
    }
    cout << "Total street cost: " << total << endl;

    int choice;
    string filename = "info.txt";
    cout << "=============================" << endl;
    cout << "   Welcome to the Program!   " << endl;
    cout << "   Building.cpp          " << endl;
    cout << "=============================" << endl;
    cout << endl;
    cout << "=============================" << endl;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Load data from file" << endl;
        cout << "2. Add new rental" << endl;
        cout << "3. Calculate total cost by street" << endl;
        cout << "4. Show all rental properties" << endl;
        cout << "5. Save data to file" << endl;
        cout << "6. Delete rent" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter filename (default " << filename << "): ";
            string input;
            cin.ignore();
            getline(cin, input);
            if (!input.empty()) {
                filename = input;
            }
            container.read_from_file(filename);
            cout << "Data loaded from file " << filename << endl;
            break;
        }
        case 2: {
            int area, rooms;
            double price, meters;
            string address;

            cout << "Enter address: ";
            cin.ignore();
            getline(cin, address);

            cout << "Enter number of rooms: ";
            cin >> rooms;

            cout << "Enter area (sq.m): ";
            cin >> meters;

            cout << "Enter price: ";
            cin >> price;

            cout << "Enter floor: ";
            cin >> area;

            container.add_rent(Rent(rooms, price, address, meters, area));
            cout << "New rental added successfully" << endl;
            break;
        }
        case 3: {
            string street;
            cout << "Enter street name to calculate total cost: ";
            cin.ignore();
            getline(cin, street);

            double total = container.calc_total_cost(street);
            cout << "Total rental cost for " << street << ": " << total << endl;
            break;
        }
        case 4: {
            cout << "All rental properties:" << endl;
            for (int i = 0; i < container.get_top(); i++) {
                cout << container[i] << '\n';
            }
            break;
        }
        case 5: {
            cout << "Enter filename for saving (default " << filename << "): ";
            string input;
            cin.ignore();
            getline(cin, input);
            if (!input.empty()) {
                filename = input;
            }
            container.save_to_file(filename);
            cout << "Data saved to file " << filename << endl;
            break;
        }
        case 6: {
            if (container.get_top() == 0) {
                cout << "No rentals to delete." << endl;
                break;
            }

            cout << "Current rentals:" << endl;
            for (int i = 0; i < container.get_top(); i++) {
                cout << i + 1 << ". " << container[i] << '\n';
            }

            int index;
            cout << "Enter the number of the rental to delete (1-" << container.get_top() << "): ";
            cin >> index;

            if (index < 1 || index > container.get_top()) {
                cout << "Invalid rental number." << endl;
            }
            else {
                cout << "Rental deleted successfully." << endl;
            }
            break;
        }
        case 0:
            cout << "Thank you for using the Rental Management Program!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}


