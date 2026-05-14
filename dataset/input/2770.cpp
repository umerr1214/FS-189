#include <iostream>
#include <string>

class Payment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() {}
}; // Missing semicolon here intentionally for syntax error

class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

int main() {
    // This code is intended to demonstrate usage if the syntax error were fixed.
    // It won't compile due to the intentional syntax error.
    CreditCardPayment ccPayment;
    ccPayment.processPayment(100.50);

    PayPalPayment ppPayment;
    ppPayment.processPayment(75.25);

    return 0;
}