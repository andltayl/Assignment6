#pragma once
#include <string>

using namespace std;

struct node {
	string first_name, last_name;
	double salary;
	node * next;
};

class employeeList
{
public:
	employeeList();
	~employeeList();
	void push_front(node entry);
	void push_back(node entry);
	void read_from_file(string file);
	void write_to_file(string file);
	double lookup(string fName, string lName);
	string reverse_lookup(double min, double max);
	void print();
	void delete_employee(string name);

private:
	node * head;
	node * tail;
};

