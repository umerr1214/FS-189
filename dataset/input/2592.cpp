#include <string>
#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

class Product {
private:
    int id;
    std::string name;
    double price;
    // SEMANTIC ERROR: Constructor is private, making it inaccessible from main
    Product(int id = 0, std::string name = "Unnamed", double price = 0.0) :
        id(id), name(name), price(price) {}
public:
    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

int main() {
    // This will cause a semantic error (compiler error: 'Product::Product(int, std::string, double)' is private)
    // The program is syntactically correct, but violates C++ access rules, preventing object creation.
    Product p1;
    std::cout << "P1: " << p1.getId() << ", " << p1.getName() << ", " << p1.getPrice() << std::endl;

    Product p2(101, "Laptop");
    std::cout << "P2: " << p2.getId() << ", " << p2.getName() << ", " << p2.getPrice() << std::endl;

    Product p3(102, "Mouse", 25.50);
    std::cout << "P3: " << p3.getId() << ", " << p3.getName() << ", " << p3.getPrice() << std::endl;

    return 0;
}