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
    static inline std::vector<Skill> globalSkillPool = {
        // --- NHÓM KỸ NĂNG CƠ BẢN (Cấp 1 - Cấp 3) ---
        Skill("Tốc biến", 1),
        Skill("Chuyến săn mạo hiểm", 1),
        Skill("Hồi máu", 2),
        Skill("Thanh tẩy", 3),

        // --- NHÓM KỸ NĂNG KHỐNG CHẾ & CHIẾN THUẬT (Cấp 4 - Cấp 8) ---
        Skill("Lời nguyền tử thần", 4),
        Skill("Trừng trị", 5),
        Skill("Gió lốc", 6),
        Skill("Lá chắn ma thuật", 7),
        Skill("Ám ảnh kinh hoàng", 8),

        // --- NHÓM CHIÊU CUỐI ULTIMATE (Cấp 10 - Cấp 12) ---
        Skill("Bão đạn", 10),
        Skill("Ma trận ảo ảnh", 11),
        Skill("Thiên thạch hủy diệt", 12)};

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
    void printEligibleSkills(const std::vector<Skill> &skillPool) const noexcept;
    void removeSkills();
    // DESTRUCTOR
    ~Hero();
};