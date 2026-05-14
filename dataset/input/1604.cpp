#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision
#include <cmath>   // For std::abs, used in a common pattern for loops with negative values

class Product {
private:
    std::string name;
    double price;
    int quantity;

public:
    // Constructor to initialize private members
    Product(std::string n, double p, int q) : name(n), price(p), quantity(q) {}

    // Public method to calculate and return the total value
    double getTotalValue() {
        // Readability/Efficiency Issue:
        // Instead of a direct and efficient multiplication (price * quantity),
        // this method uses an iterative loop. This approach is significantly
        // less efficient for larger quantities and harder to read due to the
        // conditional logic for handling positive and negative quantities separately.
        double total = 0.0;
        if (quantity >= 0) {
            for (int i = 0; i < quantity; ++i) {
                total += price;
            }
        } else {
            // For negative quantity, subtract price 'abs(quantity)' times
            for (int i = 0; i > quantity; --i) {
                total -= price;
            }
        }
        return total;
    }

    // Getters for accessing private members (useful for testing/display)
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

int main() {
    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places

    std::vector<Product> products;
    products.emplace_back("Laptop", 1200.50, 2);
    products.emplace_back("Mouse", 25.00, 0);
    products.emplace_back("Keyboard", 75.99, 1);
    products.emplace_back("Monitor", 300.00, 3);
    products.emplace_back("Freebie", 0.00, 5);
    products.emplace_back("Returned Item", 50.00, -3); // This will result in -150.00

    for (const auto& p : products) {
        std::cout << "Product: " << p.getName()
                  << ", Price: " << p.getPrice()
                  << ", Quantity: " << p.getQuantity()
                  << ", Total Value: " << p.getTotalValue() << std::endl;
    }

    return 0;
}