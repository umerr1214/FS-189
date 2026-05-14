#include <iostream>
#include <string>

struct Product {
    int id;
    std::string name;
    double price;
};

int main() {
    Product p;
    p.id = 101;
    p.name = 123; // Semantic Error: Attempting to assign an integer literal to a std::string
    p.price = 1200.50;

    std::cout << "Product ID: " << p.id << std::endl;
    std::cout << "Product Name: " << p.name << std::endl;
    std::cout << "Product Price: " << p.price << std::endl;

    return 0;
}