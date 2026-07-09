#pragma once
#include <string>
#include <vector>
#include "Skill.h"
class Hero
{
private:
    std::string heroName;
    unsigned int heroHealth;
    unsigned int heroMana;
    unsigned int heroLevel;
    std::vector<Skill *> skillList;
};