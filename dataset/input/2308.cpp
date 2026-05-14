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

    // Constructor 2: (id, name) - chains to constructor 3 with default price
    Product(int id, std::string name) : Product(id, std::move(name), 0.0) {}

    // Constructor 1: (id) - chains to constructor 2 with default name
    Product(int id) : Product(id, "Unnamed Product") {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << std::fixed << std::setprecision(2) << price << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Product p1(101);
    Product p2(102, "Laptop");
    Product p3(103, "Mouse", 25.99);

    p1.display();
    p2.display();
    p3.display();

    return 0;
}