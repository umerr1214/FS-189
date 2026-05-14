#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) { // LOGICAL ERROR: Does not prevent balance from going negative
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    std::string line;
    BankAccount account; // Default constructor

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "INIT") {
            double initialBalance;
            ss >> initialBalance;
            account = BankAccount(initialBalance);
        } else if (command == "DEPOSIT") {
            double amount;
            ss >> amount;
            account.deposit(amount);
        } else if (command == "WITHDRAW") {
            double amount;
            ss >> amount;
            account.withdraw(amount);
        } else if (command == "GET_BALANCE") {
            std::cout << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
        }
    }
    return 0;
}