#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

// void Student::inputInformation()
// {
//     cout << "Please enter your full name: ";
//     getline(cin, name);
//     cout << "Please enter your phone number: ";
//     cin >> number;
//     cin.ignore();
//     cout << "Please enter your average point: ";
//     cin >> average_point;
//     cin.ignore();
// }

// void Student::outputInformation() const
// {
//     cout << "Full name: " << name << '\n';
//     cout << "Phone number: " << number << '\n';
//     cout << "Average point: " << average_point << '\n';
// }

bool Student::checkValidInformation()
{
    bool checkAveragePoint = MIN_POINT <= average_point && average_point <= MAX_POINT;

    bool checkName = name.size() <= MAX_NAME_LENGTH;
    for (char c : name)
    {
        if (c == ' ')
            continue;

        if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z'))
        {
            checkName = false;
            break;
        }
    }

    int numberLength = number.size();
    bool checkNumber = MIN_NUMBER_LENGTH <= numberLength && numberLength <= MAX_NUMBER_LENGTH;
    for (char c : number)
    {
        if (!('0' <= c && c <= '9'))
        {
            checkNumber = false;
            break;
        }
    }
    return checkAveragePoint && checkName && checkNumber;
}

string Student::getName() const
{
    return name;
}
string Student::getNumber() const
{
    return number;
}
float Student::getAveragePoint() const
{
    return average_point;
}

void Student::setName(string newName)
{
    name = newName;
}
void Student::setNumber(string newNumber)
{
    number = newNumber;
}
void Student::setAveragePoint(float newPoint)
{
    average_point = newPoint;
}
istream &operator>>(istream &inDevice, Student &s)
{
    bool isValid = false;
    do
    {
        getline(inDevice, s.name);
        inDevice >> s.number >> s.average_point;
        inDevice.ignore();

        isValid = s.checkValidInformation();
        if (!isValid)
            cout << "The information is invalid! Please enter again....\n";
    } while (isValid);
    return inDevice;
}
ostream &operator<<(ostream &outDevice, const Student &s)
{
    cout << "Full name: " << s.name << '\n';
    cout << "Phone number: " << s.number << '\n';
    cout << "Average point: " << s.average_point << '\n';
    return outDevice;
}