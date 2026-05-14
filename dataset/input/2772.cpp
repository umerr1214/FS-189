#include <iostream>
#include <string>

class Payment {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payment() {}
};

class CreditCardPayment : public Payment {
    // Semantic error: Forgot to implement the pure virtual method processPayment,
    // making CreditCardPayment an abstract class.
    // Therefore, it cannot be instantiated directly.
public:
    void anotherMethod() {
        std::cout << "This is another method in CreditCardPayment." << std::endl;
    }
};

class PayPalPayment : public Payment {
public:
    void processPayment(double amount) override {
        std::cout << "Processing PayPal payment of $" << amount << std::endl;
    }
};

int main() {
    // This line will cause a semantic error (cannot instantiate abstract class)
    // because CreditCardPayment does not implement processPayment.
    CreditCardPayment ccPayment;
    ccPayment.anotherMethod(); // This call would be fine if ccPayment could be instantiated.

    PayPalPayment ppPayment;
    ppPayment.processPayment(75.25);

    return 0;
}