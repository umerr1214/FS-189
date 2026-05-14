#include <iostream>
#include <string>

class Payment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() {}
};

class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {
        // Logical error: This should print "Credit Card" but prints "PayPal".
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        // Logical error: This should print "PayPal" but prints "Credit Card".
        std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    }
};

int main() {
    CreditCardPayment ccPayment;
    std::cout << "Test Case 1 (Credit Card):" << std::endl;
    ccPayment.processPayment(100.50);

    std::cout << "\nTest Case 2 (PayPal):" << std::endl;
    PayPalPayment ppPayment;
    ppPayment.processPayment(75.25);

    std::cout << "\nTest Case 3 (Credit Card):" << std::endl;
    ccPayment.processPayment(200.00);

    return 0;
}