#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::find_if
#include <optional>    // For returning optional customer reference
#include <functional>  // For std::reference_wrapper

class Customer {
public:
    int id;
    std::string name;

    Customer(int id, const std::string& name) : id(id), name(name) {}

    void display() const {
        std::cout << "Customer ID: " << id << ", Name: " << name;
    }
};

class Order {
public:
    int orderID;
    int customerID; // Stores customer ID instead of a direct reference/pointer

    Order(int orderID, int customerID) : orderID(orderID), customerID(customerID) {}

    // Efficiency Issue: This method requires iterating through a list of all customers
    // every time it's called, making it O(N) where N is the number of customers.
    // A direct pointer/reference would provide O(1) access.
    std::optional<std::reference_wrapper<const Customer>> getCustomer(const std::vector<Customer>& allCustomers) const {
        for (const Customer& c : allCustomers) {
            if (c.id == customerID) {
                return std::make_optional(std::cref(c));
            }
        }
        return std::nullopt;
    }

    // Readability/Design Issue: The Order class is not self-contained for displaying
    // customer details, requiring an external list of all customers to be passed.
    void displayOrderDetails(const std::vector<Customer>& allCustomers) const {
        std::cout << "Order ID: " << orderID << ", Placed by: ";
        std::optional<std::reference_wrapper<const Customer>> customerRef = getCustomer(allCustomers);
        if (customerRef.has_value()) {
            customerRef->get().display();
        } else {
            std::cout << "Unknown Customer (ID: " << customerID << ")";
        }
        std::cout << std::endl;
    }
};