#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>
class Singleton
{
protected:
    Singleton() = default;
    ~Singleton() = default;

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static T &getInstance()
    {
        static T instance;
        return instance;
    }
};

int main()
{

    cin.get();
    return 0;
}