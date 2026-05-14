#include <iostream>
#include <string>
#include <utility> // For std::move

class Product {
public:
    int productID;
    std::string name;
    double price;

    Product(int id, std::string n, double p) : productID(id), name(std::move(n)), price(p) {}

    // Overload == operator
    bool operator==(const Product& other) const {
        return productID == other.productID;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Product p1(1, "Laptop", 1200.0);
    Product p2(1, "Laptop Pro", 1500.0);
    Product p3(2, "Mouse", 25.0);
    Product p4(3, "Keyboard", 75.0);

    std::cout << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << (p1 == p3 ? "true" : "false") << std::endl;
    std::cout << (p3 == p4 ? "true" : "false") << std::endl;
    std::cout << (p1 == p1 ? "true" : "false") << std::endl;

    return 0;
}