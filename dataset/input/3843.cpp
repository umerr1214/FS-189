#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

struct Product {
    int id;
    std::string name;
    double price;
};

int main() {
    // Create an array of 2 Product structs
    const int NUM_PRODUCTS = 2;
    Product products[NUM_PRODUCTS];

    std::cout << "Enter data for " << NUM_PRODUCTS << " products:\n";

    // Loop to prompt user for data for each product
    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        std::cout << "\nProduct " << i + 1 << ":\n";
        std::cout << "Enter ID: ";
        std::cin >> products[i].id;

        // Clear the input buffer after reading an integer to prepare for std::getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter Name: ";
        std::getline(std::cin, products[i].name);

        std::cout << "Enter Price: ";
        std::cin >> products[i].price;
    }

    // Find the product with the highest price
    int highestPriceIndex = 0; // Assume the first product has the highest price initially

    for (int i = 1; i < NUM_PRODUCTS; ++i) {
        if (products[i].price > products[highestPriceIndex].price) {
            highestPriceIndex = i;
        }
    }

    // Print details for the product with the highest price
    std::cout << "\nProduct with highest price:\n";
    std::cout << "ID: " << products[highestPriceIndex].id << "\n";
    std::cout << "Name: " << products[highestPriceIndex].name << "\n";
    std::cout.precision(2); // Set precision for price output
    std::cout << std::fixed << "Price: " << products[highestPriceIndex].price << "\n";

    return 0;
}