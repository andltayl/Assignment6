// Assignment6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "employeeList.h"

using namespace std;

int main()
{
	employeeList a;

	a.read_from_file("staff.txt");
	a.print();
}
