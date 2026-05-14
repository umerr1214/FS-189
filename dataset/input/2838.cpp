#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
        }
    }

    // Semantic Error: getBalance() returns the length of the account number string,
    // not the actual balance. This compiles because string::length() (size_type)
    // is implicitly convertible to double.
    double getBalance() const {
        return static_cast<double>(accountNumber.length()); // Intended: return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    BankAccount myAccount("123456789", 1000.0); // accountNumber length is 9, initial balance 1000
    myAccount.deposit(200.0); // balance becomes 1200
    myAccount.withdraw(50.0); // balance becomes 1150
    // Expected output for balance: 1150.0
    // Actual output for balance: 9.0 (length of "123456789")
    std::cout << "Account " << myAccount.getAccountNumber() << " balance: " << myAccount.getBalance() << std::endl;
    return 0;
}