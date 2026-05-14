#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
private:
    int id;
    std::string name;
    double price;

public:
    // Single constructor with default arguments
    // Robustness Issue 1: Allows negative IDs, which might be invalid in real-world scenarios.
    Product(int id = 0, std::string name = "Unnamed", double price = 0.0)
        : id(id), name(name), price(price) {
        // No validation for id, e.g., id < 0 is allowed, potentially leading to invalid object state.
    }

    // Getters
    int getId() const {
        return id;
    }

    // Robustness Issue 2: Returns a non-const reference to 'name',
    // allowing external modification of the private member, breaking encapsulation.
    std::string& getName() {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    std::stringstream ss;

    // Test Case 1: All arguments provided
    Product p1(101, "Laptop Pro", 1200.50);
    ss << "P1 Initial: ID=" << p1.getId() << ", Name=" << p1.getName() << ", Price=" << std::fixed << std::setprecision(2) << p1.getPrice() << "\n";

    // Test Case 2: Only id and name (price defaults to 0.0)
    Product p2(202, "Wireless Mouse");
    ss << "P2 Initial: ID=" << p2.getId() << ", Name=" << p2.getName() << ", Price=" << std::fixed << std::setprecision(2) << p2.getPrice() << "\n";

    // Test Case 3: No arguments (all default)
    Product p3;
    ss << "P3 Initial: ID=" << p3.getId() << ", Name=" << p3.getName() << ", Price=" << std::fixed << std::setprecision(2) << p3.getPrice() << "\n";

    // Demonstrate Robustness Issue 1: Negative ID is allowed
    Product p4(-500, "Invalid Product ID", 10.00);
    ss << "P4 (Negative ID): ID=" << p4.getId() << ", Name=" << p4.getName() << ", Price=" << std::fixed << std::setprecision(2) << p4.getPrice() << "\n";

    // Demonstrate Robustness Issue 2: External modification of name via non-const reference
    Product p5(505, "Old Name", 25.00);
    ss << "P5 Before Modification: ID=" << p5.getId() << ", Name=" << p5.getName() << ", Price=" << std::fixed << std::setprecision(2) << p5.getPrice() << "\n";
    
    p5.getName() = "New Name Via Reference"; // Direct modification of private member
    ss << "P5 After Modification: ID=" << p5.getId() << ", Name=" << p5.getName() << ", Price=" << std::fixed << std::setprecision(2) << p5.getPrice() << "\n";


    std::cout << ss.str();
    return 0;
}