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
    // Uses initializer list for efficient member initialization.
    // 'name' parameter is passed by const reference to avoid unnecessary copies.
    Product(int id = 0, const std::string& name = "Unnamed", double price = 0.0)
        : id(id), name(name), price(price) {}

    // Getters are declared const to indicate they do not modify the object's state.
    // 'name' getter returns a const reference for efficiency and to maintain encapsulation.
    int getId() const {
        return id;
    }

    const std::string& getName() const {
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
    ss << "P1: ID=" << p1.getId() << ", Name=" << p1.getName() << ", Price=" << std::fixed << std::setprecision(2) << p1.getPrice() << "\n";

    // Test Case 2: Only id and name (price defaults to 0.0)
    Product p2(202, "Wireless Mouse");
    ss << "P2: ID=" << p2.getId() << ", Name=" << p2.getName() << ", Price=" << std::fixed << std::setprecision(2) << p2.getPrice() << "\n";

    // Test Case 3: No arguments (all default)
    Product p3;
    ss << "P3: ID=" << p3.getId() << ", Name=" << p3.getName() << ", Price=" << std::fixed << std::setprecision(2) << p3.getPrice() << "\n";

    // Additional test cases for completeness
    Product p4(404, "External SSD", 150.75);
    ss << "P4: ID=" << p4.getId() << ", Name=" << p4.getName() << ", Price=" << std::fixed << std::setprecision(2) << p4.getPrice() << "\n";

    Product p5(505, "Keyboard"); // Price defaults
    ss << "P5: ID=" << p5.getId() << ", Name=" << p5.getName() << ", Price=" << std::fixed << std::setprecision(2) << p5.getPrice() << "\n";

    std::cout << ss.str();
    return 0;
}