#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed, std::setprecision

class Book {
private:
    std::string bookTitle;
    std::string bookAuthor;
    double bookPrice;

public:
    // Parameterized constructor - passes strings by value (inefficient due to copying)
    // Uses less descriptive parameter names (t, a, p)
    Book(std::string t, std::string a, double p) : bookTitle(t), bookAuthor(a), bookPrice(p) {
        // No price validation, but that's not the primary issue highlighted here.
    }

    // Public method to display book information - not declared const (violates best practice for observer methods)
    void displayBookInfo() { // Missing const
        std::cout << "Book Title: " << bookTitle << std::endl;
        std::cout << "Book Author: " << bookAuthor << std::endl;
        std::cout << "Book Price: $" << std::fixed << std::setprecision(2) << bookPrice << std::endl;
    }
};

int main() {
    // Example usage for local compilation and testing
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", 25.99);
    book1.displayBookInfo();
    std::cout << std::endl;

    Book book2("Dune", "Frank Herbert", 15.75);
    book2.displayBookInfo();
    return 0;
}