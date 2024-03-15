#include "bank.h"
#include "client.h"
#include <iostream>

Bank::Bank(const std::string& name, double initialBalance) : name(name), bankBalance(initialBalance) {}

const std::string& Bank::getName() const {
    return name;
}

double Bank::getBankBalance() const {
    return bankBalance;
}

void Bank::addClient(const std::string& clientName, double initialBalance) {
    clients.push_back(Client(clientName, initialBalance));
    std::cout << "Client " << clientName << " added to " << name << " bank." << std::endl;
}

void Bank::removeClient(const std::string& clientName) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getName() == clientName) {
            clients.erase(it);
            std::cout << "Client " << clientName << " removed from " << name << " bank." << std::endl;
            return;
        }
    }
    std::cout << "Client " << clientName << " not found in " << name << " bank." << std::endl;
}

Client* Bank::findClient(const std::string& clientName) {
    for (auto& client : clients) {
        if (client.getName() == clientName) {
            return &client;
        }
    }
    return nullptr;
}

void Bank::deposit(Client& client, double amount) {
    client.deposit(amount);
    bankBalance += amount;
}

bool Bank::withdraw(Client& client, double amount) {
    if (bankBalance >= amount) {
        if (client.withdraw(amount)) {
            bankBalance -= amount;
            return true;
        }
        else {
            std::cout << "Withdrawal failed for client " << client.getName() << " due to insufficient funds!" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Withdrawal failed from bank " << name << " due to insufficient funds!" << std::endl;
        return false;
    }
}

void Bank::transfer(Client& sender, Client& recipient, double amount) {
    if (withdraw(sender, amount)) {
        recipient.deposit(amount);
        std::cout << "Transferred $" << amount << " from " << sender.getName() << " to " << recipient.getName() << std::endl;
    }
    else {
        std::cout << "Transfer failed due to insufficient funds!" << std::endl;
    }
}
