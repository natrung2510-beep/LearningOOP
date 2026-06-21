#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

int main()
{
    Student A;
    A.inputInformation();
    A.outputInformation();
    A.checkValidInformation();

    return 0;
}