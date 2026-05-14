#include <iostream>
#include <string>
#include <vector>
#include <memory> // Included for general C++ practice, though not strictly used for raw pointers here

class Customer {
public:
    int id;
    std::string name;

    Customer(int id, const std::string& name) : id(id), name(name) {
        std::cout << "Customer " << name << " (ID: " << id << ") created." << std::endl;
    }

    ~Customer() {
        // This destructor will only be called if the Customer object is destroyed.
        // For dynamically allocated objects managed by raw pointers, this requires explicit 'delete'.
        std::cout << "Customer " << name << " (ID: " << id << ") destroyed." << std::endl;
    }

    void display() const {
        std::cout << "Customer ID: " << id << ", Name: " << name;
    }
};

class Order {
public:
    int orderID;
    Customer* customerPtr; // Raw pointer to Customer

    Order(int orderID, Customer* customer) : orderID(orderID), customerPtr(customer) {
        std::cout << "Order " << orderID << " created." << std::endl;
    }

    ~Order() {
        std::cout << "Order " << orderID << " destroyed." << std::endl;
        // Robustness Issue: The Order class does not manage the lifetime of customerPtr.
        // If customerPtr points to a dynamically allocated Customer, and no other code deletes it,
        // this will lead to a memory leak. Consistent with "without strict ownership", Order
        // should not delete the Customer, but the overall program must ensure deletion.
    }

    void displayOrderDetails() const {
        std::cout << "Order ID: " << orderID << ", Placed by: ";
        if (customerPtr) {
            customerPtr->display();
        } else {
            std::cout << "Unknown Customer (nullptr)";
        }
        std::cout << std::endl;
    }
};