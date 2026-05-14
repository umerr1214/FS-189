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

    // Setter methods
    void setProductName(std::string name) {
        productName = name;
    }

    void setPrice(double p) {
        price = p;
    }
}; // ERROR: Missing semicolon after class definition

int main() {
    Product myProduct("Laptop", 1200.50);
    std::cout << "Initial Product: " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    myProduct.setProductName("Gaming PC");
    myProduct.setPrice(1800.00);

    std::cout << "Updated Product: " << myProduct.getProductName() << ", " << myProduct.getPrice() << std::endl;

    return 0;
}