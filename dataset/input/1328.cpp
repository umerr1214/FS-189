#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    std::string accNum; // Poor variable name
    std::string hName;  // Poor variable name
    double bal;         // Poor variable name

public:
    // Constructor: Passes std::string by value (minor efficiency issue)
    BankAccount(std::string accNum, std::string hName, double bal)
        : accNum(accNum), hName(hName), bal(bal) {
        // No comments (readability issue)
        std::cout << "Account " << this->accNum << " created with initial balance: " 
                  << std::fixed << std::setprecision(2) << this->bal << std::endl; // Excessive std::endl
    }

    // Deposit method: Prints messages directly, uses std::endl excessively (readability/design/efficiency issue)
    void deposit(double amt) { // Poor variable name
        std::cout << "Attempting to deposit " << std::fixed << std::setprecision(2) << amt << "..." << std::endl;
        if (amt > 0) {
            bal += amt;
            std::cout << "Deposit successful. New balance: " << std::fixed << std::setprecision(2) << bal << std::endl;
        } else {
            std::cout << "Deposit failed. Amount must be positive." << std::endl;
        }
    }

    // Withdraw method: Prints messages directly, uses std::endl excessively (readability/design/efficiency issue)
    void withdraw(double wAmt) { // Poor variable name
        std::cout << "Attempting to withdraw " << std::fixed << std::setprecision(2) << wAmt << "..." << std::endl;
        if (wAmt > 0) {
            if (bal >= wAmt) {
                bal -= wAmt;
                std::cout << "Withdrawal successful. New balance: " << std::fixed << std::setprecision(2) << bal << std::endl;
            } else {
                std::cout << "Withdrawal failed. Insufficient funds." << std::endl;
            }
        } else {
            std::cout << "Withdrawal failed. Amount must be positive." << std::endl;
        }
    }

    double getBalance() const {
        return bal;
    }

    std::string getAccountNumber() const {
        return accNum;
    }
    
    std::string getAccountHolderName() const {
        return hName;
    }
};

int main() {
    // Demonstrating Readability/Efficiency Issues
    BankAccount myAccount("12345", "Alice", 100.00); 
    
    myAccount.deposit(50.00);
    myAccount.withdraw(30.00);

    myAccount.deposit(-10.00); // Invalid deposit
    myAccount.deposit(0.00);   // Invalid deposit

    myAccount.withdraw(200.00); // Overdraft
    myAccount.withdraw(-20.00); // Invalid withdrawal amount

    std::cout << "Current balance for " << myAccount.getAccountNumber() << ": " 
              << std::fixed << std::setprecision(2) << myAccount.getBalance() << std::endl;

    return 0;
}