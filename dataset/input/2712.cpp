#include <iostream>

class BankAccount {
public: // Semantic error: 'balance' is public, violating strict encapsulation
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
            std::cout << "Warning (via setBalance): Cannot set negative balance. Balance not updated." << std::endl;
        }
    }
};

int main() {
    BankAccount myAccount(100.0);
    std::cout << "Initial balance: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(250.50);
    std::cout << "Balance after setting to 250.50 via setBalance(): " << myAccount.getBalance() << std::endl;

    // Direct access to balance, bypassing validation
    myAccount.balance = -75.0; // This is the semantic error being demonstrated
    std::cout << "Balance after directly setting to -75.0: " << myAccount.getBalance() << std::endl;

    myAccount.setBalance(0.0);
    std::cout << "Balance after setting to 0.0 via setBalance(): " << myAccount.getBalance() << std::endl;

    BankAccount anotherAccount(-10.0);
    std::cout << "Another account initial balance: " << anotherAccount.getBalance() << std::endl;

    return 0;
}