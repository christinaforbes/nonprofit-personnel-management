/*  Christina Forbes and Yuqing Cai
    Program 5 (Group Assignment)
    11/20/2023
*/

#include "functions.h"

void readStaffList(istream& inputFile, ostream& errorFile, LinkedList<Volunteer>& volunteers, LinkedList<Employee>& employees) {
  string inputFileLine;

  // reads each input file line
  while (getline(inputFile, inputFileLine)) {
    if (inputFileLine == "Q") {
      break;
    }
    else {
      stringstream fileLineSS(inputFileLine);
      vector<string> fileLineData;
      string temp;

      // reads data (separated by a comma) in each line
      while (getline(fileLineSS, temp, ',')) {
        fileLineData.push_back(temp);
      }

      try {
        // validates values
        char type = fileLineData.at(0).at(0);
        int IDNumber = stoi(fileLineData.at(1));
        string firstName = fileLineData.at(2);
        string lastName = fileLineData.at(3);
        int age = stoi(fileLineData.at(4));
        string phoneNumber = fileLineData.at(5);
        string email = fileLineData.at(6);
        double yearsAtOrganization = stod(fileLineData.at(7));

        bool isFullTime;
        string position;
       
        if (type == 'E') {
          string isFullTimeStr = fileLineData.at(8);
          
          if (isFullTimeStr != "0" && isFullTimeStr != "1") {
            string msg = "Error: '" + isFullTimeStr + "' is an invalid full-time status.";
            throw runtime_error(msg);
          }
          else {
            // if isFullTimeStr equals "1", assigns true to isFullTime; else, assigns false to isFullTime
            isFullTime = (isFullTimeStr == "1") ? true : false;
          }

          position = fileLineData.at(9);
        }
        
        if (type != 'V' && type != 'E') {
          string msg = "Error: '" + string(1, type) + "' is an invalid staff type.";
          throw runtime_error(msg);
        }

        if (IDNumber <= 0) {
          string msg = "Error: " + to_string(IDNumber) + " is an invalid ID number.";
          throw runtime_error(msg);
        }

        if (age < 16) {
          string msg = "Error: " + to_string(age) + " is an invalid age.";
          throw runtime_error(msg);
        }

        if (yearsAtOrganization < 0) {
          string msg = "Error: " + to_string(yearsAtOrganization) + " is an invalid number of years.";
          throw runtime_error(msg);
        }

        if (type == 'V') {
          // creates new Volunteer object, sets values, and adds object to linked list of volunteers
          Volunteer tempVolunteer;
          tempVolunteer.setIDNumber(IDNumber);
          tempVolunteer.setFirstName(firstName);
          tempVolunteer.setLastName(lastName);
          tempVolunteer.setAge(age);
          tempVolunteer.setPhoneNumber(phoneNumber);
          tempVolunteer.setEmail(email);
          tempVolunteer.setYearsAtOrganization(yearsAtOrganization);
          volunteers.addNode(tempVolunteer);
        }
        else if (type == 'E') {
          // creates new Employee object, sets values, and adds object to linked list of employees
          Employee tempEmployee;
          tempEmployee.setIDNumber(IDNumber);
          tempEmployee.setFirstName(firstName);
          tempEmployee.setLastName(lastName);
          tempEmployee.setAge(age);
          tempEmployee.setPhoneNumber(phoneNumber);
          tempEmployee.setEmail(email);
          tempEmployee.setYearsAtOrganization(yearsAtOrganization);
          tempEmployee.setIsFullTime(isFullTime);
          tempEmployee.setPosition(position);
          employees.addNode(tempEmployee);
        }

        // updates totals
        if (type == 'V') {
          Volunteer::totalVolunteers++;
        }
        else if (type == 'E') {
          Employee::totalEmployees++;
        }
      }
      catch (invalid_argument& error) {
        errorFile << "Line: " << inputFileLine << endl;
        errorFile << "Error: " << error.what() << " error." << endl << endl;
      }
      catch (out_of_range& error) {
        errorFile << "Line: " << inputFileLine << endl;
        errorFile << "Error: " << error.what() << " error." << endl << endl;
      }
      catch (runtime_error& error) {
        errorFile << "Line: " << inputFileLine << endl;
        errorFile << error.what() << endl << endl;
      }
    }
  }
  
  return;
}

