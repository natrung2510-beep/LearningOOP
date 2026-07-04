#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>
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

public:
    void startNextWave(int spawnCounts)
    {
        monstersAlive = spawnCounts;
        cout << "Wave " << waveCurrent++ << " bắt đầu với " << spawnCounts << " quái\n";
    }
    void monsterDefeated()
    {
        cout << "Còn lại :" << ((monstersAlive > 0) ? --monstersAlive : 0) << " quái\n";
    }
    int getMonstersAlive() const noexcept
    {
        return monstersAlive;
    }
};
class EconomyManager : public Singleton<EconomyManager>
{
    friend class Singleton<EconomyManager>;

private:
    EconomyManager() {}
    ~EconomyManager() {}
    int playerGold = 100;

public:
    void earnGold(int amount)
    {
        playerGold += amount;
        cout << "Gold : " << playerGold << '\n';
    }
    bool buyTower(int cost)
    {
        if (cost <= playerGold)
        {
            playerGold -= cost;
            cout << "Mua thanh cong! Con lai: " << playerGold << '\n';
            return true;
        }
        else
        {
            cout << "Khong du tien!\n";
            return false;
        }
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "--- GAME PHONG THU THANH (TOWER DEFENSE) START ---\n\n";
    WaveManager &waveMng = WaveManager::getInstance();
    auto &ecoMng = EconomyManager::getInstance();

    waveMng.startNextWave(3);
    cout << "\n--- CHUYEN SANG WAVE TIEP THEO ---\n";

    ecoMng.buyTower(70);

    waveMng.monsterDefeated();
    ecoMng.earnGold(30);

    waveMng.monsterDefeated();
    ecoMng.earnGold(30);

    return 0;
}