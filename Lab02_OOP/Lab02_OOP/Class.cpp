#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Class.h"
using namespace std;
static void mergeSort_Helper(vector<Student> &members, vector<Student> &temp, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort_Helper(members, temp, low, mid);
    mergeSort_Helper(members, temp, mid + 1, high);

    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
        temp[k++] = (members[j] < members[i]) ? members[i++] : members[j++];
    while (i <= mid)
        temp[k++] = members[i++];
    while (j <= high)
        temp[k++] = members[j++];

    for (int p = low; p <= high; p++)
        members[p] = temp[p];
}
static void mergeSort(vector<Student> &members)
{
    int n = members.size();
    vector<Student> temp(n);

    mergeSort_Helper(members, temp, 0, n - 1);
}
void Class::addStudent(const string &newName, const string &newNumber, float newPoint)
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
        Student newStudent(newName, newNumber, newPoint);
        members.push_back(newStudent);
        cout << "Successfully added!\n";
    }
}

void Class::removeStudent(const string &name)
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
        cout << "The student is not in the class!\n";
}

void Class::sortStudent_DescendingAveragePoint()
{
    mergeSort(members);
}

void Class::outputClass() const
{
    for (const auto &i : members)
        cout << i;
}

void Class::inputClass_File()
{
    fstream myFile;
    myFile.open("LopHoc.txt");
    if (myFile.fail())
        return;
    int classSize;
    myFile >> classSize;
    while (classSize--)
    {
        Student student;
        myFile >> student;
        members.push_back(student);
    }
}