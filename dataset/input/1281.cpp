#include <iostream>
#include <string>
#include <iomanip> // For setprecision
#include <algorithm> // For std::clamp

class Order {
protected:
    int orderId;
public:
    // Constructor using initializer list for efficient initialization
    Order(int id) : orderId(id) {}

    // Virtual display method, marked const to indicate it doesn't modify object state
    virtual void display() const {
        std::cout << "Order ID: " << orderId << std::endl;
    }
};

class SpecialOrder : public Order {
private:
    double discount; // Stored as a fraction (e.g., 0.10 for 10%)
public:
    // Constructor explicitly calling base class constructor (Order(id))
    // and using an initializer list for its own member (discount).
    // Includes basic validation for discount using std::clamp for robustness and correctness.
    SpecialOrder(int id, double disc) : Order(id), discount(std::clamp(disc, 0.0, 1.0)) {
        // std::clamp ensures discount is always between 0.0 (0%) and 1.0 (100%), inclusive.
        // This handles potentially invalid input values gracefully.
    }

    // Override display method, marked const, and uses 'override' keyword for clarity
    void display() const override {
        Order::display(); // Call base class display method
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  Discount: " << discount * 100 << "%" << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Correct Implementation ---" << std::endl;

    Order regularOrder(1001);
    regularOrder.display();
    std::cout << std::endl;

    SpecialOrder specialOrder1(2001, 0.10); // 10% discount
    specialOrder1.display();
    std::cout << std::endl;

    SpecialOrder specialOrder2(2002, 0.25); // 25% discount
    specialOrder2.display();
    std::cout << std::endl;

    // Test with invalid discount values to show robustness of the correct version's clamping
    std::cout << "--- Testing correct version's discount clamping ---" << std::endl;
    SpecialOrder specialOrder3(2003, -0.05); // Input -5%, should be clamped to 0%
    specialOrder3.display();
    std::cout << std::endl;

    SpecialOrder specialOrder4(2004, 1.50); // Input 150%, should be clamped to 100%
    specialOrder4.display();
    std::cout << std::endl;

    return 0;
}