#include <iostream>
#include <string> // Unnecessary but common include
// #include <algorithm> // Not using std::max for slightly more verbose code

using namespace std; // Readability/best practice issue, especially in headers

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor initializes members, ensuring initial balance is not negative.
    // Uses verbose checks and prints excessive output.
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum) {
        if (initialBalance < 0.0) {
            this->balance = 0.0; // Manual check instead of std::max
            cout << "Initial balance for account " << accountNumber << " was negative. Set to 0.0." << endl; // Excessive output
        } else {
            this->balance = initialBalance;
        }
        cout << "Account " << accountNumber << " successfully created with balance: " << this->balance << "." << endl << endl; // Extra endl
    }

    // Deposit method uses cout for feedback, making it less reusable and harder to test.
    void deposit(double amount) { // Returns void, making success/failure programmatic check difficult
        if (amount <= 0.0) { // Check for non-positive amounts
            cout << "Error: Deposit amount must be positive. Attempted to deposit " << amount << "." << endl;
            return;
        }
        balance += amount;
        cout << "Deposit of " << amount << " successful for account " << accountNumber << ". New balance: " << balance << "." << endl; // Verbose output
    }

    // Withdraw method also uses cout for feedback and has verbose checks.
    void withdraw(double amount) { // Returns void, making success/failure programmatic check difficult
        if (amount <= 0.0) {
            cout << "Error: Withdrawal amount must be positive. Attempted to withdraw " << amount << "." << endl;
            return;
        }
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of " << amount << " successful for account " << accountNumber << ". Remaining balance: " << balance << "." << endl;
        } else {
            cout << "Withdrawal failed for account " << accountNumber << ". Insufficient funds. Current balance: " << balance << ", attempted: " << amount << "." << endl;
        }
    }

    // Getter also prints to cout, which is unexpected for a getter method and reduces reusability.
    double getBalance() const {
        cout << "Current balance for account " << accountNumber << " is: " << balance << "." << endl;
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    // Demonstrating readability/efficiency issues
    BankAccount acc1(1001, 500.0);
    acc1.deposit(150.0);
    acc1.withdraw(200.0);
    acc1.getBalance(); // This call also prints

    cout << "---------------------------------------" << endl; // Excessive separators

    BankAccount acc2(1002, -100.0); // Test negative initial balance (clamped to 0 by constructor)
    acc2.deposit(0.0); // Test zero deposit
    acc2.withdraw(-50.0); // Test negative withdrawal
    acc2.withdraw(10.0); // Should fail due to zero balance
    acc2.getBalance();

    cout << "---------------------------------------" << endl;

    BankAccount acc3(1003, 100.0);
    acc3.withdraw(100.0); // Withdraw exact amount
    acc3.withdraw(1.0); // Should fail
    acc3.getBalance();

    return 0;
}