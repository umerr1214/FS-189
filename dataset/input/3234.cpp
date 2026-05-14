#include <iostream>
#include <string>

class Product {
public:
    int id;
    std::string name;
    double price;

    Product(int i, const std::string& n, double p) : id(i), name(n), price(p) {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << std::endl;
    }
};

int main() {
    // Array of Product objects
    Product products[] = {
        Product(101, "Laptop", 1200.00),
        Product(102, "Mouse", 25.50),
        Product(103, "Keyboard", 75.00)
    };

    // Number of products
    int numProducts = sizeof(products) / sizeof(products[0]); // numProducts is 3

    // Iterate through the array and display details
    // SEMANTIC ERROR: The loop condition `i <= numProducts` causes an out-of-bounds access
    // when i becomes equal to numProducts (i.e., products[3]). This leads to undefined behavior.
    for (int i = 0; i <= numProducts; ++i) { // Should be i < numProducts
        products[i].display();
    }

    return 0;
}