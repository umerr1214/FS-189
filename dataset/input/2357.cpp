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

    double calculateTotal() {
        double total = 0.0;
        for (const auto& item : items) {
            // Logical error: Adding price and quantity instead of multiplying
            total += item.price + item.quantity; // Should be item.price * item.quantity
        }
        return total;
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem(Item("Laptop", 1200.0, 1));
    cart.addItem(Item("Mouse", 25.0, 2));
    cart.addItem(Item("Keyboard", 75.0, 1));

    double total = cart.calculateTotal();
    std::cout << "Total: " << std::fixed << std::setprecision(2) << total << std::endl;

    ShoppingCart cart2;
    cart2.addItem(Item("Book", 15.50, 3));
    cart2.addItem(Item("Pen", 2.0, 10));
    double total2 = cart2.calculateTotal();
    std::cout << "Total2: " << std::fixed << std::setprecision(2) << total2 << std::endl;

    return 0;
}