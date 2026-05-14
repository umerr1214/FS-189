#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
private:
    int _id; // Using non-standard prefix for private members, slightly impacting readability for some.
    std::string _name;
    double _price;

public:
    // Single constructor with default arguments
    // Efficiency Issue: 'name' is passed by value, causing an unnecessary copy.
    // Readability/Efficiency Issue: Members are initialized using assignment in the constructor body
    // instead of an initializer list, which is less efficient for non-trivial types like std::string
    // and generally considered less idiomatic C++.
    Product(int id = 0, std::string name = "Unnamed", double price = 0.0) {
        this->_id = id;
        this->_name = name; // This assignment causes a second copy after the parameter 'name' itself is constructed.
        this->_price = price;
    }

    // Getters are fine here, the issues are in the constructor.
    int getId() const {
        return _id;
    }

    const std::string& getName() const {
        return _name;
    }

    double getPrice() const {
        return _price;
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

    // Additional test to confirm functionality despite inefficiencies
    Product p4(404, "Charger", 45.99);
    ss << "P4: ID=" << p4.getId() << ", Name=" << p4.getName() << ", Price=" << std::fixed << std::setprecision(2) << p4.getPrice() << "\n";


    std::cout << ss.str();
    return 0;
}