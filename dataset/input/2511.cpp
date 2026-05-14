#include <iostream>
#include <string>
#include <utility> // For std::move

class Product {
private:
    int productID;
    std::string name;
    double price;

public:
    // Constructor
    Product(int id, std::string n, double p)
        : productID(id), name(std::move(n)), price(p) {}

    // Getter for productID (if external access is needed, though not strictly required for ==)
    int getProductID() const {
        return productID;
    }

    // Friend declaration for the overloaded == operator
    // This allows the non-member operator to access private members.
    friend bool operator==(const Product& lhs, const Product& rhs);

    // Display method
    void display() const {
        std::cout << "ID: " << productID << ", Name: " << name << ", Price: " << price << std::endl;
    }
};

// Overload == operator as a non-member friend function
// Takes arguments by const reference for efficiency and correctness.
// Compares two Product objects based solely on their productID as per the question.
bool operator==(const Product& lhs, const Product& rhs) {
    return lhs.productID == rhs.productID;
}

int main() {
    Product p1(101, "Gaming Laptop", 1500.00);
    Product p2(102, "Ergonomic Mouse", 50.00);
    Product p3(101, "Mechanical Keyboard", 120.00); // Same ID as p1, different name/price
    Product p4(103, "4K Monitor", 450.00);

    p1.display();
    p2.display();
    p3.display();
    p4.display();

    std::cout << "\n--- Comparisons ---" << std::endl;
    std::cout << "p1 (ID 101) == p2 (ID 102): " << (p1 == p2 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "p1 (ID 101) == p3 (ID 101): " << (p1 == p3 ? "true" : "false") << std::endl; // Expected: true
    std::cout << "p2 (ID 102) == p4 (ID 103): " << (p2 == p4 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "p3 (ID 101) == p1 (ID 101): " << (p3 == p1 ? "true" : "false") << std::endl; // Expected: true

    // Test with a temporary object to ensure operator works with rvalues
    std::cout << "p1 (ID 101) == Product(101, \"Temporary Item\", 10.0): " << (p1 == Product(101, "Temporary Item", 10.0) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "p1 (ID 101) == Product(999, \"Another Temp\", 10.0): " << (p1 == Product(999, "Another Temp", 10.0) ? "true" : "false") << std::endl; // Expected: false

    return 0;
}