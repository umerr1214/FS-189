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
};

class SpecialProduct : public Product {
public:
    SpecialProduct(std::string n, double p, double dr) : Product(n, p, dr) {}

    // Logical Error: This method calculates the discount amount, not the final price.
    // It should be getPrice() * (1.0 - discountRate).
    double getFinalPrice() const {
        return getPrice() * discountRate;
    }

    void displaySpecialProduct() const {
        std::cout << "Special Product: " << getName() << ", Original Price: $" << std::fixed << std::setprecision(2) << getPrice()
                  << ", Discount Rate: " << discountRate * 100 << "%"
                  << ", Calculated Value (Incorrect Final Price): $" << getFinalPrice() << std::endl;
    }
};

int main() {
    Product p1("Book", 25.0, 0.0);
    p1.displayProduct();

    SpecialProduct sp1("Laptop", 1200.0, 0.10); // 10% discount
    // Expected final price: $1080.00, but will output $120.00 (the discount amount)
    sp1.displaySpecialProduct();

    SpecialProduct sp2("Mouse", 50.0, 0.05); // 5% discount
    // Expected final price: $47.50, but will output $2.50 (the discount amount)
    sp2.displaySpecialProduct();

    return 0;
}