#include <iostream>
#include <string>
#include "Skill.h"
#include <stdexcept>
#include <numeric>
using namespace std;
// CONSTRUCTORS
Skill::Skill(const std::string &name, unsigned int level)
{
    if (name.empty())
        throw invalid_argument("Tên kĩ năng không thể là một chuỗi rỗng!\n");
    skillName = name;
    skillLevel = level;
}
Skill::Skill(const std::string &name) : Skill(name, 1) {}
Skill::Skill() : Skill("Tốc biến", 1) {}
Skill::Skill(const Skill &skill) : Skill(skill.skillName, skill.skillLevel) {}
// OPERATIONS
// getter
std::string Skill::getSkillName() const noexcept
{
    return this->skillName;
}
unsigned int Skill::getSkillLevel() const noexcept
{
    return this->skillLevel;
}
// setter
void Skill::setSkillName(const std::string newName)
{
    if (newName.empty())
        throw invalid_argument("Tên kĩ năng không thể là một chuỗi rỗng!\n");

    skillName = newName;
}
void Skill::setSkillLevel(unsigned int newLevel)
{
    skillLevel = newLevel;
}
// input
void Skill::inputSkill()
{
    string name;
    unsigned int level;
    cout << "Mời nhập tên cho kĩ năng: ";
    getline(cin, name);
    setSkillName(name);
    cout << "\nMời nhập cấp độ cần thiết cho kĩ năng: ";
    cin >> level;
    setSkillLevel(level);
    cin.ignore();
}
// ouput
void Skill::outputSkill() const noexcept
{
    cout << "Tên kĩ năng: " << skillName << '\n';
    cout << "Cấp độ yêu cầu: " << skillLevel << '\n';
}
// DESTRUCTOR
Skill::~Skill()
{
    cout << "Đã xoá kĩ năng thành công!\n";
}