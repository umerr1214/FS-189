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

    // SYNTAX ERROR: Missing return type 'void' for setPrice
    setPrice(double newPrice) { 
        if (newPrice >= 0) {
            price = newPrice;
        } else {
            std::cout << "Error: Price cannot be negative. Price not updated." << std::endl;
        }
    }

    double getPrice() const {
        return price;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    book1.setPrice(12.99);
    book1.display();

    Book book2("1984", "George Orwell");
    book2.setPrice(-5.00);
    book2.display();

    Book book3("Dune", "Frank Herbert");
    book3.setPrice(25.50);
    book3.setPrice(-10.00);
    book3.display();

    return 0;
}