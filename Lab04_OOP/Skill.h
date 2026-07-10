#pragma once
#include <string>
#include <vector>

class Skill
{
private:
    std::string skillName;
    unsigned int skillLevel;

public:
    // CONSTRUCTORS
    Skill(const std::string &name, unsigned int level);
    Skill(const std::string &name);
    Skill();
    Skill(const Skill &skill);
    // OPERATIONS
    // getter
    std::string getSkillName() const noexcept;
    unsigned int getSkillLevel() const noexcept;
    // setter
    void setSkillName(const std::string newName);
    void setSkillLevel(unsigned int newLevel);
    // input
    void inputSkill();
    // ouput
    void outputSkill() const noexcept;
    // DESTRUCTOR
    ~Skill();
};