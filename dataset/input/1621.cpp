#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed, std::setprecision

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    // Parameterized constructor
    Book(std::string t, std::string a, double p) : title(t), author(a), price(p) {}

    // Public method to display book information
    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

int main() {
    // Example usage for local compilation and testing
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 12.50);
    book1.displayBookInfo();
    std::cout << std::endl;

    // This book has a negative price, which is accepted without validation.
    Book book2("A Book with Negative Price", "Problematic Author", -5.99);
    book2.displayBookInfo();
    return 0;
}