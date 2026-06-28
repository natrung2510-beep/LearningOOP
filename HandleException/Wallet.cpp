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
Wallet::Wallet(const char *name, double balance) {}
double Wallet::getBalance() const noexcept {}
void Wallet::deposit(double amount) {}
void Wallet::withdraw(double amount) {}
Wallet::~Wallet()
{
}