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

    double getBalance() const {
        return balance;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    BankAccount myAccount("12345", 1000.0);
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    std::cout << "Account " << myAccount.getAccountNumber() << " balance: " << myAccount.getBalance() << std::endl;
    return 0;
}