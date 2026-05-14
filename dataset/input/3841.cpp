#include <iostream>
#include <string>
#include <vector>
#include <limits> // Required for numeric_limits

struct Product {
    int id;
    std::string name;
    double price;
};

int main() {
    Product products[2]; // Array of 2 Product structs
    int numProducts = 2;

    std::cout << "Enter data for " << numProducts << " products:\n";

    for (int i = 0; i < numProducts; ++i) {
        std::cout << "Product " << i + 1 << ":\n";
        std::cout << "Enter ID: ";
        std::cin >> products[i].id; // Leaves newline in buffer

        std::cout << "Enter Name: ";
        // This getline will read the leftover newline from std::cin >> id,
        // causing products[i].name to be empty. This is the robustness issue.
        std::getline(std::cin, products[i].name); 

        std::cout << "Enter Price: ";
        std::cin >> products[i].price;
    }

    // Find the product with the highest price
    int highestPriceIndex = -1;
    double maxPrice = -1.0; // Initialize with a value lower than any possible price

    for (int i = 0; i < numProducts; ++i) {
        if (products[i].price > maxPrice) {
            maxPrice = products[i].price;
            highestPriceIndex = i;
        }
    }

    // Print details for the product with the highest price
    if (highestPriceIndex != -1) {
        std::cout << "\nProduct with highest price:\n";
        std::cout << "ID: " << products[highestPriceIndex].id << "\n";
        std::cout << "Name: " << products[highestPriceIndex].name << "\n";
        std::cout.precision(2);
        std::cout << std::fixed << "Price: " << products[highestPriceIndex].price << "\n";
    } else {
        std::cout << "\nNo products entered or an error occurred.\n";
    }

    return 0;
}