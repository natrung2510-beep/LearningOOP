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

    static constexpr float employee_Coefficient = 1.0f;
    static constexpr float manager_Coefficient = 1.5f;
    static constexpr float departmentManager_Coefficient = 2.25f;
    static constexpr float headOfManager_Coefficient = 4.0f;

public:
    // CONSTRUCTORS
    Employee(const std::string &fullName, int workDays, const std::string &jobTitle, const std::string &workName, float salaryCoefficient);
    Employee(const std::string &fullName, int workDays);
    Employee();
    Employee(const Employee &other); // chức danh , hs lương, số ngày làm việc

    // DESTRUCTOR
    ~Employee();
    // OPERATIONS
};