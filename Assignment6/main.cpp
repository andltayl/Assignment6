// Assignment6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "employeeList.h"

using namespace std;

int main()
{
	employeeList a;

	a.read_from_file("staff.txt");

	node temp;
	temp.first_name = "John";
	temp.last_name = "Wayne";
	temp.salary = 45000;
	temp.next = NULL;

	a.push_back(&temp);

	a.print();
	cout << a.lookup("Beau", "Taylor") << '\n';
	cout << a.reverse_lookup(30000, 1000000);
	a.delete_employee("Anderson Taylor");
	a.print();
	a.write_to_file("test_output.txt");


}
