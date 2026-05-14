#include <iostream>

class Order {
protected:
    int orderId;
public:
    Order(int id) : orderId(id) {
        // Constructor implementation
    }
    // No default constructor for Order
    virtual void display() const {
        std::cout << "Order ID: " << orderId;
    }
};

class SpecialOrder : public Order {
private:
    double discount;
public:
    // Semantic Error: Fails to explicitly call the base class constructor in the initializer list.
    // Since Order has no default constructor, this will result in a compilation error.
    SpecialOrder(int id, double disc) : discount(disc) { // Missing : Order(id)
        // Constructor body (too late to call base constructor here)
    }
    void display() const override {
        Order::display();
        std::cout << ", Discount: " << discount << "%";
    }
};

int main() {
    Order o1(101);
    o1.display();
    std::cout << std::endl;

    // This line will cause a compilation error due to the semantic issue in SpecialOrder's constructor
    SpecialOrder so1(201, 10.5);
    so1.display();
    std::cout << std::endl;

    return 0;
}