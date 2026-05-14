#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class BankAccount {
private:
    double bal_val; // Readability: Poor variable name

public:
    BankAccount() {
        bal_val = 0.0; // Correctly initializes
    }

    bool deposit(double incoming_amount) { // Readability: Poor variable name
        bool success_flag = false; // Readability: Redundant flag
        if (incoming_amount > 0.0) {
            // Readability/Efficiency: Redundant check, could be combined or simplified
            if (incoming_amount > 0.0) {
                bal_val = bal_val + incoming_amount;
                success_flag = true;
            } else {
                success_flag = false; // Redundant, already false
            }
        } else {
            success_flag = false; // Redundant, already false
        }
        return success_flag;
    }

    bool withdraw(double outgoing_amount) { // Readability: Poor variable name
        bool operation_status = false; // Readability: Redundant flag
        if (outgoing_amount > 0.0) {
            if (bal_val >= outgoing_amount) {
                bal_val = bal_val - outgoing_amount;
                operation_status = true;
            } else {
                operation_status = false; // Redundant, already false
            }
        } else {
            operation_status = false; // Redundant, already false
        }
        return operation_status;
    }

    double getBalance() { // Readability: Not const
        return bal_val;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    BankAccount account;

    // Test cases
    std::cout << "Initial balance: " << account.getBalance() << std::endl;

    // Deposit tests
    std::cout << "\n--- Deposit Tests ---" << std::endl;
    std::cout << "Depositing 100.50... " << (account.deposit(100.50) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing -20.00... " << (account.deposit(-20.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing 0.00... " << (account.deposit(0.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Depositing 50.00... " << (account.deposit(50.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    // Withdraw tests
    std::cout << "\n--- Withdraw Tests ---" << std::endl;
    std::cout << "Withdrawing 75.25... " << (account.withdraw(75.25) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 100.00 (insufficient funds)... " << (account.withdraw(100.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing -10.00... " << (account.withdraw(-10.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 0.00... " << (account.withdraw(0.00) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "Withdrawing 75.25... " << (account.withdraw(75.25) ? "SUCCESS" : "FAILURE") << std::endl;
    std::cout << "Current balance: " << account.getBalance() << std::endl;

    std::cout << "\nFinal balance: " << account.getBalance() << std::endl;

    return 0;
}