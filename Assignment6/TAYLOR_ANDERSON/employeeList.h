/*
 * Author: Anderson Taylor
 * Date: 11/9/18
 * File: employeeList.h
 * Description: Header file for the employeeList class.
 */
#pragma once
#include <string>

using namespace std;

struct node {						// Node struct to store the employee data.
	string first_name, last_name;
	double salary;
	node * next;
};

class employeeList
{
public:
	employeeList();
	/*
 * Description:
 *   Default constructor does nothing.
 *
 * Inputs:
 *   none
 *
 * Return:
 *   n/a
 */
	~employeeList();
	/*
 * Description:
 *   Deletes all nodes in the linked list.
 *
 * Inputs:
 *   none
 *
 * Return:
 *   n/a
 */
	void push_front(node * entry);
	/*
 * Description:
 *   Pushes a node onto the front of the list.
 *
 * Inputs:
 *   node * entry
 *     A pointer to a node.
 *
 * Return:
 *   void
 */
	void push_back(node * entry);
	/*
 * Description:
 *   Pushes a node onto the end of the list.
 *
 * Inputs:
 *   node * entry
 *     A pointer to a node.
 *
 * Return:
 *   void
 */
	void read_from_file(string file);
	/*
 * Description:
 *   Reads in employee data and puts it into the linked list.
 *
 * Inputs:
 *   string file
 *		the file name to read from.
 *
 * Return:
 *   void
 */
	void write_to_file(string file);
	/*
 * Description:
 *   Writes the contents of the linked list to a file.
 *
 * Inputs:
 *   string file
 *		the file name to write to.
 *
 * Return:
 *   void
 */
	double lookup(string fName, string lName);
	/*
 * Description:
 *   Looks up the salary of an employee.
 *
 * Inputs:
 *   string fName
 *     the first name of the employee to lookup.
 *	 string lName
 *	   the last name of the employee to lookup.
 * Return:
 *   double - The salary of the employee in question.
 */
	string reverse_lookup(double min, double max);
	/*
 * Description:
 *   Looks up all the employees that have a salary in the given range.
 *
 * Inputs:
 *   double min
 *     minimum salary value
 *	 double max
 *	   maximum salary value
 *
 * Return:
 *   string - all the employees that match the criteria.
 */
	void print();
	/*
 * Description:
 *   Print the contents of the list.
 *
 * Inputs:
 *   none
 *
 * Return:
 *   void
 */
	void delete_employee(string name);
	/*
 * Description:
 *   deletes an employee from the list.
 *
 * Inputs:
 *   string name
 *     Name of the employee to delete.
 *
 * Return:
 *   void
 */

private:
	node * head;
	node * tail;
};

