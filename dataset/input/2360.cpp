#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate
#include <list>    // Using list for no particular reason other than to show an alternative that might be less efficient for random access, but still works.

class Item {
public:
    std::string nm; // Poor variable name
    double prc;     // Poor variable name
    int qty;        // Poor variable name

    Item(std::string name_param, double price_param, int quantity_param)
        : nm(std::move(name_param)), prc(price_param), qty(quantity_param) {}

    // Getters for external use (might be slightly verbose for simple access)
    std::string getItemName() const { return nm; }
    double getItemPrice() const { return prc; }
    int getItemQuantity() const { return qty; }
};

class ShoppingCart {
private:
    std::list<Item> items_list; // Using std::list, which is less efficient for iteration than std::vector in many cases due to cache locality.

public:
    void addItem(Item item_to_add) { // Passing Item by value, causing a copy, then another copy into the list.
        items_list.push_back(item_to_add); // Another copy
    }

    double calculateTotal() {
        double total_sum = 0.0;
        // Using a traditional iterator-based loop, which is more verbose than a range-based for loop or std::accumulate.
        for (std::list<Item>::iterator it = items_list.begin(); it != items_list.end(); ++it) {
            total_sum += it->prc * it->qty; // Accessing members directly from iterator, using poorly named variables
        }
        return total_sum;
    }

    // Helper for demonstration
    void printCartContents() const {
        if (items_list.empty()) {
            std::cout << "Cart is currently empty.\n";
            return;
        }
        std::cout << "--- Cart Contents ---\n";
        for (const auto& i : items_list) { // Using range-based for loop here for printing, but not for calculation
            std::cout << i.getItemName() << " (" << i.getItemQuantity() << " @ $" << i.getItemPrice() << ")\n";
        }
        std::cout << "---------------------\n";
    }
};

int main() {
    ShoppingCart myCart;

    // Adding items
    myCart.addItem(Item("Book", 15.99, 2));
    myCart.addItem(Item("Pen Set", 8.50, 1));
    myCart.addItem(Item("Notebook", 3.25, 3));

    std::cout << "Cart contents after adding items:\n";
    myCart.printCartContents();
    std::cout << "Calculated total: $" << myCart.calculateTotal() << std::endl; // Expected: (15.99*2) + (8.50*1) + (3.25*3) = 31.98 + 8.50 + 9.75 = 50.23

    std::cout << "\n---------------------------\n\n";

    // Adding more items
    myCart.addItem(Item("Eraser", 1.00, 5));
    std::cout << "Cart contents after adding Eraser:\n";
    myCart.printCartContents();
    std::cout << "New total: $" << myCart.calculateTotal() << std::endl; // Expected: 50.23 + (1.00*5) = 55.23

    std::cout << "\n---------------------------\n\n";

    // Empty cart test
    ShoppingCart anotherCart;
    std::cout << "Another cart total (empty): $" << anotherCart.calculateTotal() << std::endl; // Expected: 0.0

    return 0;
}