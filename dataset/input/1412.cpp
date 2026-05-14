#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
private:
    std::string productName;
    double price;

public:
    // Default constructor
    Product() : productName(""), price(0.0) {}

    // Parameterized constructor
    Product(std::string name, double p) : productName(name), price(p) {} // Passing name by value here too

    // Getter methods - Readability/Efficiency issue: Missing 'const' qualifier
    std::string getProductName() { // Should be const
        return productName;
    }

    double getPrice() { // Should be const
        return price;
    }

    // Setter methods - Readability/Efficiency issue: Passing string by value
    void setProductName(std::string name) { // Should be const std::string&
        productName = name;
    }

    void setPrice(double p) {
        // No validation, but the primary issue here is readability/efficiency, not robustness.
        price = p;
    }
};

int main() {
    Product p1;
    p1.setProductName("Monitor");
    p1.setPrice(350.75);

    std::cout << "Product: " << p1.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    p1.setProductName("Gaming Monitor");
    p1.setPrice(499.99);
    std::cout << "Product: " << p1.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    Product p2("Mouse", 25.00);
    std::cout << "Product: " << p2.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p2.getPrice() << std::endl;

    return 0;
}