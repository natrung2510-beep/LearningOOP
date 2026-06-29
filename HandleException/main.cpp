#include <iostream>
#include <stdexcept>
#include "Wallet.h"
#include <windows.h>
#include <string>
using namespace std;

int i = 1;
void printExecution(const string &instruction, double amount)
{
    cout << "[Giao dịch " << i++ << "] " << instruction << ' ' << amount << " VND...\n";
}
void printError(const string &type, const string &msg)
{
    cerr << "[LOG LỖI - " << type << " ] Lỗi: " << msg << '\n';
}
int main()
{

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "--- KHOI TAO HE THONG ---\n";
    auto customerA = new Wallet("Nguyễn Văn A", 5.0e6);
    double transactions[] = {1e6, -500000, 10e6, 25e7};

    for (double amount : transactions)
    {
        try
        {
            if (amount > 0 && amount == 1e6)
            {
                printExecution("Nạp", amount);
                customerA->deposit(amount);
            }
            else
            {
                printExecution("Rút", amount);
                customerA->withdraw(amount);
            }
            cout << "Thành công! Số dư hiện tại: " << customerA->getBalance() << " VND\n\n";
        }
        catch (const InvalidAmountException &e)
        {
            printError("INVALID AMOUNT", e.what());
        }
        catch (const InsufficientFundsException &e)
        {
            printError("INSUFFICIENT", e.what());
        }
        catch (const TransactionException &e)
        {
            printError("TRANSACTION", e.what());
        }
        catch (const exception &e)
        {
            cerr << "LỖI HỆ THỐNG: " << e.what() << '\n';
        }
        catch (...)
        {
            cerr << "LỖI KHÔNG XÁC ĐỊNH!\n";
        }
    }
    cout << "--- TỔNG KẾT ---\n";
    cout << "Chương trình kết thúc. Số dư cuối cùng an toàn: " << customerA->getBalance() << " VND\n";
    delete customerA;
    customerA = nullptr;
    cin.get();
    return 0;
}