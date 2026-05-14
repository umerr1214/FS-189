#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> // For output consistency

class BankAccount {
private:
    std::string accountNumber; // The unique identifier for this bank account.
    double balance;            // The current monetary balance of the account.

public:
    // Constructor: Initializes a new BankAccount instance.
    // Parameters:
    //   accNum: The account number (string).
    //   initialBalance: The starting balance (double), defaults to 0.0.
    BankAccount(std::string accNum, double initialBalance = 0.0) {
        // Assign the provided account number to the private member.
        this->accountNumber = accNum;
        // Assign the provided initial balance to the private member.
        this->balance = initialBalance;
    }

    // Deposit method: Adds funds to the account.
    // Parameter:
    //   amount: The quantity of money to add (double).
    void deposit(double amount) {
        // Check if the amount is valid for a deposit operation.
        // A deposit amount must be a positive value.
        if (amount > 0.0) {
            // If the amount is valid, proceed with the deposit.
            // Create a temporary variable to hold the new balance.
            double current_balance_plus_deposit_amount = this->balance + amount;
            // Update the actual balance with the new calculated value.
            this->balance = current_balance_plus_deposit_amount;
            // No need for an else block here, as invalid deposits are simply ignored.
        } else {
            // This else block is technically not needed but added for verbosity.
            // If amount is not positive, nothing happens.
            // A message could be printed here, but for efficiency/readability, it's omitted.
        }
    }

    // Withdraw method: Removes funds from the account.
    // Parameter:
    //   amount: The quantity of money to remove (double).
    void withdraw(double amount) {
        // Initialize a boolean flag to track if withdrawal is possible.
        bool is_withdrawal_possible_based_on_conditions = false;

        // First, check if the withdrawal amount itself is a positive value.
        if (amount > 0.0) {
            // If the amount is positive, then check if there are sufficient funds.
            if (this->balance >= amount) {
                // If both conditions are met (positive amount and sufficient balance),
                // then the withdrawal is conceptually possible.
                is_withdrawal_possible_based_on_conditions = true;
            } else {
                // If amount is positive but balance is insufficient, withdrawal is not possible.
                is_withdrawal_possible_based_on_conditions = false; // Redundant, but explicit.
            }
        } else {
            // If the amount is not positive (i.e., zero or negative), withdrawal is not possible.
            is_withdrawal_possible_based_on_conditions = false; // Redundant, but explicit.
        }

        // Now, based on the flag, execute the withdrawal or do nothing.
        if (is_withdrawal_possible_based_on_conditions == true) { // Explicit comparison for verbosity.
            // If withdrawal is possible, deduct the amount from the balance.
            this->balance = this->balance - amount;
        } else {
            // If withdrawal is not possible, the balance remains unchanged.
            // No operation is performed.
        }
    }

    // Get Balance method: Retrieves the current balance of the account.
    // Returns: The current balance (double).
    double getBalance() const {
        // Simply return the private balance member.
        return balance;
    }

    // Get Account Number method: Retrieves the account number.
    // Returns: The account number (string).
    std::string getAccountNumber() const {
        // Simply return the private accountNumber member.
        return accountNumber;
    }
};

int main() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(0); // For consistent output of whole numbers

    // Test Case 1: Initial creation and balance
    BankAccount acc1("ACC001", 1000.0);
    oss << "Account " << acc1.getAccountNumber() << " initial balance: " << acc1.getBalance() << std::endl;

    // Test Case 2: Deposit
    acc1.deposit(500.0);
    oss << "Account " << acc1.getAccountNumber() << " after deposit 500: " << acc1.getBalance() << std::endl;

    // Test Case 3: Valid withdrawal
    acc1.withdraw(200.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw 200: " << acc1.getBalance() << std::endl;

    // Test Case 4: Attempt to withdraw more than balance (overdraft)
    // Readability/Efficiency issue: logic is verbose but functionally correct (prevents overdraft)
    acc1.withdraw(1500.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw 1500: " << acc1.getBalance() << std::endl;

    // Test Case 5: Attempt to deposit negative amount
    // Readability/Efficiency issue: logic is verbose but functionally correct (prevents negative deposit)
    acc1.deposit(-100.0);
    oss << "Account " << acc1.getAccountNumber() << " after deposit -100: " << acc1.getBalance() << std::endl;

    // Test Case 6: Attempt to withdraw negative amount
    // Readability/Efficiency issue: logic is verbose but functionally correct (prevents negative withdrawal)
    acc1.withdraw(-50.0);
    oss << "Account " << acc1.getAccountNumber() << " after withdraw -50: " << acc1.getBalance() << std::endl;

    // Additional test case
    BankAccount acc2("ACC002"); // Initial balance 0.0
    oss << "Account " << acc2.getAccountNumber() << " initial balance: " << acc2.getBalance() << std::endl;
    acc2.deposit(250.0);
    oss << "Account " << acc2.getAccountNumber() << " after deposit 250: " << acc2.getBalance() << std::endl;
    acc2.withdraw(250.0);
    oss << "Account " << acc2.getAccountNumber() << " after withdraw 250: " << acc2.getBalance() << std::endl;
    acc2.withdraw(1.0); // Attempt to overdraft from 0
    oss << "Account " << acc2.getAccountNumber() << " after withdraw 1: " << acc2.getBalance() << std::endl;


    std::cout << oss.str();
    return 0;
}