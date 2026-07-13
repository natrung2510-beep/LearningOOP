#include <iostream>
#include "Hero.h"
#include "Skill.h"

using namespace std;

int main()
{
    cout << "========== KHỞI ĐỘNG HỆ THỐNG GAME ==========\n\n";

    cout << "[HỆ THỐNG] Tạo vị tướng thứ nhất...\n";
    Hero hero1;
    hero1.inputHero();
    hero1.outputHero();

    cout << "\n=============================================\n\n";

    cout << "[HỆ THỐNG] Tạo vị tướng thứ hai (cấp độ 10)...\n";
    Hero hero2("Zuka", 3500, 400);
    hero2.setHeroLevel(10);

    cout << "\n[HỆ THỐNG] Kiểm tra Bể chứa kĩ năng của thế giới game:\n";
    hero2.printEligibleSkills();

    cout << "\n=============================================\n";
    cout << "Test xóa kĩ năng của Hero 1:\n";
    hero1.removeSkills();
    hero1.outputHero();

    cout << "\n========== KẾT THÚC CHƯƠNG TRÌNH ==========\n";
    return 0;
}