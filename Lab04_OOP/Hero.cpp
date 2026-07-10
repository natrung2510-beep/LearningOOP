#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <numeric>
#include "Hero.h"
using namespace std;

// CONSTRUCTORs
Hero::Hero(const std::string &name, unsigned int hp, unsigned int mana, unsigned int level, const std::vector<Skill *> &skills)
{
    if (name.empty())
        throw invalid_argument("Tên của Hero không thể là một chuỗi rỗng!\n");
    heroName = name;
    heroHealth = hp;
    heroMana = mana;
    heroLevel = level;
    for (const auto &i : skills)
    {
        if (!i)
            continue;
        this->skillList.push_back(new Skill(*i));
    }
}
Hero::Hero(const std::string &name, unsigned int hp, unsigned int mana) : Hero(name, hp, mana, 1) {}
Hero::Hero() : Hero(heroName_default, hp_default, mana_default) {}
Hero::Hero(const Hero &other) : Hero(other.heroName, other.heroHealth, other.heroMana, other.heroLevel, other.skillList) {}

// OPERATIONs
// getter
std::string Hero::getHeroName() const noexcept
{
    return heroName;
}
unsigned int Hero::getHeroHealth() const noexcept
{
    return heroHealth;
}
unsigned int Hero::getHeroMana() const noexcept
{
    return heroMana;
}
unsigned int Hero::getHeroLevel() const noexcept
{
    return heroLevel;
}
// setter
void Hero::setHeroName(const std::string &newName)
{
    if (newName.empty())
        throw invalid_argument("Tên Hero không thể là chuỗi rỗng!\n");

    heroName = newName;
}
void Hero::setHeroHealth(unsigned int hp)
{
    heroHealth = hp;
}
void Hero::setHeroMana(unsigned int mana)
{
    heroMana = mana;
}
void Hero::setHeroLevel(unsigned int level)
{
    heroLevel = level;
}
// input
void Hero::inputHero()
{
    string name;
    cout << "Mời nhập tên của Hero: ";
    getline(cin, name);
    setHeroName(name);

    unsigned int hp;
    cout << "\nMời nhập điểm sinh lực của Hero: ";
    cin >> hp;
    cin.ignore();
    setHeroHealth(hp);

    unsigned int mana;
    cout << "\nMời nhập mana của Hero: ";
    cin >> mana;
    cin.ignore();
    setHeroMana(mana);

    unsigned int level;
    cout << "\nMời nhập cấp độ của Hero: ";
    cin >> level;
    cin.ignore();
    setHeroLevel(level);

    int n;
    cout << "\nMời nhập số kĩ năng bạn muốn Hero học: ";
    cin >> n;
    cin.ignore();
    if (n < 0)
        n = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Mời nhập kĩ năng thứ " << i + 1 << '.';
        try
        {
            Skill tempSkill;
            tempSkill.inputSkill();
            cin.ignore();
            this->skillList.push_back(new Skill(tempSkill));
        }
        catch (const invalid_argument &e)
        {
            cerr << "LỖI: " << e.what();
            cerr << "Vui lòng nhập lại thông tin kĩ năng!\n";
            i--;
        }
        catch (const exception &e)
        {
            cerr << "LỖI HỆ THỐNG : " << e.what() << '\n';
            cerr << "Vui lòng nhập lại thông tin kĩ năng!\n";
            i--;
        }
        catch (...)
        {
            cerr << "LỖI KHÔNG XÁC ĐỊNH!\n";
            cerr << "Vui lòng nhập lại thông tin kĩ năng!\n";
            i--;
        }
    }
}
// output
void Hero::outputHero() const noexcept
{
    cout << "--- THÔNG TIN HERO ---\n";
    cout << "Tên Hero: " << this->heroName << "\n";
    cout << "Sinh lực: " << this->heroHealth << "\n";
    cout << "Mana: " << this->heroMana << "\n";
    cout << "Cấp độ: " << this->heroLevel << "\n";

    cout << "Danh sách kĩ năng:\n";
    if (this->skillList.empty())
    {
        cout << "(Trống - Chưa học kĩ năng nào)\n";
    }
    else
    {
        int count = 1;
        for (const auto &skillPtr : this->skillList)
        {
            if (skillPtr)
            {
                cout << "  + Kĩ năng " << count++ << ":\n";
                skillPtr->outputSkill();
                cout << "\n";
            }
        }
    }
}
// others
void Hero::printEligibleSkills() const noexcept
{
}
void Hero::removeSkills()
{
    int size = this->skillList.size();
    if (!size)
    {
        cout << "Danh sách kĩ năng trống! Hero chưa học được kĩ năng nào!\n";
        return;
    }
    int n;
    cout << "Nhập số lượng kĩ năng bạn muốn loại bỏ: ";
    cin >> n;
    cin.ignore();
    if (n < 0)
        n = 0;
    if (n > size)
        n = size;

    for (int i = 0; i < n; i++)
    {
        auto *skillPtr = this->skillList.back();
        if (skillPtr)
            delete skillPtr;
        this->skillList.pop_back();
    }
}
// DESTRUCTOR
Hero::~Hero()
{
    for (const auto &i : this->skillList)
    {
        if (!i)
            continue;

        delete i;
    }
}
