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
    // Constructors setup
    Trung() : age(0), id("00000000"), homeTown("Undefined") {}
    Trung(int a, string ID, string HT) : age(a), id(ID), homeTown(HT)
    {
        if (this->age < 0)
            this->age = 0;

        if (this->id.length() != 8)
            this->id = "00000000";

        if (this->homeTown == "")
            this->homeTown = "Undefined";
    }
    Trung(string ID, string HT) : Trung(19, ID, HT) {}

    // Functions
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
    ~Trung() {}
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
    Trung *tr1 = new Trung("12345678", "BD");
    if (tr)
    {
        // tr->input(cin);
        // tr->output(cout);
        cin >> *tr;
        cout << *tr;
        cout << *tr1;
        delete tr;
        tr = nullptr;
        delete tr1;
        tr1 = nullptr;
    }

    cin.get();
    return 0;
}