#include <iostream>
#include <string>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Block.h"
#include "Inventory.h"
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void printTitle(const string &title)
{
    cout << "\n=================================================================\n";
    cout << "🎮 " << title << " \n";
    cout << "=================================================================\n";
}

void printStep(const string &stepName)
{
    cout << "\n-----------------------------------------------------------------\n";
    cout << "🔷 TEST CASE: " << stepName << "\n";
    cout << "-----------------------------------------------------------------\n";
}

void printAction(const string &action)
{
    cout << "  [Hành động] >>> " << action << "\n";
}

void printResult(const string &result)
{
    cout << "  [Kỳ vọng]   => " << result << "\n\n";
}

int main()
{
    // 1. Lệnh thiết lập hiển thị Tiếng Việt có dấu cho Terminal/Console
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    printTitle("CHƯƠNG TRÌNH KIỂM THỬ HỆ THỐNG INVENTORY MINECRAFT");

    // TODO: Khởi tạo túi đồ gốc ở đây (VD: Inventory myBag(5); )
    Inventory myInventory(5);
    Item *leftOver = nullptr;
    // ---------------------------------------------------------
    printStep("1. Khởi tạo & Đa hình (Polymorphism)");
    printAction("Tạo túi đồ, nhét Weapon, Block, Potion và gọi useItem().");

    // TODO: Viết code test của em ở đây...
    leftOver = myInventory.addItem(new Weapon(2, 1, "Kiếm Kim Cương", 7.0f));
    if (leftOver)
    {
        delete leftOver;
        leftOver = nullptr;
    }

    leftOver = myInventory.addItem(new Potion(5, 1, "Thuốc hồi máu siêu cấp"));
    if (leftOver)
    {
        delete leftOver;
        leftOver = nullptr;
    }

    leftOver = myInventory.addItem(new Block(5, 64, "Khối vàng"));
    if (leftOver)
    {
        delete leftOver;
        leftOver = nullptr;
    }

    printResult("Các vật phẩm đã được thêm. Kích hoạt useItem() in ra đúng hành động!");

    for (int i = 0; i < 3; i++)
        myInventory.getSlot()[i]->useItem();

    // ---------------------------------------------------------
    printStep("2. Nạp chồng toán tử & Tràn Stack (Merge & Overflow)");
    printAction("Nhặt Khối Đất liên tục để ép tràn số lượng (VD: > 64).");

    // TODO: Viết code test gộp đồ và tràn stack ở đây...

    while (!leftOver)
        leftOver = myInventory.addItem(new Block(1, 5, "Khối đất"));

    printResult("Vật phẩm rớt ra ngoài và biến mất!");
    delete leftOver;
    leftOver = nullptr;

    // ---------------------------------------------------------
    printStep("3. Ép giới hạn (Túi đầy & Rớt đồ)");
    printAction("Nhét thêm đồ VIP khi túi đã chứa tối đa số slot.");

    // TODO: Viết code test túi đầy ở đây...

    printResult("Hệ thống báo đầy túi, vật phẩm bị rớt ra ngoài mà không sập game.");

    // ---------------------------------------------------------
    printStep("4. Xóa đồ & Quản lý phân mảnh (Fragmentation)");
    printAction("Xóa ngẫu nhiên 1 món đồ ở giữa túi, rồi nhặt 1 món mới hoàn toàn.");

    // TODO: Viết code test xóa đồ và nhét vào ô trống (tombstone) ở đây...

    printResult("Món đồ mới đã khôn ngoan lấp đúng vào khoảng trống ở giữa túi đồ.");

    // ---------------------------------------------------------
    printStep("5. Nén mảng & Sắp xếp (Compaction & Quick Sort)");
    printAction("Xóa 1 vài ô để tạo khoảng trống, sau đó gọi sortInventory().");

    // TODO: Viết code gọi hàm sort ở đây...

    printResult("Túi đồ đã dồn khít, ô trống bị đẩy về cuối, đồ VIP Rarity cao nằm trên cùng!");

    // ---------------------------------------------------------
    printStep("6. Luật 3 Hàm (Deep Copy & Memory)");
    printAction("Tạo túi đồ copy (bag2 = bag1) và thay đổi tên 1 món đồ trong bag2.");

    // TODO: Viết code test Copy Constructor / Assignment Operator ở đây...

    printResult("Túi 1 không bị đổi tên theo. Hai túi hoàn toàn độc lập trong bộ nhớ!");

    cout << "\n=================================================================\n";
    cout << "🏁 HOÀN TẤT KIỂM THỬ. HỆ THỐNG ĐANG DỌN DẸP BỘ NHỚ...\n";
    cout << "=================================================================\n";

    // Hệ thống sẽ tự động gọi Destructor khi ra khỏi hàm main
    return 0;
}