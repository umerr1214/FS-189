#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price; // New attribute

public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author), price(0.0) {} // Initialize price

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << std::endl;
    }

    void setPrice(double newPrice) {
        // LOGICAL ERROR: Inverted validation and incorrect assignment logic
        if (newPrice < 0) { // If newPrice IS negative
            price = newPrice; // LOGICAL ERROR: Sets negative price
            std::cout << "Warning: Negative price was set!" << std::endl; // Added for clarity during execution
        } else { // If newPrice is NOT negative (i.e., >= 0)
            std::cout << "Error: Price cannot be negative. Price not updated." << std::endl; // LOGICAL ERROR: Reports error for valid price
            // LOGICAL ERROR: Price is not updated for valid positive values
        }
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    book1.setPrice(12.99); // Should set price, but will report error and not set
    book1.display();

    Book book2("1984", "George Orwell");
    book2.setPrice(-5.00); // Should report error and not set, but will set negative price
    book2.display();

    Book book3("Dune", "Frank Herbert");
    book3.setPrice(25.50); // Should set price, but will report error and not set
    book3.setPrice(-10.00); // Should report error and not set, but will set negative price
    book3.display();

    return 0;
}