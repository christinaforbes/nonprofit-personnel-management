/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#pragma once
#include <iostream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "linkedList.h"
#include "volunteer.h"
#include "employee.h"
using namespace std;

void readStaffList(istream& inputFile, ostream& errorFile, LinkedList<Volunteer>& volunteers, LinkedList<Employee>& employees);
// PRE:     accepts file input stream, output stream, LinkedList object of Volunteer objects, and LinkedList object of Employee objects
// POST:    reads input file and validates values
//            if no errors, adds volunteers and employees in file to respective linked lists and updates total counts
//            else, outputs error messages to errorFile

void printAllStaff(istream& inputFile, ostream& reportFile, ostream& errorFile,
                   const LinkedList<Volunteer>& volunteers, const LinkedList<Employee>& employees);
// PRE:     accepts input stream containing 'A' and possibly a letter, 2 output streams,
//            LinkedList object of Volunteer objects, and LinkedList object of Employee objects
// POST:    if 'A' is not followed by a letter (last initial) and linked lists are not empty,
//            outputs list of all employees and volunteers to reportFile
//          else if 'A' is followed by a letter (last initial) and at least 1 employee or volunteer with that last initial exists,
//            outputs list of all employees and volunteers with that last initial to reportFile
//          else, outputs error message to errorFile

void printVolunteers(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Volunteer>& volunteers);
// PRE:     accepts input stream containing 'V' and possibly a letter, 2 output streams, and LinkedList object of Volunteer objects
// POST:    if 'V' is not followed by a letter (last initial) and linked list is not empty,
//            outputs list of all volunteers to reportFile
//          else if 'V' is followed by a letter (last initial) and at least 1 volunteer with that last initial exists,
//            outputs list of all volunteers with that last initial to reportFile
//          else, outputs error message to errorFile

void printEmployees(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Employee>& employees);
// PRE:     accepts input stream containing 'E' and possibly a letter, 2 output streams, and LinkedList object of Employee objects
// POST:    if 'E' is not followed by a letter (last initial) and linked list is not empty,
//            outputs list of all employees to reportFile
//          else if 'E' is followed by a letter (last initial) and at least 1 employee with that last initial exists,
//            outputs list of all employees with that last initial to reportFile
//          else, outputs error message to errorFile

void printTotals(ostream& reportFile);
// PRE:     accepts output stream
// POST:    outputs number of volunteers, employees, and total staff to reportFile 

void findVolunteer(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Volunteer>& volunteers);
// PRE:     accepts input stream containing 'F' and an ID number, 2 output streams, and LinkedList object of Volunteer objects
// POST:    searches linked list for Volunteer object with matching ID number
//            if volunteer is found, outputs volunteer's information to reportFile
//            else, outputs error message to errorFile

void findEmployee(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Employee>& employees);
// PRE:     accepts input stream containing 'L' and an ID number, 2 output streams, and LinkedList object of Employee objects
// POST:    searches linked list for Employee object with matching ID number
//            if employee is found, outputs employee's information to reportFile
//            else, outputs error message to errorFile

void addStaff(istream& inputFile, ostream& reportFile, ostream& errorFile, LinkedList<Volunteer>& volunteers, LinkedList<Employee>& employees);
// PRE:     accepts input stream containing 'N' and volunteer or employee data, 2 output streams,
//            LinkedList object of Volunteer objects, and LinkedList object of Employee objects
// POST:    validates values
//            if no errors, adds volunteer or employee to respective linked list and updates total counts
//            else, outputs error messages to errorFile

void removeVolunteer(istream& inputFile, ostream& reportFile, ostream& errorFile, LinkedList<Volunteer>& volunteers);
// PRE:     accepts input stream containing 'R' and an ID number, 2 output streams, and LinkedList object of Volunteer objects
// POST:    searches linked list for Volunteer object with matching ID number
//            if volunteer is found, removes volunteer from linked list and updates total counts
//            else, outputs error message to errorFile

void removeEmployee(istream& inputFile, ostream& reportFile, ostream& errorFile, LinkedList<Employee>& employees);
// PRE:     accepts input stream containing 'D' and an ID number, 2 output streams, and LinkedList object of Employee objects
// POST:    searches linked list for Employee object with matching ID number
//            if employee is found, removes employee from linked list and updates total counts
//            else, outputs error message to errorFile