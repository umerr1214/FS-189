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
    p.name = "Laptop";
    p.price = 1200.50;

    std::cout << "Product ID: " << p.id << std::endl;
    std::cout << "Product Name: " << p.id << std::endl; // Logical Error: Printing 'id' instead of 'name'
    std::cout << "Product Price: " << p.price << std::endl;

    return 0;
}