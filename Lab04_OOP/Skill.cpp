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
void Skill::setkillName(const std::string newName)
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
void Skill::inputSkill() {}
// ouput
void Skill::outputSkill() const noexcept {}
// DESTRUCTOR
Skill::~Skill() {}