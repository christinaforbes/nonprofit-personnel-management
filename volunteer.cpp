/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#include "volunteer.h"

// default constructor
Volunteer::Volunteer() {
  type = 'V';
  IDNumber = 0;
  firstName = "";
  lastName = "";
  age = 0;
  phoneNumber = "";
  email = "";
  yearsAtOrganization = 0;
}

// overloaded constructor
Volunteer::Volunteer(int id, string fn, string ln, int a, string pn, string e, double yo) {
  type = 'V';
  IDNumber = id;
  firstName = fn;
  lastName = ln;
  age = a;
  phoneNumber = pn;
  email = e;
  yearsAtOrganization = yo;
}

// outputs header for volunteer information
void Volunteer::printHeader(ostream& os) {
  // outputs divider line
  os << left << setw(150) << setfill('-') << "" << endl;
  // resets fill character
  os << setfill(' ');
  // outputs header
  os << setw(10) << "Type" << setw(10) << "ID#" << setw(15) << "Last Name" << setw(15) << "First Name"
      << setw(15) << "Phone" << setw(30) << "Email" << setw(10) << "Years" << endl;
}

// outputs volunteer information
void Volunteer::print(ostream& os) {
  os << left << setw(10) << type << setw(10) << IDNumber << setw(15) << lastName << setw(15) << firstName
  << setw(15) << phoneNumber << setw(30) << email << setw(10) << yearsAtOrganization << endl;
}