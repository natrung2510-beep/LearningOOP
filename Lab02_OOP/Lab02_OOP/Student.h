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
    Student(const string &name, const string &number, float point)
    {
        validateInformation();
        this->name = name;
        this->number = number;
        this->average_point = point;
    }
    Student() : Student("", "000000000", 0.0) {}
    // void inputInformation();
    // void outputInformation() const;
    friend istream &operator>>(istream &inDevice, Student &s);
    friend ostream &operator<<(ostream &outDevice, const Student &s);

    bool checkValidInformation() const;
    void validateInformation() const;
    string getName() const;
    string getNumber() const;
    float getAveragePoint() const;

    void setName(string newName);
    void setNumber(string newNumber);
    void setAveragePoint(float newPoint);

    bool operator==(const Student &other) const;
    bool operator<(const Student &other) const;

    ~Student() {}
};