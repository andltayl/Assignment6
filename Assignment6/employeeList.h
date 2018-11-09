#pragma once
#include <string>

using namespace std;

struct node {
	string first_name, last_name;
	double salary;
};

class employeeList
{
public:
	employeeList();
	~employeeList();
	void push_front(node n);
	void push_back(node n);
	void read_from_file(string file);
	void write_to_file(string file);
	double lookup(string fName, string lName);
	string reverse_lookup(double min, double max);
	void print();
	void delete_employee(string name);
};

