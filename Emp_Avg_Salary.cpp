#include <iostream>
#include <vector>
#include <fstream>
#include <string>
//#include <nlohmann/json.hpp> 
//#include <tinyxml2.h>
#include "json.hpp"  //Manually downloaded json library
#include "tinyxml2.h"  //Manually downloaded  XMl library
#include <algorithm>

using json = nlohmann::json;
using namespace std;
using namespace tinyxml2;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

// Function to parse JSON
vector<Employee> parseJSON(const string& filename) {
    ifstream file(filename);
    json j;
    file >> j;
    vector<Employee> employees;
    for (const auto& item : j["employees"]) {
        employees.push_back({
            item["id"].get<int>(),
            item["name"].get<string>(),
            item["department"].get<string>(),
            item["salary"].get<double>()
        });
    }
    return employees;
}

// Function to parse XML
vector<Employee> parseXML(const string& filename) {
    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    vector<Employee> employees;
    
    XMLElement* root = doc.RootElement();
    XMLElement* employeeElement = root->FirstChildElement("employee");
    
    while (employeeElement) {
        Employee emp;
        emp.id = atoi(employeeElement->FirstChildElement("id")->GetText());
        emp.name = employeeElement->FirstChildElement("name")->GetText();
        emp.department = employeeElement->FirstChildElement("department")->GetText();
        emp.salary = atof(employeeElement->FirstChildElement("salary")->GetText());
        
        employees.push_back(emp);
        employeeElement = employeeElement->NextSiblingElement("employee");
    }
    return employees;
}

// Function to calculate average salary
double calculateAverageSalary(const vector<Employee>& employees) {
    double totalSalary = 0;
    for (const auto& emp : employees) {
        totalSalary += emp.salary;
    }
    return totalSalary / employees.size();
}

// Function to find the highest paid employee
Employee findHighestPaidEmployee(const vector<Employee>& employees) {
    return *max_element(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.salary < b.salary;
    });
}

// Function to print employee list
void printEmployees(const vector<Employee>& employees) {
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Department: " << emp.department << ", Salary: " << emp.salary << endl;
    }
}

// Function to sort employees by ID
void sortEmployeesByID(vector<Employee>& employees) {
    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.id < b.id;
    });
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <file>" << endl;
        return 1;
    }

    string filename = argv[1];
    vector<Employee> employees;

    if (filename.substr(filename.find_last_of(".") + 1) == "json") {
        employees = parseJSON(filename);
    } else if (filename.substr(filename.find_last_of(".") + 1) == "xml") {
        employees = parseXML(filename);
    } else {
        cerr << "Unsupported file format. File format expected is either json or xml" << endl;
        return 1;
    }

    // Calculate average salary
    double avgSalary = calculateAverageSalary(employees);
    cout << "Average Salary: " << avgSalary << endl;

    // Find and print the highest paid employee
    Employee highestPaid = findHighestPaidEmployee(employees);
    cout << "Highest Paid Employee: " << endl;
    cout << "ID: " << highestPaid.id << ", Name: " << highestPaid.name << ", Department: " << highestPaid.department << ", Salary: " << highestPaid.salary << endl;

    // Sort and print the employee list
    sortEmployeesByID(employees);
    cout << "Sorted Employees by ID: " << endl;
    printEmployees(employees);

    return 0;
}
