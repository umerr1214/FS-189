#include <iostream>
#include <vector>
#include <string>
#include <numeric> // Required for std::accumulate
#include <utility> // Required for std::move

class Item {
public:
    std::string name;
    double price;
    int quantity;

    // Constructor using initializer list and std::move for string
    Item(std::string name, double price, int quantity)
        : name(std::move(name)), price(price), quantity(quantity) {
        // Basic validation for robustness (optional, but good practice for a correct version)
        if (price < 0) {
            this->price = 0; // Ensure price is non-negative
        }
        if (quantity < 0) {
            this->quantity = 0; // Ensure quantity is non-negative
        }
    }

    // Getters for accessing private members (if members were private)
    // For this example, members are public as per typical simple data structures.
    double getSubtotal() const {
        return price * quantity;
    }
};

class ShoppingCart {
private:
    std::vector<Item> items; // Using std::vector for efficient storage and iteration

public:
    // addItem method using const reference to avoid unnecessary copies
    void addItem(const Item& item) {
        items.push_back(item);
    }

    // Overload for rvalue references to allow move semantics for temporary items
    void addItem(Item&& item) {
        items.push_back(std::move(item));
    }

    // calculateTotal method using std::accumulate for conciseness and efficiency
    double calculateTotal() const {
        // Use std::accumulate with a lambda function for a clean sum calculation
        return std::accumulate(items.begin(), items.end(), 0.0,
                               [](double current_total, const Item& item) {
                                   return current_total + item.getSubtotal();
                               });
    }

    // Helper method for displaying cart contents (good for testing/debugging)
    void displayCart() const {
        if (items.empty()) {
            std::cout << "Shopping cart is empty.\n";
            return;
        }
        std::cout << "--- Current Shopping Cart ---\n";
        for (const auto& item : items) {
            std::cout << "- " << item.name << " (Qty: " << item.quantity
                      << ", Price: $" << item.price << ") -> Subtotal: $"
                      << item.getSubtotal() << std::endl;
        }
        std::cout << "-----------------------------\n";
    }
};

int main() {
    ShoppingCart myCart;

    // Add items using different addItem overloads
    myCart.addItem(Item("Laptop", 1200.0, 1)); // Uses rvalue overload
    Item mouse("Wireless Mouse", 25.0, 2);
    myCart.addItem(mouse);                     // Uses const lvalue reference overload
    myCart.addItem(Item("Keyboard", 75.0, 1));
    myCart.addItem(Item("USB Hub", 15.50, 3));

    std::cout << "After adding several items:\n";
    myCart.displayCart();
    std::cout << "Total cart value: $" << myCart.calculateTotal() << std::endl; // Expected: 1200 + 50 + 75 + 46.5 = 1371.5

    std::cout << "\n---------------------------\n\n";

    // Test with an empty cart
    ShoppingCart emptyCart;
    std::cout << "Empty cart total: $" << emptyCart.calculateTotal() << std::endl; // Expected: 0.0

    std::cout << "\n---------------------------\n\n";

    // Test robustness: add item with negative quantity/price (should be corrected by Item constructor)
    myCart.addItem(Item("Defective Charger", -5.0, 1)); // Price corrected to 0
    myCart.addItem(Item("Expired Candy", 2.0, -10));    // Quantity corrected to 0
    std::cout << "After adding items with initially negative values (corrected):\n";
    myCart.displayCart();
    std::cout << "Total cart value: $" << myCart.calculateTotal() << std::endl; // Should remain 1371.5 as corrected items have 0 subtotal

    return 0;
}