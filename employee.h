/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#pragma once
#include <iomanip>
#include <string>
#include "volunteer.h"
using namespace std;

class Employee : public Volunteer {
private:
  bool isFullTime;
  string position;
public:
  // constructors
  Employee();
  Employee(int id, string fn, string ln, int a, string pn, string e, double yo, bool f, string pos);

  // getters
  bool getIsFullTime() { return isFullTime; };
  string getPosition() { return position; };

  // setters
  void setIsFullTime(bool ft) { isFullTime = ft; };
  void setPosition(string p) { position = p; };

  // print functions
  void printHeader(ostream& os);
  void print(ostream& os);

  static int totalEmployees;
};