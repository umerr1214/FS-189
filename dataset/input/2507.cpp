#include <iostream>
#include <string>
#include <utility> // For std::move

class Product {
public:
    int productID;
    std::string name;
    double price;

    Product(int id, std::string n, double p) : productID(id), name(std::move(n)), price(p) {}

    // Overload == operator with logical error: compares name instead of productID
    bool operator==(const Product& other) const {
        return name == other.name; // LOGICAL ERROR: Should compare productID
    }
};

int main() {
    Product p1(1, "Laptop", 1200.0);
    Product p2(1, "Laptop Pro", 1500.0); // Same ID, different name
    Product p3(2, "Mouse", 25.0);
    Product p4(3, "Keyboard", 75.0);

    std::cout << (p1 == p2 ? "true" : "false") << std::endl; // Expected true (by ID), Actual false (by name)
    std::cout << (p1 == p3 ? "true" : "false") << std::endl; // Expected false (by ID), Actual false (by name)
    std::cout << (p3 == p4 ? "true" : "false") << std::endl; // Expected false (by ID), Actual false (by name)
    std::cout << (p1 == p1 ? "true" : "false") << std::endl; // Expected true (by ID), Actual true (by name)

    return 0;
}