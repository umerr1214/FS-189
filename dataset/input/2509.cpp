#include <iostream>
#include <cstring> // For strcpy, strlen

class Product {
public:
    int productID;
    char* name; // Using char* for name to introduce memory management issues
    double price;

    // Constructor
    Product(int id, const char* n, double p) : productID(id), price(p) {
        if (n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        } else {
            name = nullptr;
        }
    }

    // Destructor - responsible for freeing name
    ~Product() {
        delete[] name;
    }

    // IMPORTANT ROBUSTNESS ISSUE:
    // The class uses a raw pointer (char* name) but does NOT implement a
    // custom copy constructor or copy assignment operator (Rule of Three).
    // The compiler-generated default versions will perform shallow copies.
    // This means if one Product object is copied from another (e.g., Product p2 = p1;),
    // both objects' 'name' pointers will point to the same memory.
    // When both objects are destructed, their destructors will attempt to
    // delete[] the same memory twice, leading to a double-free error and a crash.

    // Overload == operator
    bool operator==(const Product& other) const {
        return productID == other.productID;
    }

    void display() const {
        std::cout << "ID: " << productID << ", Name: " << (name ? name : "N/A") << ", Price: " << price << std::endl;
    }
};

int main() {
    Product p1(101, "Laptop", 1200.50);
    Product p2(102, "Mouse", 25.00);
    Product p3(101, "Keyboard", 75.00); // Same ID as p1, different name/price

    p1.display();
    p2.display();
    p3.display();

    std::cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << std::endl;
    std::cout << "p1 == p3: " << (p1 == p3 ? "true" : "false") << std::endl;

    // To demonstrate the robustness issue (shallow copy and double-free potential):
    // If you uncomment the following lines, the program will likely crash
    // when p_copy_test and p_shallow_copy go out of scope, due to double-free.
    // {
    //     Product p_copy_test(105, "Test Product", 99.99);
    //     Product p_shallow_copy = p_copy_test; // This performs a shallow copy
    //     std::cout << "p_copy_test display: "; p_copy_test.display();
    //     std::cout << "p_shallow_copy display: "; p_shallow_copy.display();
    // } // CRASH LIKELY HERE due to double-free

    return 0;
}