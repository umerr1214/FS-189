#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price; // Member variable

public:
    Book(const std::string& title, const std::string& author)
        : title(title), author(author), price(0.0) {} // Initialize price

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << std::endl;
    }

    void setPrice(double price) { // Parameter 'price' SEMANTIC ERROR: shadows member 'price'
        if (price >= 0) { // This 'price' refers to the parameter
            price = price; // SEMANTIC ERROR: Assigns parameter to itself. Member 'this->price' is never modified.
                           // To fix, it should be 'this->price = price;'
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
    book1.setPrice(12.99); // Expected to set price, but won't due to semantic error
    book1.display();

    Book book2("1984", "George Orwell");
    book2.setPrice(-5.00); // Expected to report error, will report error (correct behavior for this input)
    book2.display();

    Book book3("Dune", "Frank Herbert");
    book3.setPrice(25.50); // Expected to set price, but won't due to semantic error
    book3.setPrice(-10.00); // Expected to report error, will report error (correct behavior for this input)
    book3.display();

    return 0;
}