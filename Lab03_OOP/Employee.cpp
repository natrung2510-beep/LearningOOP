#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

// Helper function

// CONSTRUCTORS
Employee::Employee(const std::string &fullName, int workDays, const std::string &jobTitle, const std::string &workName, float salaryCoefficient) {}
Employee::Employee(const std::string &fullName, int workDays) : Employee(fullName, workDays) {}
Employee::Employee(const Employee &other) {} // chức danh , hs lương, số ngày làm việc

// DESTRUCTOR
Employee::~Employee() {}
// OPERATIONS
// getter
std::string Employee::getfullName() const noexcept {}
int Employee::getWorkDays() const {}
std::string Employee::getJobTitle() const noexcept {}
std::string Employee::getWorkName() const noexcept {}
float Employee::getSalaryCoefficient() const noexcept {}

// setter
void Employee::setFullName(const string &newFullName) {}
void Employee::setWorkDays(int newVal) {}
void Employee::setJobTitle(const string &newTitle) {}
void Employee::setWorkName(const string &newName) {}
void Employee::setSalaryCoefficient(float newVal) {}

// other
void Employee::inputEmployee() {}
void Employee::outputEmployee() const {}
