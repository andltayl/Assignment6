#include "employeeList.h"
#include <fstream>
#include <iomanip>
#include <iostream>


employeeList::employeeList()
{

}


employeeList::~employeeList()
{
}

void employeeList::push_front(node entry)
{
	entry.next = head;
	head = &entry;
}

void employeeList::push_back(node entry)
{
	tail -> next = &entry;
	tail = &entry;
}

void employeeList::read_from_file(string file)
{
	ifstream iFile;

	iFile.open(file.c_str());

	while (iFile) {
		node * temp = new node;

		if (head == NULL) {
			head = temp;
		}

		iFile >> temp->first_name;
		iFile >> temp->last_name;
		iFile >> temp->salary;
		
		tail->next = temp;
		tail = temp;
	}

	iFile.close();
}

void employeeList::write_to_file(string file)
{
}

double employeeList::lookup(string fName, string lName)
{
	return 0.0;
}

string employeeList::reverse_lookup(double min, double max)
{
	return string();
}

void employeeList::print()
{
	node * temp = head;

	while (temp != NULL) {
		cout << "Name: " << temp->first_name << " " << temp->last_name << '\n';
		cout << "Salary: $" << temp->salary << '\n' << endl;

		temp = temp->next;
	}
}

void employeeList::delete_employee(string name)
{
}
