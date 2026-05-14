#include <iostream>
#include <string>

class Customer {
public:
    int customerID;
    std::string name;

    Customer(int id, const std::string& n) : customerID(id), name(n) {
        std::cout << "Customer " << name << " created." << std::endl;
    }

    ~Customer() {
        std::cout << "Customer " << name << " destroyed." << std::endl;
    }

    void displayCustomer() const {
        std::cout << "Customer ID: " << customerID << ", Name: " << name << std::endl;
    }
};

class Order {
public:
    int orderID;
    Customer* customer; // Correctly uses a pointer for association

    Order(int id, Customer* cust) : orderID(id), customer(cust) {
        std::cout << "Order " << orderID << " created." << std::endl;
    }

    ~Order() {
        std::cout << "Order " << orderID << " destroyed." << std::endl;
    }

    void displayOrder() const {
        std::cout << "Order ID: " << orderID << std::endl;
        // SEMANTIC ERROR: Dereferencing a dangling pointer if 'customer' points to an out-of-scope object
        if (customer) {
            std::cout << "  Placed by Customer ID: " << customer->customerID << ", Name: " << customer->name << std::endl;
        } else {
            std::cout << "  Customer information not available (nullptr)." << std::endl;
        }
    }
};

int main() {
    Order order1(0, nullptr); // Initialize order1

    { // Create a local scope for cust1
        Customer cust1(101, "Alice Smith");
        order1 = Order(1001, &cust1); // Assigns the address of a local variable to order1.customer
    } // cust1 is destroyed here, making order1.customer a dangling pointer

    std::cout << "\n--- Attempting to display order after customer is destroyed ---" << std::endl;
    // This will lead to undefined behavior (e.g., segmentation fault or garbage output)
    // because order1.customer is a dangling pointer.
    order1.displayOrder();

    return 0;
}