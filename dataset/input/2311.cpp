#include <iostream>
#include <string>
#include <iomanip> // For setprecision

class Product {
public:
    int id;
    std::string name;
    double price;

    // Constructor 1: Takes only id
    // Does not chain, explicitly initializes name and price.
    // Lacks validation for id (e.g., negative id is allowed).
    Product(int id_val) : id(id_val) {
        this->name = "";
        this->price = 0.0;
    }

    // Constructor 2: Takes id and name
    // Does not chain, explicitly initializes price.
    // Lacks validation for id.
    Product(int id_val, std::string name_val) : id(id_val), name(name_val) {
        this->price = 0.0;
    }

    // Constructor 3: Takes id, name, and price
    // Lacks validation for id_val or price_val (e.g., negative price is allowed).
    Product(int id_val, std::string name_val, double price_val)
        : id(id_val), name(name_val), price(price_val) {
        // No input validation for price or id, which can lead to illogical product data
    }

    void display() const {
        std::cout << "ID: " << id
                  << ", Name: " << (name.empty() ? "[N/A]" : name)
                  << ", Price: " << std::fixed << std::setprecision(2) << price
                  << std::endl;
    }
};

int main() {
    std::cout << "Testing Product constructors and potential robustness issues:\n";

    Product p1(101); // Only ID
    std::cout << "Product 1: ";
    p1.display();

    Product p2(102, "Laptop"); // ID and Name
    std::cout << "Product 2: ";
    p2.display();

    Product p3(103, "Mouse", 25.50); // ID, Name, and Price
    std::cout << "Product 3: ";
    p3.display();

    // Demonstrate robustness issue: Negative ID and Price are accepted without validation
    Product p4_robust(-50, "Invalid Item", -10.00);
    std::cout << "Product 4 (Robustness Test - Negative Values): ";
    p4_robust.display(); // Output shows negative ID and price, which might be an unintended state

    Product p5_mod(200); // Only ID, then modify
    p5_mod.name = "Custom Product";
    p5_mod.price = 99.99;
    std::cout << "Product 5 (Modified): ";
    p5_mod.display();

    return 0;
}