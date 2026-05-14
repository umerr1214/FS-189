#include <iostream>

class BankAccount {
private:
    static int totalAccountsCreated;
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        totalAccountsCreated++;
    }

    // Syntax Error: Missing return type for static function
    static getTotalAccounts() { // Should be 'static int getTotalAccounts()'
        return totalAccountsCreated;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int BankAccount::totalAccountsCreated = 0;

int main() {
    BankAccount acc1(101, 1000.0);
    BankAccount acc2(102, 500.0);

    // This line will cause a compilation error due to the syntax error in getTotalAccounts() definition
    std::cout << "Total accounts created: " << BankAccount::getTotalAccounts() << std::endl;

    return 0;
}