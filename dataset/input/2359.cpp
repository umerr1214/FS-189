#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate (though not used in robust version to keep it simple)

class Item {
public:
    std::string name;
    double price;
    int quantity;

    Item(std::string name, double price, int quantity)
        : name(std::move(name)), price(price), quantity(quantity) {}

    // No validation for price or quantity here, allowing negative values
};

class ShoppingCart {
private:
    std::vector<Item> items;

public:
    void addItem(Item item) {
        // No validation for item's price or quantity when adding
        items.push_back(item);
    }

    double calculateTotal() {
        double total = 0.0;
        for (const auto& item : items) {
            // Directly sums up price * quantity, even if price or quantity are negative
            total += item.price * item.quantity;
        }
        return total;
    }

    // A helper for demonstration, not part of the core requirements
    void displayCart() const {
        if (items.empty()) {
            std::cout << "Cart is empty.\n";
            return;
        }
        std::cout << "--- Shopping Cart Items ---\n";
        for (const auto& item : items) {
            std::cout << item.name << " | Price: $" << item.price << " | Qty: " << item.quantity << std::endl;
        }
        std::cout << "---------------------------\n";
    }
};

int main() {
    ShoppingCart cart;

    // Test Case 1: Standard items
    cart.addItem(Item("Laptop", 1200.0, 1));
    cart.addItem(Item("Mouse", 25.0, 2));
    std::cout << "After adding Laptop and Mouse:\n";
    cart.displayCart();
    std::cout << "Total: $" << cart.calculateTotal() << std::endl; // Expected: 1250.0

    std::cout << "\n---------------------------\n\n";

    // Test Case 2: Item with negative quantity - leads to incorrect total
    cart.addItem(Item("Discount Voucher", -10.0, 1)); // This item has a negative price
    std::cout << "After adding Discount Voucher (price -10.0):\n";
    cart.displayCart();
    std::cout << "Total: $" << cart.calculateTotal() << std::endl; // Expected: 1250.0 - 10.0 = 1240.0 (mathematically, but conceptually wrong for a cart total)

    std::cout << "\n---------------------------\n\n";

    // Test Case 3: Item with negative price - leads to incorrect total
    cart.addItem(Item("Damaged Item", 50.0, -1)); // This item has a negative quantity
    std::cout << "After adding Damaged Item (qty -1):\n";
    cart.displayCart();
    std::cout << "Total: $" << cart.calculateTotal() << std::endl; // Expected: 1240.0 - 50.0 = 1190.0 (mathematically, but conceptually wrong)

    std::cout << "\n---------------------------\n\n";

    // Test Case 4: Empty cart
    ShoppingCart emptyCart;
    std::cout << "Empty Cart Total: $" << emptyCart.calculateTotal() << std::endl; // Expected: 0.0

    return 0;
}