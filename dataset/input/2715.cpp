#include <iostream>
#include <string> // For test cases output
#include <limits> // Generally good practice, though not strictly needed for this specific validation

class BankAccount {
private:
    double balance; // Encapsulated private member

public:
    // Constructor with robust input validation for initial balance
    BankAccount(double initialBalance = 0.0) : balance(0.0) {
        if (initialBalance >= 0.0) {
            balance = initialBalance;
        } else {
            // A correct and robust approach handles invalid initial values.
            // For this context, setting to 0.0 and printing a warning to stdout is clear.
            std::cout << "Warning: Initial balance cannot be negative. Setting to 0.0." << std::endl;
        }
    }

    // Public getter for balance, marked const as it does not modify the object state
    double getBalance() const {
        return balance;
    }

    // Public setter for balance with robust input validation.
    // Returns true on successful update, false otherwise, providing clear feedback.
    bool setBalance(double newBalance) {
        if (newBalance >= 0.0) {
            balance = newBalance;
            return true; // Successfully updated
        }
        // Input is invalid (negative).
        // A robust design signals failure without altering the object's state.
        return false; // Failed to update due to invalid input
    }
};

// Helper function to run and display test case results
void runTestCase(const std::string& description, double initial_val_for_constructor, double set_val, double expected_after_set, bool set_expected_success) {
    std::cout << "--- " << description << " ---" << std::endl;
    BankAccount account(initial_val_for_constructor); // Create a new account for each test to ensure isolation
    std::cout << "Initial balance (from constructor): " << account.getBalance() << std::endl;

    std::cout << "Attempting to set balance to: " << set_val << std::endl;
    bool set_success = account.setBalance(set_val);
    std::cout << "Set operation successful: " << (set_success ? "true" : "false") << std::endl;
    std::cout << "Balance after set: " << account.getBalance() << std::endl;
    std::cout << "Expected balance after set: " << expected_after_set << std::endl;
    
    // Check both the final balance and the success status of the set operation
    bool balance_correct = (account.getBalance() == expected_after_set);
    bool success_status_correct = (set_success == set_expected_success);

    if (balance_correct && success_status_correct) {
        std::cout << "Test PASSED" << std::endl;
    } else {
        std::cout << "Test FAILED" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Valid initial balance, valid set operation
    runTestCase("Test 1: Valid initial, valid set", 100.0, 250.0, 250.0, true);

    // Test 2: Valid initial balance, invalid (negative) set operation
    runTestCase("Test 2: Valid initial, negative set (should fail)", 50.0, -100.0, 50.0, false);

    // Test 3: Invalid (negative) initial balance (constructor handles), valid set operation
    runTestCase("Test 3: Negative initial (constructor handles), valid set", -200.0, 300.0, 300.0, true);

    // Test 4: Invalid (negative) initial balance, invalid (negative) set operation
    runTestCase("Test 4: Negative initial (constructor handles), negative set (should fail)", -50.0, -75.0, 0.0, false);
    
    // Test 5: Zero initial balance, valid set operation
    runTestCase("Test 5: Zero initial, valid set", 0.0, 150.0, 150.0, true);

    // Test 6: Zero initial balance, invalid (negative) set operation
    runTestCase("Test 6: Zero initial, negative set (should fail)", 0.0, -10.0, 0.0, false);

    return 0;
}