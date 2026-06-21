#pragma once
#include <vector>
#include <string>
#include "Student.h"
using namespace std;

class Class
{
private:
    vector<Student> members;

public:
    void addStudent(const string &newName, const string &newNumber, float newPoint);
    void removeStudent(const string &name);
    void sortStudent_DescendingAveragePoint();
    void outputClass() const;
    void inputClass_File(); // "LopHoc.txt"
};