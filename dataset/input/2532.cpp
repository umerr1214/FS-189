#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // SEMANTIC ERROR: getBalance() returns int, losing precision and not matching the double balance
    int getBalance() const {
        return static_cast<int>(balance); // Semantic error: type narrowing, potential loss of data
    }
};

int main() {
    BankAccount account(100.55);
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Initial: " << account.getBalance() << std::endl; // Expected: 100.55, Actual: 100.00 (due to int cast)

    account.deposit(20.33);
    // Internal balance is 120.88, but getBalance() returns 120
    std::cout << "After deposit 20.33: " << account.getBalance() << std::endl; // Expected: 120.88, Actual: 120.00

    account.withdraw(10.11);
    // Internal balance is 110.77, but getBalance() returns 110
    std::cout << "After withdraw 10.11: " << account.getBalance() << std::endl; // Expected: 110.77, Actual: 110.00

    return 0;
}