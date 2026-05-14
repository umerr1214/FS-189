#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision
#include <sstream> // For std::stringstream (inefficient use)

class BankAccount {
private:
    double current_account_balance; // Readability Issue: Overly verbose member variable name

public:
    BankAccount(double starting_amount = 0.0) : current_account_balance(starting_amount) {
        if (current_account_balance < 0.0) {
            current_account_balance = 0.0;
            std::cout << "Initial balance cannot be negative, set to 0.00." << std::endl;
        }
    }

    void deposit(double deposit_amount_value) { // Readability Issue: Overly verbose parameter name
        if (deposit_amount_value > 0.0) {
            current_account_balance = current_account_balance + deposit_amount_value; // Readability/Efficiency Issue: Redundant assignment, could use `+=`
            std::cout << "Operation: Deposit. Amount: " << std::fixed << std::setprecision(2) << deposit_amount_value << ". Current Balance After Deposit: " << current_account_balance << std::endl << std::endl; // Efficiency Issue: Excessive `std::endl` flushes the stream multiple times
        } else {
            std::cout << "Deposit amount must be positive. No action taken." << std::endl << std::endl; // Efficiency Issue: Excessive `std::endl`
        }
    }

    bool withdraw(double withdrawal_request_amount) { // Readability Issue: Overly verbose parameter name
        bool operation_successful_flag = false; // Readability/Efficiency Issue: Unnecessary flag variable
        if (withdrawal_request_amount > 0.0) {
            double potential_new_balance = current_account_balance - withdrawal_request_amount; // Efficiency Issue: Creates a temporary variable for a simple check
            if (potential_new_balance >= 0.0) {
                current_account_balance = potential_new_balance;
                std::stringstream ss; // Efficiency Issue: Using stringstream for simple output is less efficient than direct `std::cout` streaming
                ss << "Withdrawal Successful. Amount: " << std::fixed << std::setprecision(2) << withdrawal_request_amount << ". New Balance: " << current_account_balance;
                std::cout << ss.str() << std::endl; // Prints stringstream content
                operation_successful_flag = true;
            } else {
                std::cout << "Funds insufficient for " << std::fixed << std::setprecision(2) << withdrawal_request_amount << ". Available: " << current_account_balance << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive. No action." << std::endl;
        }
        return operation_successful_flag;
    }

    double getBalance() { // Readability/Correctness Issue: Missing `const` qualifier
        return current_account_balance;
    }
};