#include <iostream>
#include <string>
#include <iomanip> // For setprecision

class Product {
public:
    int id;
    std::string name;
    double price;

    // Constructor 1: Takes only id
    Product(int id_val) {
        this->id = id_val;          // Explicitly initialize id
        this->name = "";             // Explicitly initialize name (redundant if chained)
        this->price = 0.0;           // Explicitly initialize price (redundant if chained)
    }

    // Constructor 2: Takes id and name
    Product(int id_val, std::string name_val) {
        this->id = id_val;          // Redundant initialization
        this->name = name_val;
        this->price = 0.0;           // Explicitly initialize price (redundant if chained)
    }

    // Constructor 3: Takes id, name, and price
    Product(int id_val, std::string name_val, double price_val) {
        this->id = id_val;          // Redundant initialization
        this->name = name_val;      // Redundant initialization
        this->price = price_val;
    }

    void display() const {
        std::cout << "ID: " << this->id
                  << ", Name: " << (this->name.empty() ? "[N/A]" : this->name)
                  << ", Price: " << std::fixed << std::setprecision(2) << this->price
                  << std::endl;
    }
};

int main() {
    std::cout << "Testing Product constructors (Readability/Efficiency Issue):\n";

    Product p1(101); // Only ID
    std::cout << "Product 1: ";
    p1.display();

    Product p2(102, "Laptop"); // ID and Name
    std::cout << "Product 2: ";
    p2.display();

    Product p3(103, "Mouse", 25.50); // ID, Name, and Price
    std::cout << "Product 3: ";
    p3.display();

    Product p4_mod(200); // Only ID, then modify
    p4_mod.name = "Custom Product";
    p4_mod.price = 99.99;
    std::cout << "Product 4 (Modified): ";
    p4_mod.display();

    return 0;
}