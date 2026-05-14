#include <iostream>

class Order {
protected:
    int orderId;
public:
    Order(int id) : orderId(id) {
        // Constructor implementation
    }
    virtual void display() const {
        std::cout << "Order ID: " << orderId;
    }
} // Syntax Error: Missing semicolon here

class SpecialOrder : public Order {
private:
    double discount;
public:
    SpecialOrder(int id, double disc) : Order(id), discount(disc) {
        // Constructor implementation
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

    SpecialOrder so1(201, 10.5);
    so1.display();
    std::cout << std::endl;

    return 0;
}