#include <iostream>
#include <string>
#include <limits> // For numeric_limits to clear cin buffer

struct Product {
    int id;
    std::string name;
    double price;
};

int main() {
    Product products[2];

    for (int i = 0; i < 2; ++i) {
        std::cout << "Enter details for Product " << i + 1 << ":" << std::endl;
        std::cout << "ID: ";
        std::cin >> products[i].id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
        std::cout << "Name: ";
        std::getline(std::cin, products[i].name);
        std::cout << "Price: ";
        std::cin >> products[i].price;
    }

    // LOGICAL ERROR: The comparison operator is inverted, causing the program
    // to find the product with the lowest price instead of the highest.
    Product highestPriceProduct = products[0];
    for (int i = 1; i < 2; ++i) {
        if (products[i].price < highestPriceProduct.price) { // Should be '>' for highest price
            highestPriceProduct = products[i];
        }
    }

    std::cout << "\nProduct with the highest price:" << std::endl;
    std::cout << "ID: " << highestPriceProduct.id << std::endl;
    std::cout << "Name: " << highestPriceProduct.name << std::endl;
    std::cout << "Price: " << highestPriceProduct.price << std::endl;

    return 0;
}