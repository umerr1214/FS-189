#include <iostream>
#include <string>
#include <sstream>

class Wallet {
private:
    int balance;

public:
    Wallet() : balance(0) {}

    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(int amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
        }
    }

    int getBalance() const {
        return balance;
    }
} // SYNTAX ERROR: Missing semicolon here, should be `};`

int main() {
    Wallet wallet;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string command;
        ss >> command;
        if (command == "deposit") {
            int amount;
            ss >> amount;
            wallet.deposit(amount);
        } else if (command == "withdraw") {
            int amount;
            ss >> amount;
            wallet.withdraw(amount);
        } else if (command == "balance") {
            std::cout << "Balance: " << wallet.getBalance() << std::endl;
        }
    }
    return 0;
}