#include <iostream>
#include <string>
#include <vector>

class Customer {
public:
    int customerID;
    std::string name;

    Customer(int id, const std::string& n) : customerID(id), name(n) {}

    void displayCustomer() const {
        std::cout << "Customer ID: " << customerID << ", Name: " << name << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

class Order {
public:
    int orderID;
    Customer* customer; // Association: pointer

    Order(int id, Customer* cust) : orderID(id), customer(cust) {}

    void displayOrder() const {
        std::cout << "Order ID: " << orderID << std::endl;
        if (customer) {
            std::cout << "  Placed by Customer ID: " << customer->customerID << ", Name: " << customer->name << std::endl;
        } else {
            std::cout << "  Customer information not available." << std::endl;
        }
    }
};

int main() {
    Customer cust1(101, "Alice Smith");
    Order order1(1001, &cust1);

    cust1.displayCustomer();
    order1.displayOrder();

    return 0;
}