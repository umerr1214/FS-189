#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, std::string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        // Ensuring initial balance is not negative, though not explicitly an error for robustness issue.
        if (balance < 0.0) {
            balance = 0.0;
        }
    }

    // Robustness Issue: Allows negative amounts to be "deposited", effectively performing a withdrawal
    // without the proper checks or explicit intent.
    void deposit(double amount) {
        balance += amount; // No check for amount > 0
    }

    // Robustness Issue: Does not handle non-positive withdrawal amounts or insufficient funds gracefully.
    // It simply does nothing without informing the user about the failure.
    void withdraw(double amount) {
        if (amount > 0 && balance - amount >= 0) {
            balance -= amount;
        }
        // No explicit feedback (e.g., return value or exception) for invalid amounts (<=0)
        // or insufficient funds. The operation silently fails from the user's perspective.
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount("123456789", "John Doe", 1000.0);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Initial balance: $" << myAccount.getBalance() << std::endl;

    myAccount.deposit(200.0);
    std::cout << "After deposit $200.00: $" << myAccount.getBalance() << std::endl;

    myAccount.withdraw(300.0);
    std::cout << "After withdraw $300.00: $" << myAccount.getBalance() << std::endl;

    // --- Robustness Issue demonstration ---
    // 1. Negative deposit acts as a withdrawal without proper validation
    myAccount.deposit(-150.0);
    std::cout << "After deposit $-150.00 (robustness issue): $" << myAccount.getBalance() << std::endl;

    // 2. Withdrawal of zero amount - silent failure
    myAccount.withdraw(0.0);
    std::cout << "After withdraw $0.00 (robustness issue): $" << myAccount.getBalance() << std::endl;

    // 3. Withdrawal of negative amount - silent failure
    myAccount.withdraw(-50.0);
    std::cout << "After withdraw $-50.00 (robustness issue): $" << myAccount.getBalance() << std::endl;

    // 4. Attempt to overdraw - correctly prevented, but no feedback to the user
    myAccount.withdraw(1000.0);
    std::cout << "After attempt to withdraw $1000.00: $" << myAccount.getBalance() << std::endl;

    myAccount.withdraw(50.0);
    std::cout << "After withdraw $50.00: $" << myAccount.getBalance() << std::endl;

    return 0;
}