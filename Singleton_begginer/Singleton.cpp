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

class WaveManager : public Singleton<WaveManager>
{
    friend class Singleton<WaveManager>;

private:
    WaveManager() {};
    ~WaveManager() {};

    int waveCurrent = 1;
    int monstersAlive = 0;
};
class EconomyManager : public Singleton<EconomyManager>
{
    friend class Singleton<EconomyManager>;
};
int main()
{

    cin.get();
    return 0;
}