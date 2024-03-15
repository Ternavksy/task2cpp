#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Bank; // Forward declaration

class Client {
private:
    std::string name;
    double accountBalance;

public:
    Client(const std::string& name, double initialBalance);

    const std::string& getName() const;

    double getAccountBalance() const;

    void deposit(double amount);

    bool withdraw(double amount);

    void transfer(Bank& destinationBank, Client& recipient, double amount);
};

#endif // CLIENT_H
