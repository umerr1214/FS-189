#include <string>
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
public:
    int id;
    std::string name;
    double price;

    // Constructor 3: (id, name, price) - primary constructor for chaining
    Product(int id, std::string name, double price) : id(id), name(std::move(name)), price(price) {}

    // Constructor 2: (id, name) - LOGICAL ERROR: Does not chain to the (id, name, price) constructor.
    // Instead, it directly initializes members and sets a non-zero default price (1.0)
    // where 0.0 was expected by chaining convention.
    Product(int id, std::string name) : id(id), name(std::move(name)), price(1.0) {} // Should be: Product(id, std::move(name), 0.0)

    // Constructor 1: (id) - chains to constructor 2
    Product(int id) : Product(id, "Unnamed Product") {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

int main() {
    Product p1(101); // Expected price 0.00, will be 1.00
    Product p2(102, "Laptop"); // Expected price 0.00, will be 1.00
    Product p3(103, "Mouse", 25.99); // Correctly initialized price

    p1.display();
    p2.display();
    p3.display();

    return 0;
}