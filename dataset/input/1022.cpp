#include <iostream>

class BankAccount {
public:
    BankAccount() {
        // Logical Error: totalAccountsCreated is not incremented in the constructor
        // totalAccountsCreated++; // This line is intentionally omitted
    }

    static int getTotalAccountsCreated() {
        return totalAccountsCreated;
    }

private:
    static int totalAccountsCreated;
};

int BankAccount::totalAccountsCreated = 0;

int main() {
    BankAccount acc1;
    BankAccount acc2;
    BankAccount acc3;
    std::cout << "Total accounts created: " << BankAccount::getTotalAccountsCreated() << std::endl;
    return 0;
}