#include <iostream>
#include <string>

class Product {
public: // Semantic error: `productName` and `price` should be private as per the question
    std::string productName;
    double price;

public:
    // Constructor
    Product(std::string name, double p) : productName(name), price(p) {}

    // Getter methods
    std::string getProductName() const {
        return productName;
    }

    double getPrice() const {
        return price;
    }

    // Setter methods
    void setProductName(std::string name) {
        productName = name;
    }

    void setPrice(double p) {
        price = p;
    }
};

int main() {
    Product myProduct("Laptop", 1200.50);
    std::cout << "Initial Product: " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    myProduct.setProductName("Gaming PC");
    myProduct.setPrice(1800.00);

    // This code compiles and functions, but the design requirement (private members) is violated.
    std::cout << "Updated Product (via setters): " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    // The semantic error allows direct access, which should not be possible if members were private.
    myProduct.productName = "Workstation";
    myProduct.price = 2500.00;
    std::cout << "Directly modified Product: " << myProduct.productName << ", " << myProduct.price << std::endl;

    return 0;
}