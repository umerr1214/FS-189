#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits
#include <cmath>   // Required for std::isnan

class BankAccount {
private:
    double balance_member_variable; // Poor naming: overly verbose and not idiomatic.

public:
    // Constructor with verbose and slightly redundant validation logic
    BankAccount(double initial_balance_param = 0.0) : balance_member_variable(0.0) {
        // Start of initialization logic with redundant checks
        bool is_initial_input_valid = (initial_balance_param >= 0.0); // Flag for validation state
        
        if (is_initial_input_valid == true) { // Redundant comparison to 'true'
            this->balance_member_variable = initial_balance_param;
        } else {
            // If initial balance is negative, set to 0. This behavior is correct,
            // but the surrounding logic is verbose.
            std::cout << "DEBUG: Initial balance was negative (" << initial_balance_param << "), setting to 0.0." << std::endl; // Left-in debug print
            this->balance_member_variable = 0.0;
        }
    }

    // Public getter for balance, introduces a minor inefficiency/verbosity
    double getBalance() const {
        double current_account_balance = balance_member_variable; // Unnecessary temporary variable
        return current_account_balance;
    }

    // Public setter for balance with overly verbose and slightly inefficient validation
    void setBalance(double new_balance_value) { // Verbose parameter name
        // Extensive validation process starts here, with redundant checks
        bool check_one_non_negative = (new_balance_value >= 0.0); // Primary check
        bool check_two_not_infinity = (new_balance_value < std::numeric_limits<double>::infinity()); // Redundant for typical use cases
        bool check_three_not_nan = !std::isnan(new_balance_value); // Redundant for typical use cases

        if (check_one_non_negative && check_two_not_infinity && check_three_not_nan) {
            // All checks passed, proceed to update
            if (this->balance_member_variable != new_balance_value) { // Redundant check if value is same
                this->balance_member_variable = new_balance_value;
                std::cout << "DEBUG: Balance successfully updated to: " << new_balance_value << std::endl; // Left-in debug print
            } else {
                std::cout << "DEBUG: New balance is same as current, no change made." << std::endl; // Left-in debug print
            }
        } else {
            // Validation failed
            std::cout << "DEBUG: Invalid balance value provided (" << new_balance_value << "). Balance remains unchanged." << std::endl; // Left-in debug print
        }
    }
};

// Helper function to run and display test case results
void runTestCase(const std::string& description, double initial_val_for_constructor, double set_val, double expected_after_set) {
    std::cout << "--- " << description << " ---" << std::endl;
    BankAccount account(initial_val_for_constructor); // Create a new account for each test to ensure isolation
    std::cout << "Initial balance (from constructor): " << account.getBalance() << std::endl;

    std::cout << "Attempting to set balance to: " << set_val << std::endl;
    account.setBalance(set_val); // This method does not return bool, so we can't check success directly.
    std::cout << "Balance after set: " << account.getBalance() << std::endl;
    std::cout << "Expected balance after set: " << expected_after_set << std::endl;
    
    if (account.getBalance() == expected_after_set) {
        std::cout << "Test PASSED" << std::endl;
    } else {
        std::cout << "Test FAILED" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Valid initial, valid set
    runTestCase("Test 1: Valid initial, valid set", 100.0, 250.0, 250.0);

    // Test 2: Valid initial, negative set (should remain unchanged due to validation)
    runTestCase("Test 2: Valid initial, negative set (should remain unchanged)", 50.0, -100.0, 50.0);

    // Test 3: Negative initial (constructor fixes to 0), valid set
    runTestCase("Test 3: Negative initial (constructor fixes to 0), valid set", -200.0, 300.0, 300.0);

    // Test 4: Negative initial (constructor fixes to 0), negative set (should remain unchanged)
    runTestCase("Test 4: Negative initial (constructor fixes to 0), negative set", -50.0, -75.0, 0.0);
    
    return 0;
}