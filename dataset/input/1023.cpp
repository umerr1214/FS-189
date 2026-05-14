#include <iostream>

class BankAccount {
public:
    BankAccount() {
        // Incrementing a char, which will wrap around after 127
        totalAccountsCreated++;
    }

    static int getTotalAccountsCreated() {
        // Implicit conversion from char to int
        return totalAccountsCreated;
    }

private:
    // Semantic Error: Using 'char' for a counter that is expected to count beyond 127
    // This compiles and runs, but the meaning of the count is corrupted for larger numbers.
    static char totalAccountsCreated;
};

char BankAccount::totalAccountsCreated = 0;

int main() {
    // Create enough accounts to demonstrate the char overflow
    for (int i = 0; i < 130; ++i) {
        BankAccount acc;
    }
    std::cout << "Total accounts created: " << BankAccount::getTotalAccountsCreated() << std::endl;
    return 0;
}