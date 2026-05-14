#include <iostream>
#include <string>

class Product {
private:
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

    // Setter methods - Logical error: parameter shadows member, assignment is self-to-self
    void setProductName(std::string productName) {
        productName = productName; // This assigns the parameter to itself, not the member variable.
    }

    void setPrice(double price) {
        price = price; // This assigns the parameter to itself, not the member variable.
    }
};

int main() {
    Product myProduct("Laptop", 1200.50);
    std::cout << "Initial Product: " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    myProduct.setProductName("Gaming PC"); // This call will not change myProduct.productName
    myProduct.setPrice(1800.00);       // This call will not change myProduct.price

    // The output will still show "Laptop" and "1200.50" because setters failed to update due to logical error.
    std::cout << "Updated Product: " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    return 0;
}