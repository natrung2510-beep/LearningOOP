#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Class.h"
using namespace std;
void mergeSort_Helper(vector<Student> &members, int n, vector<Student> &temp, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort_Helper(members, n, temp, low, mid);
    mergeSort_Helper(members, n, temp, mid + 1, high);

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
        temp[k++] = (members[i].getAveragePoint() >= members[j].getAveragePoint()) ? members[i++] : members[j++];
    while (i <= mid)
        temp[k++] = members[i++];
    while (j <= high)
        temp[k++] = members[j++];

    for (int p = low; p <= high; p++)
        members[p] = temp[p];
}
void mergeSort(vector<Student> &members)
{
    int n = members.size();
    vector<Student> temp(n);

    mergeSort_Helper(members, n, temp, 0, n - 1);
}
void Class::addStudent(string newName, string newNumber, float newPoint)
{
    bool isFound = false;

    for (const auto &i : members)
    {
        if (i.getName() == newName)
        {
            isFound = true;
            break;
        }
    }

    if (isFound)
        cout << "The student is already in the class!\n";
    else
    {
        Student newStudent;
        newStudent.setName(newName);
        newStudent.setNumber(newNumber);
        newStudent.setAveragePoint(newPoint);
        newStudent.checkValidInformation();
        members.push_back(newStudent);
        cout << "Successfully added!\n";
    }
}

void Class::removeStudent(string name)
{
    bool isFound = false;
    int target = 0;
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i].getName() == name)
        {
            target = i;
            isFound = true;
            break;
        }
    }

    if (isFound)
    {
        members.erase(members.begin() + target);
        cout << "Successfully removed!\n";
    }
    else
        cout << "The student is not in  the class!\n";
}

void Class::sortStudent_DescendingAveragePoint()
{
    mergeSort(members);
}

void Class::outputClass()
{
    for (const auto &i : members)
        i.outputInformation();
}

void Class::inputClass_File()
{
    fstream myFile;
    myFile.open("LopHoc.txt");
    if (myFile.fail())
        return;
    int classSize;
    myFile >> classSize;
    myFile.ignore();
    while (classSize--)
    {
        Student student;
        string fullName;
        string phoneNumber;
        float averagePoint;

        getline(myFile, fullName);
        myFile >> phoneNumber;
        myFile.ignore();
        myFile >> averagePoint;
        myFile.ignore();

        student.setAveragePoint(averagePoint);
        student.setName(fullName);
        student.setNumber(phoneNumber);

        members.push_back(student);
    }
}