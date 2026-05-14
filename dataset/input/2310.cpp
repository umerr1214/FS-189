#include <string>
#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
public:
    int id;
    std::string name;
    double price; // POD type, will be uninitialized if not set in constructor

    // Constructor 3: (id, name, price) - primary constructor for chaining
    Product(int id, std::string name, double price) : id(id), name(std::move(name)), price(price) {}

    // Constructor 2: (id, name) - SEMANTIC ERROR: 'price' member is not initialized.
    // Its value will be indeterminate (undefined behavior) when accessed.
    Product(int id, std::string name) : id(id), name(std::move(name)) {
        // 'price' is left uninitialized here.
        // It should either chain: Product(id, std::move(name), 0.0)
        // or explicitly initialize: price = 0.0;
    }

    // Constructor 1: (id) - chains to constructor 2, which has the uninitialized price issue
    Product(int id) : Product(id, "Unnamed Product") {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

int main() {
    Product p1(101); // Calls constructor 2, price uninitialized
    Product p2(102, "Laptop"); // Calls constructor 2, price uninitialized
    Product p3(103, "Mouse", 25.99); // Correctly initialized price

    p1.display(); // Accessing uninitialized p1.price -> Undefined Behavior
    p2.display(); // Accessing uninitialized p2.price -> Undefined Behavior
    p3.display();

    return 0;
}