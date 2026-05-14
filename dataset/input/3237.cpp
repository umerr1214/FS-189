#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

// Define a Product class
class Product {
public:
    int id;
    std::string name;
    double price;

    // Constructor to initialize member variables
    Product(int i, const std::string& n, double p)
        : id(i), name(n), price(p) {}

    // Method to display product details
    void display() const {
        std::cout << "ID: " << id
                  << ", Name: " << name
                  << ", Price: $" << std::fixed << std::setprecision(2) << price << '\n';
    }
};

int main() {
    // Create a std::vector of Product objects for dynamic array management
    std::vector<Product> products;

    // Populate the vector with data using emplace_back for efficiency
    products.emplace_back(101, "Laptop", 1200.50);
    products.emplace_back(102, "Mouse", 25.00);
    products.emplace_back(103, "Keyboard", 75.99);

    std::cout << "--- Product Details (Correct Version) ---\n";
    // Iterate through the vector using a range-based for loop to display details
    for (const auto& product : products) {
        product.display();
    }

    return 0;
}