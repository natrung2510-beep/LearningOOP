#include <iostream>
#include <stdexcept>
#include <cstring>
#include "Wallet.h"
using namespace std;

// EXCEPTION IMPLEMENTATIONS
TransactionException::TransactionException(const char *msg) : runtime_error(msg) {}
InvalidAmountException::InvalidAmountException(const char *msg) : TransactionException(msg) {}
InsufficientFundsException::InsufficientFundsException(const char *msg) : TransactionException(msg) {}

// WALLET CLASS IMPLEMENTATIONS

// Construtors
Wallet::Wallet(const char *name, double balance)
{
    if (balance < 0)
        throw invalid_argument("SỐ DƯ KHÔNG THỂ LÀ SỐ ÂM!");
    this->balance = balance;
    this->ownerName = new char[strlen(name) + 1];
    strcpy(ownerName, name);
}
// Operations
double Wallet::getBalance() const noexcept
{
    return this->balance;
}
void Wallet::deposit(double amount)
{
    if (amount <= 0)
        throw InvalidAmountException("SỐ TIỀN CẦN NẠP KHÔNG THỂ ÂM!");

    this->balance += amount;
    cout << "NẠP TIỀN THÀNH CÔNG! SỐ DƯ HIỆN TẠI: " << this->balance << '\n';
}
void Wallet::withdraw(double amount)
{
    if (amount <= 0)
        throw InvalidAmountException("SỐ TIỀN CẦN RÚT KHÔNG THỂ ÂM!");

    if (amount > this->balance)
        throw InsufficientFundsException("SỐ DƯ CỦA QUÝ KHÁCH KHÔNG ĐỦ ĐỂ THỰC HIỆN GIAO DỊCH!");

    if (amount > MAX_BALANCE)
        throw TransactionException("LỖI GIAO DỊCH! VƯỢT QUÁ HẠN MỨC CHO PHÉP!");

    this->balance -= amount;
    cout << "RÚT TIỀN THÀNH CÔNG! SỐ DƯ HIỆN TẠI: " << this->balance << '\n';
}

// Destructors
Wallet::~Wallet()
{
    delete this->ownerName;
    this->ownerName = nullptr;
}