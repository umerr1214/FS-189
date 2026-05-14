#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    int balance; // SEMANTIC ERROR: Should be double as per question

public:
    BankAccount(int initialBalance = 0) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += static_cast<int>(amount); // Data loss due to casting double to int
        }
    }

    void withdraw(double amount) {
        // Logic correctly prevents negative balance, but operates on int after casting
        if (amount > 0 && balance - static_cast<int>(amount) >= 0) {
            balance -= static_cast<int>(amount); // Data loss due to casting double to int
        }
    }

    double getBalance() const {
        return static_cast<double>(balance); // Returns double, but internal balance is int
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
            account = BankAccount(static_cast<int>(initialBalance)); // Cast initial balance to int for constructor
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