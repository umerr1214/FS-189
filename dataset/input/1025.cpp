#include <iostream>

class BankAccount {
private:
    static int totalAccountsCreated;
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {
        totalAccountsCreated++; // Correctly increments the static counter
    }

    // Logical Error: Returns a hardcoded value instead of the actual totalAccountsCreated
    static int getTotalAccounts() {
        return 0; // This should return totalAccountsCreated
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
    BankAccount acc3(103, 200.0); // Create three accounts

    // The program will compile and run, but output an incorrect value due to the logical error
    std::cout << "Total accounts created: " << BankAccount::getTotalAccounts() << std::endl;

    return 0;
}