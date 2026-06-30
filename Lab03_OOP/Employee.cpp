#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

// Helper function
bool Employee::checkValidJobTitle() const
{
    if (jobTitle != positions[0] && jobTitle != positions[1] && jobTitle != positions[2] && jobTitle != positions[3])
        return false;
    if (workDays < 0)
        return false;
    if (workDays <= terms[0] && jobTitle != positions[0])
        return false;
    if (workDays > terms[0] && workDays <= terms[1] && jobTitle != positions[1])
        return false;
    if (workDays > terms[1] && workDays <= terms[2] && jobTitle != positions[2])
        return false;
    if (workDays > terms[2] && jobTitle != positions[3])
        return false;

    return true;
}
bool Employee::checkValidSalaryCoefficient() const
{
    if (salaryCoefficient < 0)
        return false;
    for (int i = 0; i < 4; i++)
    {
        if (jobTitle == positions[i] && salaryCoefficient != salaryMultipliers[i])
            return false;
    }
    return true;
}
void Employee::validateInformation()
{
    if (workDays < 0)
        workDays = 0;

    if (!checkValidJobTitle())
    {
        if (workDays <= terms[0])
            jobTitle = positions[0];
        else if (workDays <= terms[1])
            jobTitle = positions[1];
        else if (workDays <= terms[2])
            jobTitle = positions[2];
        else
            jobTitle = positions[3];
    }

    int target = 0;
    for (int i = 0; i < 4; i++)
    {
        if (jobTitle == positions[i])
        {
            target = i;
            break;
        }
    }
    if (!checkValidSalaryCoefficient())
        salaryCoefficient = salaryMultipliers[target];
}
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
