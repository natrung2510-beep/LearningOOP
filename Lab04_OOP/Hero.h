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

    static constexpr const char *heroName_default = "Valhein";
    static constexpr unsigned int hp_default = 3000;
    static constexpr unsigned int mana_default = 500;

public:
    // CONSTRUCTORs
    Hero(const std::string &name, unsigned int hp, unsigned int mana, unsigned int level, const std::vector<Skill *> &skills = {});
    Hero(const std::string &name, unsigned int hp, unsigned int mana);
    Hero();
    Hero(const Hero &other);

    // OPERATIONs
    // getter
    std::string getHeroName() const noexcept;
    unsigned int getHeroHealth() const noexcept;
    unsigned int getHeroMana() const noexcept;
    unsigned int getHeroLevel() const noexcept;
    // setter
    void setHeroName(const std::string &newName);
    void setHeroHealth(unsigned int hp);
    void setHeroMana(unsigned int mana);
    void setHeroLevel(unsigned int level);
    // input
    void inputHero();
    // output
    void outputHero() const noexcept;
    // others
    void printEligibleSkills() const noexcept;
    void removeSkills();
    // DESTRUCTOR
    ~Hero();
};