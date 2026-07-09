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
    unsigned int heroLevel = 1;
    std::vector<Skill *> skillList;

    static constexpr char *heroName_default = "Valhein";
    static constexpr unsigned int hp_default = 3000;
    static constexpr unsigned int mana_default = 500;

public:
    // CONSTRUCTORs
    Hero(const std::string &name, unsigned int hp, unsigned int mana, unsigned int level);
    Hero(const std::string &name, unsigned int hp, unsigned int mana);
    Hero(const std::string &name, unsigned int level);
    Hero(const std::string &name);
    Hero();
    Hero(const Hero &other);

    // OPERATIONs

    // DESTRUCTOR
};