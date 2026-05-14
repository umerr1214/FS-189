#include <iostream>
#include <string>
#include <cstdio> // For printf
#include <iomanip> // Not strictly needed for printf, but included for consistency if std::cout were used

// Define a Product class
class Product {
public:
    int id;
    std::string name;
    double price;

    // Default constructor needed for `new Product[N]`
    Product() : id(0), name(""), price(0.0) {}
    Product(int i, const std::string& n, double p) : id(i), name(n), price(p) {}
};

int main() {
    const int PROD_COUNT = 3;
    // Create an array of Product objects using manual memory management
    Product* prod_arr = new Product[PROD_COUNT];

    // Populate it with data
    prod_arr[0] = Product(101, "Laptop", 1200.50);
    prod_arr[1] = Product(102, "Mouse", 25.00);
    prod_arr[2] = Product(103, "Keyboard", 75.99);

    printf("--- Product Details (Readability/Efficiency Issue) ---\n");

    int idx = 0;
PRODUCT_DISPLAY_LOOP: // Using goto for iteration, which is generally discouraged
    if (idx < PROD_COUNT) {
        // Display details using printf (less C++ idiomatic and type-safe than std::cout)
        printf("Product %d: ID: %d, Name: %s, Price: $%.2f\n",
               idx + 1, prod_arr[idx].id, prod_arr[idx].name.c_str(), prod_arr[idx].price);
        idx++;
        goto PRODUCT_DISPLAY_LOOP;
    }

    // Clean up allocated memory
    delete[] prod_arr; // Manual memory deallocation

    return 0;
}