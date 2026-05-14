#include <iostream>
#include <string>

class Customer {
public:
    int customerID;
    std::string name;

    Customer(int id, const std::string& n) : customerID(id), name(n) {}

    void setName(const std::string& newName) {
        name = newName;
    }

    void displayCustomer() const {
        std::cout << "Customer ID: " << customerID << ", Name: " << name << std::endl;
    }
};

class Order {
public:
    int orderID;
    Customer customer; // LOGICAL ERROR: Storing Customer by value instead of a pointer/reference

    Order(int id, const Customer& cust) : orderID(id), customer(cust) {} // Copies the Customer object

    void displayOrder() const {
        std::cout << "Order ID: " << orderID << std::endl;
        std::cout << "  Placed by Customer ID: " << customer.customerID << ", Name: " << customer.name << std::endl;
    }
};

int main() {
    Customer cust1(101, "Alice Smith");
    Order order1(1001, cust1); // Passes a copy of cust1

    std::cout << "--- Initial State ---" << std::endl;
    cust1.displayCustomer();
    order1.displayOrder();

    // Change the original customer's name
    cust1.setName("Alice Wonderland");
    std::cout << "\n--- After Customer Name Change ---" << std::endl;
    cust1.displayCustomer(); // Original customer reflects change
    order1.displayOrder();   // Order's customer does NOT reflect change (it's a copy)

    return 0;
}