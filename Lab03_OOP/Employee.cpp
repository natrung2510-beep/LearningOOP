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

    this->workName = jobTitle + " " + fullName;
}

// CONSTRUCTORS
Employee::Employee() : fullName("Nguyen Van A"), workDays(0), jobTitle(positions[0]), workName(positions[0] + " " + fullName), salaryCoefficient(salaryMultipliers[0]) {}
Employee::Employee(const std::string &fullName, int workDays, const std::string &jobTitle, const std::string &workName, float salaryCoefficient) : fullName(fullName), workDays(workDays), jobTitle(jobTitle), workName(workName), salaryCoefficient(salaryCoefficient)
{
    validateInformation();
    cout << "Tao thanh cong doi tuong moi!\n";
}
Employee::Employee(const std::string &fullName, int workDays) : Employee(fullName, workDays, positions[0], positions[0] + " " + fullName, salaryMultipliers[0]) {}
Employee::Employee(const Employee &other) : Employee("Nguyen Van A", other.workDays, other.jobTitle, other.jobTitle + " " + "Nguyen Van A", other.salaryCoefficient) {}

// DESTRUCTOR
Employee::~Employee()
{
    cout << "Huy doi tuong thanh cong!\n";
}
// OPERATIONS
// getter
std::string Employee::getfullName() const noexcept
{
    return fullName;
}
int Employee::getWorkDays() const
{
    return workDays;
}
std::string Employee::getJobTitle() const noexcept
{
    return jobTitle;
}
std::string Employee::getWorkName() const noexcept
{
    return workName;
}
float Employee::getSalaryCoefficient() const noexcept
{
    return salaryCoefficient;
}

// setter
void Employee::setFullName(const string &newFullName)
{
    if (newFullName.empty())
    {
        fullName = "Nguyen Van A";
        return;
    }

    fullName = newFullName;
    validateInformation();
}
void Employee::setWorkDays(int newVal)
{
    if (newVal < 0)
    {
        workDays = 0;
        return;
    }

    workDays = newVal;
    validateInformation();
}
void Employee::setJobTitle(const string &newTitle)
{
    bool isFound = false;
    for (int i = 0; i < 4; i++)
    {
        if (positions[i] == newTitle)
        {
            isFound = true;
            break;
        }
    }
    if (newTitle.empty() || isFound)
        jobTitle = positions[0];
    else
        jobTitle = newTitle;
    validateInformation();
}
void Employee::setWorkName(const string &newName) {}
void Employee::setSalaryCoefficient(float newVal) {}

// other
void Employee::inputEmployee() {}
void Employee::outputEmployee() const {}
