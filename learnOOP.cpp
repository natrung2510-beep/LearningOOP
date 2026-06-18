#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

class Trung
{
private:
    int age;
    string id;
    string homeTown;

public:
    void set(int x, string str, string place)
    {
        age = x;
        id = str;
        homeTown = place;
    }

    int getAge() const
    {
        return age;
    }

    string getId() const
    {
        return id;
    }

    string getHomeTown() const
    {
        return homeTown;
    }

    void input(istream &inDevice)
    {
        int x;
        string str;
        string place;
        inDevice >> x >> str;
        inDevice.ignore();
        getline(inDevice, place);
        set(x, str, place);
    }

    void output(ostream &outDevice)
    {
        outDevice << "Age: " << getAge() << '\n';
        outDevice << "Id: " << getId() << '\n';
        outDevice << "HomeTown: " << getHomeTown() << '\n';
    }
};

int main()
{
    Trung *tr = new Trung();
    if (tr)
    {
        tr->input(cin);
        tr->output(cout);
        delete tr;
        tr = nullptr;
    }

    cin.get();
    return 0;
}