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
    Product(const std::string& name, double p) : productName(name), price(0.0) { // Initialize price to 0.0 first
        setPrice(p); // Then use setter for validation
    }

    // Getter methods - Correct: Marked as const
    std::string getProductName() const {
        return productName;
    }

    double getPrice() const {
        return price;
    }

    // Setter methods - Correct: Pass string by const reference, validate price
    void setProductName(const std::string& name) {
        productName = name;
    }

    void setPrice(double p) {
        if (p >= 0) { // Robustness: Validate price
            price = p;
        } else {
            std::cerr << "Warning: Price cannot be negative. Price for '" << productName << "' remains $" << std::fixed << std::setprecision(2) << price << "." << std::endl;
        }
    }
};

int main() {
    Product p1;
    p1.setProductName("Smartphone");
    p1.setPrice(799.99);

    std::cout << "Product: " << p1.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    // Test with a negative price (should be rejected)
    p1.setPrice(-50.00);
    std::cout << "Product: " << p1.getProductName() << ", Price after invalid set attempt: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    Product p2("Smartwatch", 249.00);
    std::cout << "Product: " << p2.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p2.getPrice() << std::endl;

    // Test parameterized constructor with negative price
    Product p3("Broken Item", -10.00); // Should set price to 0.0 due to validation in constructor
    std::cout << "Product: " << p3.getProductName() << ", Price from constructor: $" << std::fixed << std::setprecision(2) << p3.getPrice() << std::endl;

    return 0;
}