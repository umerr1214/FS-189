#include <iostream>   // Required for std::cout and std::endl
#include <string>     // Required for std::string
#include <iomanip>    // Required for std::fixed and std::setprecision

// Define a struct Product with specified members.
// Members are public by default in a struct, allowing direct access.
struct Product {
    int id;
    std::string name;
    double price;
};

int main() {
    // Create an instance of Product using aggregate initialization for clarity and conciseness.
    Product myProduct = {101, "Laptop", 1200.50};

    // Print its details using direct stream output (std::cout).
    // Using std::fixed and std::setprecision(2) for consistent price formatting.
    std::cout << "Product ID: " << myProduct.id << std::endl;
    std::cout << "Product Name: " << myProduct.name << std::endl;
    std::cout << "Product Price: " << std::fixed << std::setprecision(2) << myProduct.price << std::endl;

    return 0; // Indicate successful execution
}