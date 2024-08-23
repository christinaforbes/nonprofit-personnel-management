/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#include <fstream>
#include "linkedList.h"
#include "volunteer.h"
#include "employee.h"
#include "functions.h"
using namespace std;

// initializes totals
int Volunteer::totalVolunteers = 0;
int Employee::totalEmployees = 0;

int main() {
  ifstream listFile;
  ifstream commandsFile;
  ofstream reportFile;
  ofstream errorFile;

  listFile.open("staffList.txt");
  commandsFile.open("commandList.txt");
  reportFile.open("staffReport.txt");
  errorFile.open("errorReport.txt");
  
  if (!listFile.is_open()) {
    cout << "Unable to open staffList.txt" << endl << endl;
  }

  if (!commandsFile.is_open()) {
    cout << "Unable to open commandList.txt" << endl << endl;
  }

  LinkedList<Volunteer> volunteerList;
  LinkedList<Employee> employeeList;

  readStaffList(listFile, errorFile, volunteerList, employeeList);

  string commandsFileLine;
  
  // reads each command file line
  while (getline(commandsFile, commandsFileLine)) {
    stringstream fileLineSS(commandsFileLine);
    char command = commandsFileLine.at(0);
    
    if (command == 'Q') {
      break;
    }

    switch (command) {
      case 'A':
        printAllStaff(fileLineSS, reportFile, errorFile, volunteerList, employeeList);
        break;
      case 'V':
        printVolunteers(fileLineSS, reportFile, errorFile, volunteerList);
        break;
      case 'E':
        printEmployees(fileLineSS, reportFile, errorFile, employeeList);
        break;
      case 'T':
        printTotals(reportFile);
        break;
      case 'F':
        findVolunteer(fileLineSS, reportFile, errorFile, volunteerList);
        break;
      case 'L':
        findEmployee(fileLineSS, reportFile, errorFile, employeeList);
        break;
      case 'N':
        addStaff(fileLineSS, reportFile, errorFile, volunteerList, employeeList);
        break;
      case 'R':
        removeVolunteer(fileLineSS, reportFile, errorFile, volunteerList);
        break;
      case 'D':
        removeEmployee(fileLineSS, reportFile, errorFile, employeeList);
        break;
    }
  }

  listFile.close();
  commandsFile.close();
  reportFile.close();
  errorFile.close();

  return 0;
}