#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Required for std::fixed, std::setprecision

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor - Readability/Efficiency Issue: accountNumber passed by value, then copied.
    // While for a single string this might not be a huge performance hit, for larger objects
    // or frequent constructions, passing by const reference would be more efficient.
    BankAccount(std::string accNum_val) {
        accountNumber = accNum_val; // Assignment after default construction, less efficient than initializer list
        balance = 0.0;
        std::cout << "BankAccount object created with account number: " << accountNumber << " and initial balance set to: " << balance << std::endl << std::endl;
    }

    // Deposit method - Readability/Efficiency Issues:
    // 1. Overly verbose error messages using std::endl for every line (flushes buffer frequently).
    // 2. Redundant check for positive amount using a temporary boolean.
    // 3. Printing success/failure messages directly within the class, coupling the class to I/O.
    void deposit(double amountToDeposit) {
        bool isAmountValidAndPositive = (amountToDeposit > 0.0); // Redundant boolean variable
        if (isAmountValidAndPositive == true) { // Overly explicit comparison
            balance = balance + amountToDeposit; // Simple addition
            std::cout << "Operation performed: Deposit" << std::endl;
            std::cout << "Account: " << accountNumber << std::endl;
            std::cout << "Amount deposited: " << std::fixed << std::setprecision(2) << amountToDeposit << std::endl;
            std::cout << "New balance after deposit: " << std::fixed << std::setprecision(2) << balance << std::endl << std::endl;
        } else {
            std::cout << "ATTENTION: Deposit operation failed!" << std::endl;
            std::cout << "Reason: The amount provided for deposit must be a strictly positive value." << std::endl;
            std::cout << "Attempted deposit amount was: " << std::fixed << std::setprecision(2) << amountToDeposit << std::endl;
            std::cout << "Current balance remains: " << std::fixed << std::setprecision(2) << balance << std::endl << std::endl;
        }
    }

    // Withdraw method - Readability/Efficiency Issues:
    // 1. Nested if-else structure for validation, making it harder to read.
    // 2. Repeated use of std::fixed and std::setprecision within the method.
    // 3. Overly verbose success/failure messages using std::endl.
    // 4. Temporary variable for balance check.
    void withdraw(double amountToWithdraw) {
        if (amountToWithdraw > 0.0) {
            double currentAccountBalance = balance; // Unnecessary temporary variable
            if (currentAccountBalance >= amountToWithdraw) {
                balance = balance - amountToWithdraw; // Perform subtraction
                std::cout << "Operation performed: Withdrawal" << std::endl;
                std::cout << "Account: " << accountNumber << std::endl;
                std::cout << "Amount withdrawn: " << std::fixed << std::setprecision(2) << amountToWithdraw << std::endl;
                std::cout << "Updated balance after withdrawal: " << std::fixed << std::setprecision(2) << balance << std::endl << std::endl;
            } else {
                std::cout << "WARNING: Withdrawal operation could not be completed!" << std::endl;
                std::cout << "Explanation: Insufficient funds available in account." << std::endl;
                std::cout << "Account Number: " << accountNumber << std::endl;
                std::cout << "Available balance: " << std::fixed << std::setprecision(2) << currentAccountBalance << std::endl;
                std::cout << "Requested withdrawal amount: " << std::fixed << std::setprecision(2) << amountToWithdraw << std::endl << std::endl;
            }
        } else {
            std::cout << "ERROR: Withdrawal amount must be greater than zero!" << std::endl;
            std::cout << "Input received for withdrawal: " << std::fixed << std::setprecision(2) << amountToWithdraw << std::endl;
            std::cout << "No changes made to account " << accountNumber << ". Balance: " << std::fixed << std::setprecision(2) << balance << std::endl << std::endl;
        }
    }

    // Getters
    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount myAccount("ACC98765");

    // Perform some operations
    myAccount.deposit(250.75);
    myAccount.withdraw(100.50);
    myAccount.deposit(-50.00); // Invalid deposit
    myAccount.withdraw(300.00); // Insufficient funds
    myAccount.deposit(500.00);
    myAccount.withdraw(0.00); // Invalid withdrawal
    myAccount.withdraw(650.25); // Exact withdrawal, should succeed

    // Display final balance
    std::cout << "SUMMARY REPORT:" << std::endl;
    std::cout << "Account Number: " << myAccount.getAccountNumber() << std::endl;
    std::cout << "Final Account Balance: " << std::fixed << std::setprecision(2) << myAccount.getBalance() << std::endl;

    // Another account for more testing
    BankAccount secondAccount("ACC11223");
    secondAccount.deposit(100.00);
    secondAccount.withdraw(10.00);
    secondAccount.withdraw(90.00);
    secondAccount.deposit(1.00);
    std::cout << "\nSUMMARY REPORT FOR SECOND ACCOUNT:" << std::endl;
    std::cout << "Account Number: " << secondAccount.getAccountNumber() << std::endl;
    std::cout << "Final Account Balance: " << std::fixed << std::setprecision(2) << secondAccount.getBalance() << std::endl;

    return 0;
}