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

istream &operator>>(istream &inDevice, Trung &tr)
{
    int a;
    string ID, HT;
    inDevice >> a >> ID;
    inDevice.ignore();
    getline(inDevice, HT);
    tr.set(a, ID, HT);
    return inDevice;
}
ostream &operator<<(ostream &outDevice, Trung &tr)
{
    outDevice << "Age: " << tr.getAge() << '\n';
    outDevice << "Id: " << tr.getId() << '\n';
    outDevice << "HomeTown: " << tr.getHomeTown() << '\n';
    return outDevice;
}
int main()
{
    Trung *tr = new Trung();
    if (tr)
    {
        // tr->input(cin);
        // tr->output(cout);
        cin >> *tr;
        cout << *tr;
        delete tr;
        tr = nullptr;
    }

    cin.get();
    return 0;
}