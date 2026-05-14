#include <iostream>
#include <string>
#include <iomanip>

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    Product(std::string n, double p, int q) : name(n), price(p), quantity(q) {}

    double getTotalValue() {
        // Semantic Error: Explicitly casts 'price' to an int before multiplication,
        // losing its fractional part. While syntactically valid and compiles,
        // it violates the semantic intent of using a double for price in a
        // calculation that should preserve precision.
        return (double)((int)price * quantity);
    }
};

int main() {
    Product p1("Laptop", 1200.50, 2);
    Product p2("Book", 25.99, 5);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << p1.getTotalValue() << std::endl;
    std::cout << p2.getTotalValue() << std::endl;

    return 0;
}