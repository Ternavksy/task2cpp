#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "client.h"

class Bank {
private:
    std::string name;
    double bankBalance;
    std::vector<Client> clients;

public:
    Bank(const std::string& name, double initialBalance);

    const std::string& getName() const;

    double getBankBalance() const;

    void addClient(const std::string& clientName, double initialBalance);

    void removeClient(const std::string& clientName);

    Client* findClient(const std::string& clientName);

    void deposit(Client& client, double amount);

    bool withdraw(Client& client, double amount);

    void transfer(Client& sender, Client& recipient, double amount);
};

#endif // BANK_H
