#include <iostream>
#include <string>
#include <iomanip> // For setprecision

class Order {
protected:
    int orderId;
public:
    // Constructor using initializer list
    Order(int id) : orderId(id) {}

    // Virtual display method, marked const
    virtual void display() const {
        std::cout << "Order ID: " << orderId << std::endl;
    }
};

class SpecialOrder : public Order {
private:
    double discount; // Stored as a fraction (e.g., 0.10 for 10%)
public:
    // Robustness Issue: No validation for 'discount' parameter.
    // Allows negative or excessively high discount values without any error handling
    // or clamping, which can lead to illogical order data.
    SpecialOrder(int id, double disc) : Order(id), discount(disc) {
        // A robust implementation would validate 'disc' here, e.g.,
        // if (disc < 0.0 || disc > 1.0) { /* handle error or clamp value */ }
    }

    // Override display method, marked const
    void display() const override {
        Order::display(); // Call base class display
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  Discount: " << discount * 100 << "%" << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Robustness Issue (Invalid Discounts) ---" << std::endl;

    Order order1(1001);
    order1.display();
    std::cout << std::endl;

    // Valid special order
    SpecialOrder specialOrder1(2001, 0.15); // 15% discount
    specialOrder1.display();
    std::cout << std::endl;

    // Robustness issue: Negative discount (effectively a surcharge)
    SpecialOrder specialOrder2(2002, -0.10); // -10% discount
    specialOrder2.display();
    std::cout << std::endl;

    // Robustness issue: Discount > 100%
    SpecialOrder specialOrder3(2003, 1.50); // 150% discount
    specialOrder3.display();
    std::cout << std::endl;

    return 0;
}