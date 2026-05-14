#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
public:
    int id;
    std::string name;
    double price;

    // Default constructor required for C-style arrays if not explicitly initialized
    Product() : id(0), name(""), price(0.0) {}
    Product(int i, const std::string& n, double p) : id(i), name(n), price(p) {}

    void display() const {
        std::cout << "ID: " << id
                  << ", Name: " << name
                  << ", Price: $" << std::fixed << std::setprecision(2) << price << '\n';
    }
};

int main() {
    // Define a fixed-size C-style array
    const int NUM_PRODUCTS = 3;
    Product products[NUM_PRODUCTS]; // Array of 3 Product objects

    // Populate the array with data
    products[0] = Product(101, "Laptop", 1200.50);
    products[1] = Product(102, "Mouse", 25.00);
    products[2] = Product(103, "Keyboard", 75.99);

    std::cout << "--- Product Details (Robustness Issue) ---\n";
    // Iterate through the array to display details of each product
    // This loop introduces an off-by-one error, accessing out of bounds
    for (int i = 0; i <= NUM_PRODUCTS; ++i) { // Loop goes from 0 to NUM_PRODUCTS (inclusive)
                                            // This accesses products[NUM_PRODUCTS] which is out of bounds
        std::cout << "Product " << i + 1 << ": ";
        // Accessing products[NUM_PRODUCTS] leads to undefined behavior.
        // If the Product class has a default constructor, it might print default values.
        products[i].display();
    }

    return 0;
}