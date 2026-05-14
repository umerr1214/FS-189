#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::shared_ptr and std::weak_ptr

class Customer {
public:
    int id;
    std::string name;

    Customer(int id, const std::string& name) : id(id), name(name) {
        std::cout << "Customer " << name << " (ID: " << id << ") created." << std::endl;
    }

    ~Customer() {
        std::cout << "Customer " << name << " (ID: " << id << ") destroyed." << std::endl;
    }

    void display() const {
        std::cout << "Customer ID: " << id << ", Name: " << name;
    }
};

class Order {
public:
    int orderID;
    std::weak_ptr<Customer> customerWeakPtr; // Non-owning reference to Customer

    // Constructor takes a shared_ptr to ensure the Customer object is managed
    Order(int orderID, std::shared_ptr<Customer> customer) : orderID(orderID), customerWeakPtr(customer) {
        std::cout << "Order " << orderID << " created." << std::endl;
    }
    
    ~Order() {
        std::cout << "Order " << orderID << " destroyed." << std::endl;
    }

    void displayOrderDetails() const {
        // Attempt to get a shared_ptr from the weak_ptr.
        // This 'locks' the weak_ptr, ensuring the Customer object exists
        // and is valid for the duration of the returned shared_ptr's lifetime.
        if (std::shared_ptr<Customer> customer = customerWeakPtr.lock()) {
            std::cout << "Order ID: " << orderID << ", Placed by: ";
            customer->display();
        } else {
            // If lock() returns nullptr, the Customer object has been destroyed.
            std::cout << "Order ID: " << orderID << ", Placed by: Unknown Customer (deleted)";
        }
        std::cout << std::endl;
    }
};