#include <iostream>
#include <string>
#include <iomanip>

class Order {
protected:
    int o_id; // Readability Issue: Poor variable name
public:
    // Readability Issue: Not using initializer list, uses this-> in constructor body
    Order(int id_val) {
        this->o_id = id_val; // Redundant use of this->
    }

    // Readability Issue: Not marked const, even though it doesn't modify state
    virtual void display() {
        std::cout << "Order ID: " << this->o_id << std::endl; // Redundant use of this->
    }
};

class SpecialOrder : public Order {
private:
    double disc_val; // Readability Issue: Poor variable name
public:
    // Constructor explicitly calling base class constructor, but uses this-> for its own member
    // Readability Issue: 'd_amount' is an abbreviated and less clear parameter name.
    SpecialOrder(int base_id, double d_amount) : Order(base_id) {
        this->disc_val = d_amount; // Redundant use of this->
    }

    // Readability Issue: Not marked const, even though it doesn't modify state
    void display() override {
        Order::display(); // Call base class display
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "  Discount Amount: " << this->disc_val * 100 << "%" << std::endl; // Redundant use of this->
    }
};

int main() {
    std::cout << "--- Demonstrating Readability/Efficiency Issues ---" << std::endl;

    Order firstOrder(101);
    firstOrder.display();
    std::cout << std::endl;

    SpecialOrder specialOne(201, 0.10); // 10% discount
    specialOne.display();
    std::cout << std::endl;

    SpecialOrder specialTwo(202, 0.25); // 25% discount
    specialTwo.display();
    std::cout << std::endl;

    return 0;
}