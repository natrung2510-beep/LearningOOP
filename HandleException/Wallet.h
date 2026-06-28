#pragma once
#include <stdexcept>

// EXCEPTION DEFINITIONS
class TransactionException : public std::runtime_error
{
public:
    TransactionException(const char *msg);
};
class InvalidAmountException : public std::invalid_argument
{
public:
    InvalidAmountException(const char *msg);
};
class InsufficientFundsException : public std::runtime_error
{
public:
    InsufficientFundsException(const char *msg);
};

class Wallet
{
private:
    char *ownerName;
    double balance;

public:
    Wallet(const char *name, double balance);
    double getBalance() const noexcept;
    void deposit(double amount);
    void withdraw(double amount);
    ~Wallet();
};