#include <iostream>
#include "Student.h"
#include <string>
#include <stdexcept>
#include <limits>
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

bool Student::checkValidInformation() const
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
void Student::validateInformation() const
{
    string errorList = "";
    bool checkAveragePoint = MIN_POINT <= average_point && average_point <= MAX_POINT;
    if (!checkAveragePoint)
        errorList += "-Average point is out of range from 0 to 10!\n";

    bool checkNameLength = name.size() <= MAX_NAME_LENGTH;
    if (!checkNameLength)
        errorList += "-Length of name exceeds 20 characters!\n";

    bool checkCharValidity = true;

    for (char c : name)
    {
        if (c == ' ')
            continue;

        if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z'))
        {
            checkCharValidity = false;
            break;
        }
    }

    if (!checkCharValidity)
        errorList += "-Detect invalid characters!\n";

    int numberLength = number.size();
    bool checkNumberLength = MIN_NUMBER_LENGTH <= numberLength && numberLength <= MAX_NUMBER_LENGTH;
    if (!checkNumberLength)
        errorList += "-Length of number is out range from 9 to 11 digits!\n";

    bool checkDigitValidity = true;
    for (char c : number)
    {
        if (!('0' <= c && c <= '9'))
        {
            checkDigitValidity = false;
            break;
        }
    }
    if (!checkDigitValidity)
        errorList += "-Detect invalid characters!\n";
    if (!errorList.empty())
        throw invalid_argument("Invalid infomation includes:\n" + errorList);
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
    bool success = false;
    do
    {
        try
        {
            string name, number;
            float point;
            getline(inDevice >> ws, name);
            inDevice >> number >> point;
            inDevice.ignore();

            if (inDevice.fail())
            {
                inDevice.clear();
                inDevice.ignore(numeric_limits<streamsize>::max(), '\n');

                throw invalid_argument("-Point must be a nummber!");
            }
            Student input(name, number, point);

            s = input;
            success = true;
        }
        catch (const exception &e)
        {
            cout << "---DATA ENTRY ERROR---\n";
            cout << e.what() << '\n'
                 << "Please enter again...\n";
        }

    } while (!success);
    return inDevice;
}
ostream &operator<<(ostream &outDevice, const Student &s)
{
    cout << "Full name: " << s.name << '\n';
    cout << "Phone number: " << s.number << '\n';
    cout << "Average point: " << s.average_point << '\n';
    return outDevice;
}
bool Student::operator==(const Student &other) const
{
    return this->name == other.name;
}
bool Student::operator<(const Student &other) const
{
    return this->average_point < other.average_point;
}