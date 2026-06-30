#pragma once
#include <string>

class Employee
{
private:
    std::string fullName;
    int workDays;
    std::string jobTitle;
    std::string workName;
    float salaryCoefficient;

public:
    // CONSTRUCTORS
    Employee(const std::string &fullName, int workDays, const std::string &jobTitle, const std::string &workName, float salaryCoefficient);
    Employee(const std::string &fullName, int workDays);
    Employee();
    Employee(const Employee &other); // chức danh , hs lương, số ngày làm việc
};