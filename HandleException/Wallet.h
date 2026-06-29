#pragma once
#include <stdexcept>

// EXCEPTION DEFINITIONS
class TransactionException : public std::runtime_error
{
public:
    TransactionException(const char *msg);
};
class InvalidAmountException : public TransactionException
{
public:
    InvalidAmountException(const char *msg);
};
class InsufficientFundsException : public TransactionException
{
public:
    InsufficientFundsException(const char *msg);
};

class Wallet
{
private:
    char *ownerName;
    double balance;
    static constexpr double MAX_BALANCE = static_cast<double>(2e7);

public:
    Wallet(const char *name, double balance);
    double getBalance() const noexcept;
    char *getName() const noexcept;
    void deposit(double amount);
    void withdraw(double amount);
    ~Wallet();
};