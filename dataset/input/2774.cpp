#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common for C++ programs

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
        // Readability/Efficiency Issue: Overly verbose string construction
        // and redundant intermediate variables.
        std::string msg1_part1 = "Initiating Credit Card payment for ";
        std::string amount_str = std::to_string(amount); // Uses std::to_string, which can add trailing zeros
        std::string msg1_part2 = "$";
        std::string msg1 = msg1_part1 + msg1_part2 + amount_str + ".";
        std::cout << msg1 << std::endl;

        std::string details_line = std::string("Authorization code: ") + "CC_AUTH_987. " + "Please wait for confirmation.";
        std::cout << details_line << std::endl;
        std::cout << std::endl; // Unnecessary extra newline here
    }
};

// Derived class 2: PayPalPayment
class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        // Readability/Efficiency Issue: Repetitive and less efficient string ops
        // and unnecessary conditional logic for a simple print.
        std::string initial_message = "Processing PayPal transaction.";
        std::cout << initial_message << std::endl;

        if (amount > 0) { // Unnecessary check for merely printing details, not for actual validation/logic here
            std::string amount_info = "Amount: $" + std::to_string(amount);
            std::string ref_info = "Reference ID: PP_REF_456.";
            std::string status_info = "Status: Pending merchant confirmation.";
            std::cout << amount_info << " " << ref_info << " " << status_info << std::endl;
        } else {
            // This else branch is unlikely to be hit with typical valid inputs,
            // but the 'if' itself is unnecessary for merely printing details.
            std::cout << "Payment details could not be retrieved." << std::endl;
        }
        std::cout << std::endl; // Another unnecessary extra newline
    }
};

int main() {
    // Test cases
    CreditCardPayment ccPayment;
    PayPalPayment ppPayment;

    std::cout << "--- Processing payments ---" << std::endl;
    ccPayment.processPayment(250.75);
    ppPayment.processPayment(50.00);
    ccPayment.processPayment(123.45); // Using a different amount to show it's generic

    return 0;
}