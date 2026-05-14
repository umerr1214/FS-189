#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

// Base class
class Payment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() = default; // Virtual destructor for proper cleanup in polymorphic hierarchies
};

// Derived class 1: CreditCardPayment
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            std::cout << "Credit Card Payment Error: Invalid amount $" << amount << ". Amount must be positive." << std::endl;
            return;
        }
        std::cout << "Credit Card Payment: Successfully processed $" << amount << "." << std::endl;
        std::cout << "Confirmation: CC_CONF_789. Funds expected in 1-2 business days." << std::endl;
    }
};

// Derived class 2: PayPalPayment
class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        if (amount <= 0) {
            std::cout << "PayPal Payment Error: Invalid amount $" << amount << ". Amount must be positive." << std::endl;
            return;
        }
        std::cout << "PayPal Payment: Transaction completed for $" << amount << "." << std::endl;
        std::cout << "Reference: PP_TRANS_321. Instant notification sent." << std::endl;
    }
};

int main() {
    // Using smart pointers for better memory management and polymorphism
    std::vector<std::unique_ptr<Payment>> payments;
    payments.push_back(std::make_unique<CreditCardPayment>());
    payments.push_back(std::make_unique<PayPalPayment>());

    std::cout << "--- Testing Payment Processing (Correct Version) ---" << std::endl;
    std::cout << std::endl;

    // Test with valid amounts
    std::cout << "Attempting valid payments:" << std::endl;
    payments[0]->processPayment(150.75); // Credit Card
    std::cout << std::endl;
    payments[1]->processPayment(80.00);  // PayPal
    std::cout << std::endl;

    // Test with invalid amounts (robustness handled)
    std::cout << "Attempting invalid payments:" << std::endl;
    payments[0]->processPayment(-10.00); // Credit Card with negative amount
    std::cout << std::endl;
    payments[1]->processPayment(0.00);   // PayPal with zero amount
    std::cout << std::endl;

    return 0;
}