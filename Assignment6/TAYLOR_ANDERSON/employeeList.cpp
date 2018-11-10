/*
 * Author: Anderson Taylor
 * Date: 11/9/18
 * File: employeeList.cpp
 * Description: Implementation file for the employeeList class.
 */
#include "employeeList.h"
#include <fstream>
#include <iomanip>
#include <iostream>


employeeList::employeeList()
{

}


employeeList::~employeeList()
{
	node * temp = head;

	while (head != NULL) {
		
		temp = head->next;
		delete head;
		head = temp;
	}
}

void employeeList::push_front(node * entry)
{
	entry->next = head;
	head = entry;
}

void employeeList::push_back(node * entry)
{
		tail->next = entry;
		tail = entry;
}

void employeeList::read_from_file(string file)
{
	ifstream iFile;

	iFile.open(file.c_str());

	while (iFile) {
		node * temp = new node;

		if (head == NULL) {
			head = temp;
			tail = temp;
		}

		iFile >> temp->first_name;
		iFile >> temp->last_name;
		iFile >> temp->salary;

		temp->next = NULL;
		
		push_back(temp);
		
		iFile.get();
	}

	iFile.close();
}

void employeeList::write_to_file(string file)
{
	ofstream oFile;
	oFile.open(file.c_str());
	node * temp = head;

	while (temp != NULL) {
		oFile << '\n' << temp->first_name << " " << temp->last_name << '\n';
		oFile << fixed << setprecision(2) << temp->salary;

		temp = temp->next;
	}

	oFile.close();
}

double employeeList::lookup(string fName, string lName)
{
	node * temp = head;

	while (temp != NULL) {
		if (temp->first_name == fName && temp->last_name == lName) {
			return temp->salary;
		}
		temp = temp->next;
	}
	return -1;
}

string employeeList::reverse_lookup(double min, double max)
{
	node * temp = head;
	string names;

	while (temp != NULL) {
		if (temp->salary <= max && temp->salary >= min) {
			names += temp->first_name + " " + temp->last_name + '\n';
		}
		temp = temp->next;
	}

	if (names.length() > 1) {
		return names;
	}
	
	return "No matches found.\n";
}

void employeeList::print()
{
	node * temp = head;

	while (temp != NULL) {
		cout << "Name: " << temp->first_name << " " << temp->last_name << '\n';
		cout << fixed << setprecision(2) << "Salary: $" << temp->salary << '\n' << endl;

		temp = temp->next;		
	}
}

void employeeList::delete_employee(string name)
{
	node * current = head;
	node * prev = head;

	int n = name.find_first_of(' ');			// Split the name up.
	string fName = name.substr(0, n);
	string lName = name.substr(n + 1, name.length() - 1);

	while (current != NULL) {

		if (current->first_name == fName && current->last_name == lName) {

			if (current == head) {			// If the node to be deleted is the head then head has to be reassigned.
				head = current->next;
			}

			prev->next = current->next;
			delete current;
			return;
		}
		prev = current;
		current = current->next;
	}
	cout << "\nEmployee Not Found!\n";
	return;
}
