#include <iostream>
#include <string>
#include <cstdio> // For printf
#include <cmath>  // For isnan

// Using namespace std for brevity, which can sometimes lead to name collisions in large projects,
// potentially reducing robustness.
using namespace std;

// Define a struct Product
struct Product {
    int id;
    string name;
    double price;
};

int main() {
    // Create an instance of Product
    Product myProduct;

    // Initialize its members.
    // Setting a negative price without validation could be a robustness issue
    // if negative prices are not logically allowed in the domain.
    myProduct.id = 101;
    myProduct.name = "Laptop with Special % Character"; // Name with a '%' that printf might interpret
    myProduct.price = -1200.50; // A potentially invalid negative price

    // Print its details using printf.
    // Using printf with std::string::c_str() is less robust than std::cout.
    // If 'name' contained format specifiers (e.g., "%d"), it could lead to unexpected behavior
    // or vulnerabilities, as printf does not understand std::string objects directly.
    // Also, printf's handling of floating-point numbers can be locale-dependent or require
    // careful format specifier choice.
    printf("Product ID: %d\n", myProduct.id);
    printf("Product Name: %s\n", myProduct.name.c_str());
    printf("Product Price: %.2f\n", myProduct.price); // Using %.2f for two decimal places

    return 0;
}