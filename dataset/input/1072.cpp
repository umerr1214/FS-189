#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Product {
private:
    std::string name;
    double price;
protected:
    double discountRate;

public:
    Product(std::string n, double p, double dr) : name(n), price(p), discountRate(dr) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void displayProduct() const {
        std::cout << "Product: " << name << ", Price: $" << std::fixed << std::setprecision(2) << price << ", Discount Rate: " << discountRate * 100 << "%" << std::endl;
    }
} // Missing semicolon here, causing a syntax error

class SpecialProduct : public Product {
public:
    SpecialProduct(std::string n, double p, double dr) : Product(n, p, dr) {}

    double getFinalPrice() const {
        return getPrice() * (1.0 - discountRate);
    }

    void displaySpecialProduct() const {
        std::cout << "Special Product: " << getName() << ", Original Price: $" << std::fixed << std::setprecision(2) << getPrice()
                  << ", Discount Rate: " << discountRate * 100 << "%"
                  << ", Final Price: $" << getFinalPrice() << std::endl;
    }
};

int main() {
    // This code will not compile due to the syntax error
    // The test cases are illustrative as execution will not proceed
    Product p1("Book", 25.0, 0.0);
    p1.displayProduct();

    SpecialProduct sp1("Laptop", 1200.0, 0.10);
    sp1.displaySpecialProduct();

    SpecialProduct sp2("Mouse", 50.0, 0.05);
    sp2.displaySpecialProduct();

    return 0;
}