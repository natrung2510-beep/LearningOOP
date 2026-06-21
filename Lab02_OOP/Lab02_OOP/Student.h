#pragma once
#include <string>
using namespace std;
class Student
{
private:
    string name;
    string number;
    float average_point;

    static const int MAX_NAME_LENGTH = 20;
    static constexpr float MIN_POINT = 0.0f;
    static constexpr float MAX_POINT = 10.0f;
    static const int MIN_NUMBER_LENGTH = 9;
    static const int MAX_NUMBER_LENGTH = 11;

public:
    void inputInformation();
    void outputInformation() const;
    void checkValidInformation();

    string getName() const;
    string getNumber() const;
    float getAveragePoint() const;

    void setName(string newName);
    void setNumber(string newNumber);
    void setAveragePoint(float newPoint);
};