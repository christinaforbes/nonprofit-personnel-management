/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#include "employee.h"

// default constructor
Employee::Employee() : Volunteer() {
  type = 'E';
  isFullTime = false;
  position = "";
}

// overloaded constructor
Employee::Employee(int id, string fn, string ln, int a, string pn, string e, double yo, bool f, string pos) :
          Volunteer(id, fn, ln, a, pn, e, yo) {
  type = 'E';
  isFullTime = f;
  position = pos;
}

// outputs header for employee information
void Employee::printHeader(ostream& os) {
  // outputs divider line
  os << left << setw(150) << setfill('-') << "" << endl;
  // resets fill character
  os << setfill(' ');
  // outputs header
  os << setw(10) << "Type" << setw(10) << "ID#" << setw(15) << "Last Name" << setw(15) << "First Name"
      << setw(15) << "Phone" << setw(30) << "Email" << setw(10) << "Years"
      << setw(25) << "Position" << setw(10) << "Full Time?" << endl;
}

// outputs employee information
void Employee::print(ostream& os) {
  // if isFullTime is true, assigns "Yes" to isFullTimeStr; else, assigns "No" to isFullTimeStr
  string isFullTimeStr = (isFullTime) ? "Yes" : "No";
  
  os << left << setw(10) << type << setw(10) << IDNumber << setw(15) << lastName << setw(15) << firstName
    << setw(15) << phoneNumber << setw(30) << email << setw(10) << yearsAtOrganization
    << setw(25) << position << setw(10) << isFullTimeStr << endl;
}