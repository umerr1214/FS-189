#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Item {
public:
    std::string name;
    double price;
    int quantity;

    Item(std::string n, double p, int q) : name(n), price(p), quantity(q) {}
};

class ShoppingCart {
private:
    std::vector<Item> items;
public:
    void addItem(Item item) {
        items.push_back(item);
    }

    // Semantic error: calculateTotal() returns an int, causing truncation of the total.
    int calculateTotal() { // Should be 'double calculateTotal()'
        double total = 0.0;
        for (const auto& item : items) {
            total += item.price * item.quantity;
        }
        return static_cast<int>(total); // Explicit cast to int, truncating decimal part
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem(Item("Laptop", 1200.0, 1));
    cart.addItem(Item("Mouse", 25.50, 2)); // 51.00
    cart.addItem(Item("Keyboard", 75.25, 1)); // 75.25

    double total = cart.calculateTotal(); // total will receive the truncated int value (e.g., 1326.00 instead of 1326.25)
    std::cout << "Total: " << std::fixed << std::setprecision(2) << total << std::endl;

    ShoppingCart cart2;
    cart2.addItem(Item("Book", 15.50, 3)); // 46.50
    cart2.addItem(Item("Pen", 2.0, 10)); // 20.00

    double total2 = cart2.calculateTotal(); // total2 will receive the truncated int value (e.g., 66.00 instead of 66.50)
    std::cout << "Total2: " << std::fixed << std::setprecision(2) << total2 << std::endl;

    return 0;
}