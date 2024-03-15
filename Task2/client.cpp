#include "client.h"
#include "bank.h"
#include <iostream>

Client::Client(const std::string& name, double initialBalance) : name(name), accountBalance(initialBalance) {}

const std::string& Client::getName() const {
    return name;
}

double Client::getAccountBalance() const {
    return accountBalance;
}

void Client::deposit(double amount) {
    accountBalance += amount;
    std::cout << "Deposited $" << amount << ". New balance: $" << accountBalance << std::endl;
}

bool Client::withdraw(double amount) {
    if (accountBalance >= amount) {
        accountBalance -= amount;
        std::cout << "Withdrawn $" << amount << ". New balance: $" << accountBalance << std::endl;
        return true;
    }
    else {
        std::cout << "Insufficient funds!" << std::endl;
        return false;
    }
}

void Client::transfer(Bank& destinationBank, Client& recipient, double amount) {
    if (withdraw(amount)) {
        destinationBank.deposit(recipient, amount);
        std::cout << "Transferred $" << amount << " to " << destinationBank.getName() << ". New balance: $" << accountBalance << std::endl;
    }
    else {
        std::cout << "Transfer failed due to insufficient funds!" << std::endl;
    }
}
