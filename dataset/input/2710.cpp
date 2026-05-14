#include <iostream>

class BankAccount {
private:
    double balance;
public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        if (initialBalance < 0) {
            balance = 0; // Ensure initial balance is not negative
            std::cout << "Initial balance cannot be negative. Setting to 0." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        } else {
            std::cout << "Warning: Cannot set negative balance. Balance not updated." << std::endl;
        }
    }
} // Missing semicolon here, causing a syntax error

int main() {
    BankAccount myAccount(100.0);
    std::cout << "Initial balance: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(250.50);
    std::cout << "Balance after setting to 250.50: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(-50.0);
    std::cout << "Balance after trying to set to -50.0: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(0.0);
    std::cout << "Balance after setting to 0.0: " << myAccount.getBalance() << std::endl;

    BankAccount anotherAccount(-10.0); // Test negative initial balance
    std::cout << "Another account initial balance: " << anotherAccount.getBalance() << std::endl;

    return 0;
}