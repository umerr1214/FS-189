#include <iostream>
#include <string>

// Forward declaration of Cashier is needed before Wallet if Wallet declares Cashier as friend
// and Cashier is defined later.
class Cashier; // Forward declaration

class Wallet {
private:
    double balance;

public:
    Wallet(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    frind class Cashier; // SYNTAX ERROR: misspelled 'friend'
};

class Cashier {
public:
    void processPayment(Wallet& wallet, double amount) {
        wallet.balance -= amount;
    }

    void addFunds(Wallet& wallet, double amount) {
        wallet.balance += amount;
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