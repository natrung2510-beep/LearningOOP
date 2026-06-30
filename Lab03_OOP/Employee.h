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

    static const inline std::string positions[4] = {"Nhan vien", "Quan ly", "Truong phong", "Truong ban quan ly"};
    static constexpr float salaryMultipliers[4] = {1.0f, 1.5f, 2.25f, 4.0f};
    static constexpr int terms[3] = {365, 730, 1460};

    bool checkValidJobTitle() const;
    bool checkValidSalaryCoefficient() const;
    void validateInformation();

public:
    // CONSTRUCTORS
    Employee(const std::string &fullName, int workDays, const std::string &jobTitle, const std::string &workName, float salaryCoefficient);
    Employee(const std::string &fullName, int workDays);
    Employee();
    Employee(const Employee &other); // chức danh , hs lương, số ngày làm việc

    // DESTRUCTOR
    ~Employee();
    // OPERATIONS
    // getter
    std::string getfullName() const noexcept;
    int getWorkDays() const;
    std::string getJobTitle() const noexcept;
    std::string getWorkName() const noexcept;
    float getSalaryCoefficient() const noexcept;

    // setter
    void setFullName();
    void setWorkDays();
    void setJobTitle();
    void setWorkName();
    void setSalaryCoefficient();

    // other
    void inputEmployee();
    void outputEmployee() const;
};