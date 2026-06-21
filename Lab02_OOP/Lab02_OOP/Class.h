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
    void addStudent(string newName, string newNumber, float newPoint);
    void removeStudent(string name);
    void sortStudent_DescendingAveragePoint();
    void outputClass();
    void inputClass_File(); // "LopHoc.txt"
};