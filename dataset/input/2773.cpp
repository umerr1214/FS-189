#include <iostream>
#include <string>
#include <vector>

// Base class
class Payment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() = default;
};

// Derived class 1: CreditCardPayment
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        // Robustness issue: No validation for amount.
        // It will "process" negative or zero amounts without error,
        // which is usually an invalid state for a payment system.
        std::cout << "Processing Credit Card payment for $" << amount << "." << std::endl;
        std::cout << "Transaction ID: CC_XYZ123. Funds usually clear within 1-2 business days." << std::endl;
    }
};

// Derived class 2: PayPalPayment
class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        // Robustness issue: No validation for amount.
        // It will "process" negative or zero amounts without error.
        std::cout << "Processing PayPal payment for $" << amount << "." << std::endl;
        std::cout << "Reference: PP_ABC789. Instant notification sent to merchant." << std::endl;
    }
};

int main() {
    // Test cases demonstrating the robustness issue
    CreditCardPayment ccPayment;
    PayPalPayment ppPayment;

    std::cout << "--- Test Case 1: Valid amount ---" << std::endl;
    ccPayment.processPayment(100.50);
    std::cout << std::endl;

    std::cout << "--- Test Case 2: Negative amount (Robustness Issue) ---" << std::endl;
    ppPayment.processPayment(-25.00); // Should ideally be rejected or error
    std::cout << std::endl;

    std::cout << "--- Test Case 3: Zero amount (Robustness Issue) ---" << std::endl;
    ccPayment.processPayment(0.00); // Should ideally be rejected or error
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Another valid amount ---" << std::endl;
    ppPayment.processPayment(75.25);
    std::cout << std::endl;

    return 0;
}