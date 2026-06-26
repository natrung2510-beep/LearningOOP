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
    printStep("3. Xóa đồ & Quản lý phân mảnh (Fragmentation)");
    printAction("Xóa ngẫu nhiên 1 món đồ ở giữa túi, rồi nhặt 1 món mới hoàn toàn.");

    cout << "\n[ TIẾN HÀNH XÓA ĐỒ Ở SLOT 2 ]\n";
    myInventory.removeItem(2);

    cout << "\n>>> TÌNH TRẠNG TÚI (CÓ LỖ HỔNG):";
    cout << myInventory;

    cout << "\n[ NHẶT 'KHỐI SẮT' VÀO TÚI ]\n";
    leftOver = myInventory.addItem(new Block(2, 30, "Khối sắt"));
    if (leftOver)
    {
        delete leftOver;
        leftOver = nullptr;
    }

    cout << "\n>>> TÌNH TRẠNG TÚI (ĐÃ LẤP LỖ HỔNG):";
    cout << myInventory;

    printResult("Hệ thống đã tự động tìm thấy Slot trống và lấp đầy hoàn hảo!");

    // ---------------------------------------------------------
    printStep("4. Nén mảng & Sắp xếp (Compaction & Quick Sort)");
    printAction("Xóa 1 vài ô để tạo khoảng trống, sau đó gọi sortInventory().");
    cout << myInventory;
    myInventory.removeItem(1);
    myInventory.removeItem(2);
    // TODO: Viết code gọi hàm sort ở đây...
    cout << myInventory;
    myInventory.sortInventory();
    cout << myInventory;
    printResult("Túi đồ đã dồn khít, ô trống bị đẩy về cuối, đồ VIP Rarity cao nằm trên cùng!");

    // ---------------------------------------------------------
    printStep("5. Luật 3 Hàm (Deep Copy & Memory)");
    printAction("Tạo hai túi đồ và thay đổi SỐ LƯỢNG 1 món đồ bất kì.");
    // TODO: Viết code test Copy Constructor / Assignment Operator ở đây...
    cout << "Tạo túi đồ thứ nhất (myBag1) bằng toán tử gán (= operator):\n";
    Inventory myBag1(5);
    myBag1 = myInventory;
    cout << "THÔNG TIN TÚI ĐỒ THỨ NHẤT:\n";
    cout << myBag1;
    cout << "Thay đổi số lượng của vật phẩm trong slot số " << 3 << "trong túi đồ thứ nhất\n";
    myBag1.getSlot()[3]->setQuantity(1);
    cout << "Số lượng vât phẩm ô thứ 3 trong myBag1 là : " << myBag1.getSlot()[3]->getQuantity() << '\n';
    cout << "Số lượng vât phẩm ô thứ 3 trong myInventory là : " << myInventory.getSlot()[3]->getQuantity() << '\n';

    cout << "Tạo túi đồ thứ 2 (myBag2) bằng copy constructor từ myBag1:\n";
    Inventory myBag2(myBag1);
    cout << "THÔNG TIN TÚI ĐỒ THỨ HAI:\n";
    cout << myBag2;
    cout << "Thay đổi số lượng của vật phẩm trong slot số " << 3 << "trong túi đồ thứ hai\n";
    myBag2.getSlot()[3]->setQuantity(12);
    cout << "Số lượng vât phẩm ô thứ 3 trong myBag2 là : " << myBag2.getSlot()[3]->getQuantity() << '\n';
    cout << "Số lượng vât phẩm ô thứ 3 trong myBag1 là : " << myBag1.getSlot()[3]->getQuantity() << '\n';

    printResult("Ba túi đồ hoàn toàn độc lập trong bộ nhớ!");

    cout << "\n=================================================================\n";
    cout << "🏁 HOÀN TẤT KIỂM THỬ. HỆ THỐNG ĐANG DỌN DẸP BỘ NHỚ...\n";
    cout << "=================================================================\n";

    // Hệ thống sẽ tự động gọi Destructor khi ra khỏi hàm main
    return 0;
}