#include <iostream>

class BankAccount {
public:
    BankAccount() {
        totalAccountsCreated++;
    }

    static int getTotalAccountsCreated() {
        return totalAccountsCreated;
    }

private:
    static int totalAccountsCreated;
} // Syntax Error: Missing semicolon after class definition

int BankAccount::totalAccountsCreated = 0;

int main() {
    BankAccount acc1;
    BankAccount acc2;
    BankAccount acc3;
    std::cout << "Total accounts created: " << BankAccount::getTotalAccountsCreated() << std::endl;
    return 0;
}