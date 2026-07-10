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
void Hero::setHeroName(const std::string &newName) {}
void Hero::setHeroHealth(unsigned int hp) {}
void Hero::setHeroMana(unsigned int mana) {}
void Hero::setHeroLevel(unsigned int level) {}
// input
void Hero::inputHero() {}
// output
void Hero::outputHero() const noexcept {}
// others
void Hero::printEligibleSkills() const noexcept {}
void Hero::removeSkills() {}
// DESTRUCTOR
Hero::~Hero() {}
