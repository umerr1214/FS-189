#include <iostream>
#include <string>
#include <iomanip> // For setprecision

class Product {
public:
    int id;
    std::string name;
    double price;

    // Constructor 3 (Primary/Full): Takes id, name, and price
    // Initializes all members directly using member initializer list.
    Product(int id_val, std::string name_val, double price_val)
        : id(id_val), name(name_val), price(price_val) {
        // Body can be empty or contain additional logic/validation if needed.
    }

    // Constructor 2: Takes id and name
    // Chains to the 3-argument constructor, providing a default price.
    Product(int id_val, std::string name_val)
        : Product(id_val, name_val, 0.0) {
    }

    // Constructor 1: Takes only id
    // Chains to the 2-argument constructor, providing default name and price.
    Product(int id_val)
        : Product(id_val, "") { // Chains to the 2-argument constructor, which then chains to the 3-arg.
    }

    void display() const {
        std::cout << "ID: " << id
                  << ", Name: " << (name.empty() ? "[N/A]" : name)
                  << ", Price: " << std::fixed << std::setprecision(2) << price
                  << std::endl;
    }
};

int main() {
    std::cout << "Testing Product constructors (Correct Version with Chaining):\n";

    Product p1(101); // Only ID
    std::cout << "Product 1: ";
    p1.display();

    Product p2(102, "Laptop"); // ID and Name
    std::cout << "Product 2: ";
    p2.display();

    Product p3(103, "Mouse", 25.50); // ID, Name, and Price
    std::cout << "Product 3: ";
    p3.display();

    // Test with modified object
    Product p4_mod(200); // Only ID, then modify
    p4_mod.name = "Custom Product";
    p4_mod.price = 99.99;
    std::cout << "Product 4 (Modified): ";
    p4_mod.display();

    // Another test for chaining
    Product p5_chain(300, "Keyboard");
    std::cout << "Product 5: ";
    p5_chain.display();

    return 0;
}