void printAllStaff(istream& inputFile, ostream& reportFile, ostream& errorFile,
                   const LinkedList<Volunteer>& volunteers, const LinkedList<Employee>& employees) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  // command file line does not contain letter (last initial)
  if (commandLineData.size() == 1) {
    if (employees.isEmpty() && volunteers.isEmpty()) {
      errorFile << "Unable to print report. No employees or volunteers." << endl << endl;
    }
    else {
      // ouputs list of all employees and volunteers
      reportFile << "EMPLOYEES AND VOLUNTEERS" << endl;
      employees.printList(reportFile);
      volunteers.printList(reportFile);
      reportFile << endl << endl << endl;
    }
  }
  // command file line contains letter (last initial)
  else if (commandLineData.size() == 2) {
    char lastNameLetter = commandLineData.at(1).at(0);

    if (!employees.matchingNodesExist(lastNameLetter) && !volunteers.matchingNodesExist(lastNameLetter)) {
      errorFile << "Unable to print report. No employees or volunteers whose last name starts with "
                << string(1, lastNameLetter) << "." << endl << endl;
    }
    else {
      // outputs list of all employees and volunteers with last initial
      reportFile << "EMPLOYEES AND VOLUNTEERS" << endl;
      employees.printList(reportFile, lastNameLetter);
      volunteers.printList(reportFile, lastNameLetter);
      reportFile << endl << endl << endl;
    }
  }

  return;
}

void printVolunteers(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Volunteer>& volunteers) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  // command file line does not contain letter (last initial)
  if (commandLineData.size() == 1) {
    if (volunteers.isEmpty()) {
      errorFile << "Unable to print report. No volunteers." << endl << endl;
    }
    else {
      // outputs list of all volunteers
      reportFile << "VOLUNTEERS" << endl;
      volunteers.printList(reportFile);
      reportFile << endl << endl << endl;
    }
  }
  // command file line contains letter (last initial)
  else if (commandLineData.size() == 2) {
    char lastNameLetter = commandLineData.at(1).at(0);

    if (!volunteers.matchingNodesExist(lastNameLetter)) {
      errorFile << "Unable to print report. No volunteers whose last name starts with "
                << string(1, lastNameLetter) << "." << endl << endl;
    }
    else {
      // outputs list of all volunteers with last initial
      reportFile << "VOLUNTEERS" << endl;
      volunteers.printList(reportFile, lastNameLetter);
      reportFile << endl << endl << endl;
    }
  }
  
  return;
}

void printEmployees(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Employee>& employees) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  // command file line does not contain letter (last initial)
  if (commandLineData.size() == 1) {
    if (employees.isEmpty()) {
      errorFile << "Unable to print report. No employees." << endl << endl;
    }
    else {
      // outputs list of all employees
      reportFile << "EMPLOYEES" << endl;
      employees.printList(reportFile);
      reportFile << endl << endl << endl;
    }
  }
  // command file line contains letter (last initial)
  else if (commandLineData.size() == 2) {
    char lastNameLetter = commandLineData.at(1).at(0);

    if (!employees.matchingNodesExist(lastNameLetter)) {
      errorFile << "Unable to print report. No employees whose last name starts with "
                << string(1, lastNameLetter) << "." << endl << endl;
    }
    else {
      // outputs list of all employees with last initial
      reportFile << "EMPLOYEES" << endl;
      employees.printList(reportFile, lastNameLetter);
      reportFile << endl << endl << endl;
    }
  }
  
  return;
}

void printTotals(ostream& reportFile) {
  // outputs header
  reportFile << "STAFF TOTALS" << endl;
  // outputs divider line
  reportFile << setw(150) << setfill('-') << "" << endl;
  // resets fill character
  reportFile << setfill(' ');

  // outputs totals
  reportFile << setw(15) << "Volunteers: " << setw(10) << Volunteer::totalVolunteers << endl;
  reportFile << setw(15) << "Employees: " << setw(10) << Employee::totalEmployees << endl;
  reportFile << setw(15) << "Total Staff: " << setw(10) << Volunteer::totalVolunteers + Employee::totalEmployees << endl;
  reportFile << endl << endl << endl;
}

