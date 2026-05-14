#include <iostream>
#include <string> // Using std::string for name
#include <utility> // For std::move in constructor, though not strictly required for this issue

class Product {
private:
    int productID;
    std::string name;
    double price;

public:
    // Constructor
    Product(int id, std::string n, double p) : productID(id), name(std::move(n)), price(p) {}

    // Overload == operator - EFFICIENCY ISSUE: passing by value
    // 'other' is passed by value, incurring an unnecessary copy of the Product object.
    bool operator==(Product other) const {
        // READABILITY ISSUE: 'this->' is redundant here and adds clutter.
        return this->productID == other.productID;
    }

    // READABILITY ISSUE: Verbose method name for displaying details.
    void displayProductDetails() const {
        std::cout << "Product ID: " << this->productID << std::endl;
        std::cout << "Product Name: " << this->name << std::endl;
        std::cout << "Product Price: $" << this->price << std::endl;
        std::cout << "--------------------" << std::endl;
    }
};

int main() {
    Product p1(101, "Laptop Pro", 1200.50);
    Product p2(102, "Wireless Mouse", 25.00);
    Product p3(101, "Mechanical Keyboard", 75.00); // Same ID as p1

    p1.displayProductDetails();
    p2.displayProductDetails();
    p3.displayProductDetails();

    std::cout << "Comparing p1 and p2 (ID 101 vs 102): " << (p1 == p2 ? "Match" : "No Match") << std::endl;
    std::cout << "Comparing p1 and p3 (ID 101 vs 101): " << (p1 == p3 ? "Match" : "No Match") << std::endl;

    Product p4(103, "Monitor", 300.00);
    Product p5(103, "Webcam", 50.00); // Same ID as p4
    std::cout << "Comparing p4 and p5 (ID 103 vs 103): " << (p4 == p5 ? "Match" : "No Match") << std::endl;

    return 0;
}