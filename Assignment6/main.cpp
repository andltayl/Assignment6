/*
 * Author: Anderson Taylor
 * Date: 11/9/18
 * File: main.cpp
 * Description: Main driver for the program.
 */

#include <iostream>
#include "employeeList.h"

using namespace std;

int main()
{
	employeeList list;
	node * temp = new node;
	string filename, first_name, last_name;
	double min, max, salary;
	int choice = 0;

	while (choice != 8) {
		cout << "Welcome to UTM! You may select one of the folowing options:\n"
			<< "1 Read an employee list from a file\n"
			<< "2 Write the employee list to a file\n"
			<< "3 Print the employee list\n"
			<< "4 Search for an employees\n"
			<< "5 Reverse lookup by a salary range\n"
			<< "6 Add an employee\n"
			<< "7 Delete an employee\n"
			<< "8 Exit this program\n\n"
			<< "Please enter your choice now: ";
		cin >> choice;

		switch (choice) {
			// Read an employees from a file
		case 1:
			cout << "Name of file to read from: "; cin >> filename;
			list.read_from_file(filename);
			cout << endl;
			break;
			// Write the employees to a file
		case 2:
			cout << "Name of file to write to: "; cin >> filename;
			cout << endl;
			list.write_to_file(filename);
			break;
			// Print the employee list
		case 3:
			cout << "\nCurrent list:\n" << endl;
			list.print();
			break;
			// Search for an employee salary
		case 4:
			cout << "Please enter an employee's first name: " << endl;
			cin >> first_name;
			cout << "Please enter the employee's last name: " << endl;
			cin >> last_name;
			cout << endl;
			cout << "\nSalary: $" << list.lookup(first_name, last_name) << endl;
			cout << endl;
			break;
			// Lookup by a salary range
		case 5:
			cout << "Enter a minimum value for salary: "; cin >> min;
			cout << "Enter a maximum value for salary: "; cin >> max;
			cout << "List of people within min and max: " << endl;
			cout << endl;
			cout << "Matching Employees:\n" << list.reverse_lookup(min, max);
			cout << endl;
			break;
			// Add an employee
		case 6:
			cout << "Please enter the new employee's first name: " << endl;
			cin >> first_name;
			cout << "Please enter the new employee's last name: " << endl;
			cin >> last_name;
			cout << "Please enter how much the new employee's salary is to 2 decimal places: " << endl;
			cin >> salary;

			temp->first_name = first_name;
			temp->last_name = last_name;
			temp->salary = salary;
			temp->next = NULL;

			cout << endl;
			list.push_back(temp);
			break;
			// Delete an employee
		case 7:
			cout << "Please enter an employee's full name to delete: " << endl;
			cin >> first_name >> last_name;
			first_name += (" " + last_name);
			cout << endl;
			list.delete_employee(first_name);
			break;
			// Exit the program
		case 8:
			cout << "Thanks for using the UTM employee program!" << endl;
			break;

		default:
			cout << "Error! Invalid user input of integers 1 - 8." << endl;
		}
	}
}
