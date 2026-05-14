#include <iostream>
#include <string> // For test cases output

class BankAccount {
private:
    double balance;

public:
    // Constructor allows negative initial balance - Robustness Issue
    // A robust design would validate this input or throw an exception.
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {
        // No validation here, allows negative initial balance.
        // This can lead to an invalid state for a bank account.
    }

    double getBalance() const {
        return balance;
    }

    // setBalance has flawed input handling - Robustness Issue
    // It silently "corrects" invalid input instead of rejecting it or providing feedback.
    void setBalance(double newBalance) {
        if (newBalance < 0.0) {
            // Robustness Issue: Instead of rejecting the input (e.g., returning false,
            // throwing an exception, or keeping the old balance), it silently
            // sets the balance to 0.0. This can hide bugs in calling code
            // that might expect the operation to fail for invalid input.
            balance = 0.0;
        } else {
            balance = newBalance;
        }
    }
};

// Helper function to run and display test case results
void runTestCase(const std::string& description, double initial_val_for_constructor, double set_val, double expected_after_set) {
    std::cout << "--- " << description << " ---" << std::endl;
    BankAccount account(initial_val_for_constructor); // Create a new account for each test to ensure isolation
    std::cout << "Initial balance set by constructor: " << initial_val_for_constructor << std::endl;
    std::cout << "Current balance (after constructor): " << account.getBalance() << std::endl;

    std::cout << "Attempting to set balance to: " << set_val << std::endl;
    account.setBalance(set_val);
    std::cout << "Balance after set: " << account.getBalance() << std::endl;
    std::cout << "Expected balance after set: " << expected_after_set << std::endl;
    
    // Using a small epsilon for double comparison if precision issues are expected,
    // but for integer-like doubles, direct comparison is usually fine for these tests.
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

    // Test 2: Valid initial, negative set (demonstrates setBalance robustness issue)
    runTestCase("Test 2: Valid initial, negative set (robustness issue in setBalance)", 50.0, -100.0, 0.0); // Expects 0.0 due to robustness issue

    // Test 3: Negative initial (demonstrates constructor robustness issue), valid set
    runTestCase("Test 3: Negative initial (robustness issue in constructor), valid set", -200.0, 300.0, 300.0); // Constructor allows -200, then setBalance works

    // Test 4: Negative initial and negative set (combines both robustness issues)
    runTestCase("Test 4: Negative initial (constructor) & negative set (setBalance)", -50.0, -75.0, 0.0); // Constructor allows -50, then setBalance changes to 0
    
    return 0;
}