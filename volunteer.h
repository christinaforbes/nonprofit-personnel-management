/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#pragma once
#include <iomanip>
#include <string>
using namespace std;

class Volunteer {
protected:
  char type;
  int IDNumber;
  string firstName;
  string lastName;
  int age;
  string phoneNumber;
  string email;
  double yearsAtOrganization; 
public:
  // constructors
  Volunteer();
  Volunteer(int id, string fn, string ln, int a, string pn, string e, double yo);

  // getters
  char getType() { return type; };
  int getIDNumber() { return IDNumber; };
  string getFirstName() { return firstName; };
  string getLastName() { return lastName; };
  int getAge() { return age; };
  string getPhoneNumber() { return phoneNumber; };
  string getEmail() { return email; };
  double getYearsAtOrganization() { return yearsAtOrganization; };

  // setters
  void setType(char t) { type = t; };
  void setIDNumber(int id) { IDNumber = id; };
  void setFirstName(string fn) { firstName = fn; };
  void setLastName(string ln) { lastName = ln; };
  void setAge(int a) { age = a; };
  void setPhoneNumber(string pn) { phoneNumber = pn; };
  void setEmail(string e) { email = e; };
  void setYearsAtOrganization(double yo) { yearsAtOrganization = yo; };

  // print functions
  void printHeader(ostream& os);
  void print(ostream& os);

  static int totalVolunteers;
};