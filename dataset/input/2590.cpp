#include <string>
#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

class Product {
private:
    int id;
    std::string name;
    double price // ERROR: Missing semicolon here
public:
    Product(int id = 0, std::string name = "Unnamed", double price = 0.0) :
        id(id), name(name), price(price) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

int main() {
    // This code won't compile due to the syntax error in the Product class definition.
    // It's included to make it a complete C++ program, but it's expected to fail compilation.
    // The compiler will report an error near the 'public:' keyword or the line above it.
    Product p1;
    std::cout << "P1: " << p1.getId() << ", " << p1.getName() << ", " << p1.getPrice() << std::endl;

    Product p2(101, "Laptop");
    std::cout << "P2: " << p2.getId() << ", " << p2.getName() << ", " << p2.getPrice() << std::endl;

    Product p3(102, "Mouse", 25.50);
    std::cout << "P3: " << p3.getId() << ", " << p3.getName() << ", " << p3.getPrice() << std::endl;

    return 0;
}