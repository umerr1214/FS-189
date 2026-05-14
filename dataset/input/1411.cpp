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
    Product(const std::string& name, double p) : productName(name), price(p) {}

    // Getter methods
    std::string getProductName() const {
        return productName;
    }

    double getPrice() const {
        return price;
    }

    // Setter methods - Robustness issue: No validation for price
    void setProductName(const std::string& name) {
        productName = name;
    }

    void setPrice(double p) {
        // Robustness issue: Allows negative prices without validation
        price = p;
    }
};

int main() {
    Product p1;
    p1.setProductName("Laptop");
    p1.setPrice(1200.50);

    std::cout << "Product: " << p1.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    // Demonstrate the robustness issue: setting a negative price
    p1.setPrice(-150.00);
    std::cout << "Product: " << p1.getProductName() << ", Price after invalid set: $" << std::fixed << std::setprecision(2) << p1.getPrice() << std::endl;

    Product p2("Keyboard", 75.99);
    std::cout << "Product: " << p2.getProductName() << ", Price: $" << std::fixed << std::setprecision(2) << p2.getPrice() << std::endl;

    return 0;
}