void findVolunteer(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Volunteer>& volunteers) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  try {
    // validates ID number
    int IDNumber = stoi(commandLineData.at(1));

    Volunteer volunteer = volunteers.findNode(IDNumber);
    
    // volunteer with IDNumber does not exist
    if (volunteer.getIDNumber() == 0) {
      string msg = "Unable to find volunteer. No volunteers with ID number: " + to_string(IDNumber) + ".";
      throw runtime_error(msg);
    }
    // volunter with IDNumber exists
    else {
      // outputs information about volunteer with IDNumber
      reportFile << "RESULTS FOR ID NUMBER" << to_string(IDNumber) << endl;
      reportFile << setw(150) << setfill('-') << "" << endl;
      reportFile << "Name: " << volunteer.getFirstName() << " " << volunteer.getLastName() << endl;
      reportFile << "Phone Number: " << volunteer.getPhoneNumber() << endl;
      reportFile << "Email: " << volunteer.getEmail() << endl;
      reportFile << "Years at Organization" << volunteer.getYearsAtOrganization() << endl;
      reportFile << endl << endl << endl;
    }
  }
  catch(invalid_argument& error) {
    errorFile << "Unable to find volunteer. Invalid ID number." << endl << endl;
  }
  catch (out_of_range& error) {
    errorFile << "Unable to find volunteer. Invalid ID number." << endl << endl;
  }
  catch (runtime_error& error) {
    errorFile << error.what() << endl << endl;
  }
  
  return;
}

void findEmployee(istream& inputFile, ostream& reportFile, ostream& errorFile, const LinkedList<Employee>& employees) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  try {
    // validates ID number
    int IDNumber = stoi(commandLineData.at(1));

    Employee employee = employees.findNode(IDNumber);

    // employee with IDNumber does not exist
    if (employee.getIDNumber() == 0) {
      string msg = "Unable to find employee. No employees with ID number: " + to_string(IDNumber) + ".";
      throw runtime_error(msg);
    }
    // employee with IDNumber exists
    else {
      // outputs information about employee with IDNumber
      reportFile << "RESULTS FOR ID NUMBER " << to_string(IDNumber) << endl;
      reportFile << setw(150) << setfill('-') << "" << endl;
      reportFile << "Name: " << employee.getFirstName() << " " << employee.getLastName() << endl;
      reportFile << "Phone Number: " << employee.getPhoneNumber() << endl;
      reportFile << "Email: " << employee.getEmail() << endl;
      reportFile << "Position: " << employee.getPosition() << " (" << ((employee.getIsFullTime() == 1) ? "Full-Time" : "Part-Time") << ")" << endl;
      reportFile << "Years at Organization: " << employee.getYearsAtOrganization() << endl;
      reportFile << endl << endl << endl;
    }
  }
  catch(invalid_argument& error) {
    errorFile << "Unable to find employee. Invalid ID number." << endl << endl;
  }
  catch (out_of_range& error) {
    errorFile << "Unable to find employee. Invalid ID number." << endl << endl;
  }
  catch (runtime_error& error) {
    errorFile << error.what() << endl << endl;
  }
  
  return;
}

