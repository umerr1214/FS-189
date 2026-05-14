#include <string>
#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

class Product {
private:
    int id;
    std::string name;
    double price;
public:
    // LOGICAL ERROR: Default ID for no-argument case should be 0, but is 1 here.
    Product(int id = 1, std::string name = "Unnamed", double price = 0.0) :
        id(id), name(name), price(price) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
};

int main() {
    std::cout << std::fixed << std::setprecision(1);

    Product p1; // No arguments - Expect id=0, but will get id=1 due to error
    std::cout << "P1: " << p1.getId() << ", " << p1.getName() << ", " << p1.getPrice() << std::endl;

    Product p2(101, "Laptop"); // id, name (price defaults to 0.0) - Correct
    std::cout << "P2: " << p2.getId() << ", " << p2.getName() << ", " << p2.getPrice() << std::endl;

    Product p3(102, "Mouse", 25.50); // all arguments - Correct
    std::cout << "P3: " << p3.getId() << ", " << p3.getName() << ", " << p3.getPrice() << std::endl;

    return 0;
}