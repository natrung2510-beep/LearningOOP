#include <iostream>
#include <stdexcept>
#include <cstring>
#include "Wallet.h"
using namespace std;

// EXCEPTION IMPLEMENTATIONS
TransactionException::TransactionException(const char *msg) : runtime_error(msg) {}
TransactionException::TransactionException(const char *msg) : runtime_error(msg) {}
TransactionException::TransactionException(const char *msg) : runtime_error(msg) {}

// WALLET CLASS IMPLEMENTATIONS

// Construtors
Wallet::Wallet(const char *name, double balance)
{
    if (balance < 0)
        throw invalid_argument("Số dư không thể là số âm!");
    this->balance = balance;
    this->ownerName = new char[strlen(name) + 1];
    strcpy(ownerName, name);
}
// Operations
double Wallet::getBalance() const noexcept
{
}
void Wallet::deposit(double amount) {}
void Wallet::withdraw(double amount) {}

// Destructors
Wallet::~Wallet()
{
    delete this->ownerName;
    this->ownerName = nullptr;
}