void addStaff(istream& inputFile, ostream& reportFile, ostream& errorFile,
              LinkedList<Volunteer>& volunteers, LinkedList<Employee>& employees) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  try {
    // validates values
    char type = commandLineData.at(1).at(0);
    int IDNumber = stoi(commandLineData.at(2));
    string firstName = commandLineData.at(3);
    string lastName = commandLineData.at(4);
    int age = stoi(commandLineData.at(5));
    string phoneNumber = commandLineData.at(6);
    string email = commandLineData.at(7);
    double yearsAtOrganization = stod(commandLineData.at(8));

    bool isFullTime;
    string position;

    if (type == 'E') {
      string isFullTimeStr = commandLineData.at(9);
      
      if (isFullTimeStr != "0" && isFullTimeStr != "1") {
        string msg = "Error: '" + isFullTimeStr + "' is an invalid full-time status.";
        throw runtime_error(msg);
      }
      else {
        // if isFullTimeStr equals "1", assigns true to isFullTime; else, assigns false to isFullTime
        isFullTime = (isFullTimeStr == "1") ? true : false;
      }

      position = commandLineData.at(10);
    }

    if (type != 'V' && type != 'E') {
      string msg = "Unable to add staff member. '" + string(1, type) + "' is an invalid staff type.";
      throw runtime_error(msg);
    }

    if (IDNumber <= 0) {
      string msg = "Error: " + to_string(IDNumber) + " is an invalid ID number.";
      throw runtime_error(msg);
    }

    if (age < 16) {
      string msg = "Unable to add staff member. " + to_string(age) + " is an invalid age.";
      throw runtime_error(msg);
    }

    if (yearsAtOrganization < 0) {
      string msg = "Unable to add staff member. " + to_string(yearsAtOrganization) + " is an invalid number of years.";
      throw runtime_error(msg);
    }

    if (type == 'V') {
      // creates new Volunteer object, sets values, and adds object to linked list of volunteers 
      Volunteer tempVolunteer;
      tempVolunteer.setIDNumber(IDNumber);
      tempVolunteer.setFirstName(firstName);
      tempVolunteer.setLastName(lastName);
      tempVolunteer.setAge(age);
      tempVolunteer.setPhoneNumber(phoneNumber);
      tempVolunteer.setEmail(email);
      tempVolunteer.setYearsAtOrganization(yearsAtOrganization);
      volunteers.addNode(tempVolunteer);
      
      reportFile << "Successfully added volunteer: " << firstName << " " << lastName << endl << endl << endl << endl;
    }
    else if (type == 'E') {
      // creates new Employee object, sets values, and adds object to linked list of employees
      Employee tempEmployee;
      tempEmployee.setIDNumber(IDNumber);
      tempEmployee.setFirstName(firstName);
      tempEmployee.setLastName(lastName);
      tempEmployee.setAge(age);
      tempEmployee.setPhoneNumber(phoneNumber);
      tempEmployee.setEmail(email);
      tempEmployee.setYearsAtOrganization(yearsAtOrganization);
      tempEmployee.setIsFullTime(isFullTime);
      tempEmployee.setPosition(position);
      employees.addNode(tempEmployee);
      
      reportFile << "Successfully added employee: " << firstName << " " << lastName << endl << endl << endl << endl;
    }

    // updates totals
    if (type == 'V') {
      Volunteer::totalVolunteers++;
    }
    else if (type == 'E') {
      Employee::totalEmployees++;
    }
  }
  catch (invalid_argument& error) {
    errorFile << "Unable to add staff member. " << error.what() << " error." << endl << endl;
  }
  catch (out_of_range& error) {
    errorFile << "Unable to add staff member. " << error.what() << " error." << endl << endl;
  }
  catch (runtime_error& error) {
    errorFile << error.what() << endl << endl;
  }
  
  return;
}

void removeVolunteer(istream& inputFile, ostream& reportFile, ostream& errorFile, LinkedList<Volunteer>& volunteers) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  try {
    // validates ID number
    int IDNumber = stoi(commandLineData.at(1));

    Volunteer volunteer = volunteers.findNode(IDNumber);
    
    // volunteer with IDNumber does not exist
    if (volunteer.getIDNumber() == 0) {
      string msg = "Unable to remove volunteer. No volunteers with ID number: " + to_string(IDNumber) + ".";
      throw runtime_error(msg);
    }
    // volunteer with IDNumber exists
    else {
      volunteers.delNode(IDNumber);
      Volunteer::totalVolunteers--;
      reportFile << "Successfully removed volunteer with ID number: " << IDNumber << endl << endl << endl << endl;
    }
  }
  catch(invalid_argument& error) {
    errorFile << "Unable to remove volunteer. Invalid ID number." << endl << endl;
  }
  catch (out_of_range& error) {
    errorFile << "Unable to remove volunteer. Invalid ID number." << endl << endl;
  }
  catch (runtime_error& error) {
    errorFile << error.what() << endl << endl;
  }
  
  return;
}

void removeEmployee(istream& inputFile, ostream& reportFile, ostream& errorFile, LinkedList<Employee>& employees) {
  vector<string> commandLineData;
  string temp;
  
  // reads data (separated by a comma) in command file line
  while (getline(inputFile, temp, ',')) {
    commandLineData.push_back(temp);
  }

  try {
    // validates ID number
    int IDNumber = stoi(commandLineData.at(1));

    Employee employee = employees.findNode(IDNumber);

    // employee with IDNumber does not exist
    if (employee.getIDNumber() == 0) {
      string msg = "Unable to remove employee. No employees with ID number: " + to_string(IDNumber) + ".";
      throw runtime_error(msg);
    }
    // employee with IDNumber exists
    else {
      employees.delNode(IDNumber);
      Employee::totalEmployees--;
      reportFile << "Successfully removed employee with ID number: " << IDNumber << endl << endl << endl << endl;
    }
  }
  catch (invalid_argument& error) {
    errorFile << "Unable to remove employee. Invalid ID number." << endl << endl;
  }
  catch (out_of_range& error) {
    errorFile << "Unable to remove employee. Invalid ID number." << endl << endl;
  }
  catch (runtime_error& error) {
    errorFile << error.what() << endl << endl;
  }

  return;
}