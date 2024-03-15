#include "bank.h"

int main() {
    Bank bank("MyBank", 100000); // Initial balance of the bank

    bank.addClient("John", 5000);
    bank.addClient("Alice", 10000);

    Client* john = bank.findClient("John");
    Client* alice = bank.findClient("Alice");

    if (john && alice) {
        bank.transfer(*john, *alice, 2000);
    }

    return 0;
}
