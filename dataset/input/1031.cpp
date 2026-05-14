#include <iostream>
#include <string>

class Cashier; // Forward declaration

class Wallet {
private:
    double balance;

public:
    Wallet(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    friend class Cashier;
};

class Cashier {
public:
    void processPayment(Wallet& wallet, double amount) {
        wallet.balance += amount; // LOGICAL ERROR: Should be -= amount for a payment
    }

    void addFunds(Wallet& wallet, double amount) {
        wallet.balance += amount; // This is correct for adding funds
    }
};

int main() {
    Wallet myWallet(100.0);
    Cashier myCashier;

    std::cout << "Initial wallet balance: " << myWallet.getBalance() << std::endl;

    myCashier.processPayment(myWallet, 30.0);
    std::cout << "Balance after payment: " << myWallet.getBalance() << std::endl;

    myCashier.addFunds(myWallet, 50.0);
    std::cout << "Balance after adding funds: " << myWallet.getBalance() << std::endl;

    myCashier.processPayment(myWallet, 15.0);
    std::cout << "Balance after second payment: " << myWallet.getBalance() << std::endl;

    return 0;
}