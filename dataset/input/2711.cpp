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
        if (newBalance > 0) { // Logical error: prevents setting balance to exactly 0.0
            balance = newBalance;
        } else if (newBalance < 0) {
            std::cout << "Warning: Cannot set negative balance. Balance not updated." << std::endl;
        } else { // newBalance is 0
            std::cout << "Warning: Balance must be positive. Not updating balance (0.0 is not allowed)." << std::endl;
            // The balance remains unchanged if newBalance is 0.0, which is incorrect.
        }
    }
};

int main() {
    BankAccount myAccount(100.0);
    std::cout << "Initial balance: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(250.50);
    std::cout << "Balance after setting to 250.50: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(-50.0);
    std::cout << "Balance after trying to set to -50.0: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(0.0); // This should be allowed but won't be due to logical error
    std::cout << "Balance after trying to set to 0.0: " << myAccount.getBalance() << std::endl;

    BankAccount anotherAccount(-10.0);
    std::cout << "Another account initial balance: " << anotherAccount.getBalance() << std::endl;

    return 0;
}