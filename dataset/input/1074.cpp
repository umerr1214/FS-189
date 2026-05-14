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

    // This method is added to verify the base class's discount rate
    double getBaseDiscountRate() const {
        return discountRate;
    }

    void displayProduct() const {
        std::cout << "Product: " << name << ", Price: $" << std::fixed << std::setprecision(2) << price << ", Discount Rate: " << discountRate * 100 << "%" << std::endl;
    }
};

class SpecialProduct : public Product {
public:
    // Semantic Error: The constructor for SpecialProduct ignores its own 'dr' parameter
    // and always passes 0.0 as the discount rate to the base Product constructor.
    // This means the inherited 'discountRate' will always be 0.0, regardless of the intended discount.
    SpecialProduct(std::string n, double p, double dr) : Product(n, p, 0.0) {
        // The 'dr' passed to SpecialProduct constructor is effectively ignored for the base class's discountRate.
        // If we wanted to use 'dr' for SpecialProduct, we should have passed 'dr' to Product(n, p, dr).
    }

    double getFinalPrice() const {
        // This correctly accesses the protected discountRate from the base class,
        // but its value is always 0.0 due to the constructor's semantic error.
        return getPrice() * (1.0 - discountRate);
    }

    void displaySpecialProduct() const {
        std::cout << "Special Product: " << getName() << ", Original Price: $" << std::fixed << std::setprecision(2) << getPrice()
                  << ", Discount Rate (as seen by base): " << getBaseDiscountRate() * 100 << "%" // Verify base rate
                  << ", Intended Discount Rate (ignored by constructor): " << "N/A" // Cannot access original 'dr'
                  << ", Final Price: $" << getFinalPrice() << std::endl;
    }
};

int main() {
    Product p1("Book", 25.0, 0.0);
    p1.displayProduct();

    SpecialProduct sp1("Laptop", 1200.0, 0.10); // Intends 10% discount, but base gets 0%
    // Expected final price: $1080.00, but will output $1200.00 because base discountRate is 0.0
    sp1.displaySpecialProduct();

    SpecialProduct sp2("Mouse", 50.0, 0.05); // Intends 5% discount, but base gets 0%
    // Expected final price: $47.50, but will output $50.00 because base discountRate is 0.0
    sp2.displaySpecialProduct();

    return 0;
}