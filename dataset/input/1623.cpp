#include <iostream>
#include <string>
#include <iomanip> // Required for std::fixed, std::setprecision

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    // Parameterized constructor with const references for efficiency and proper naming
    Book(const std::string& title, const std::string& author, double price)
        : title(title), author(author), price(price) {
        // Basic validation for price for robustness, setting to 0 if negative.
        if (this->price < 0) {
            this->price = 0.0;
        }
    }

    // Public method to display book information, declared const as it doesn't modify state
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

int main() {
    // Example usage for local compilation and testing
    Book book1("The Alchemist", "Paulo Coelho", 11.50);
    book1.displayBookInfo();
    std::cout << std::endl;

    Book book2("To Kill a Mockingbird", "Harper Lee", 9.75);
    book2.displayBookInfo();
    std::cout << std::endl;

    // Test with negative price to show validation working correctly
    Book book3("Validated Book", "Good Developer", -3.00);
    book3.displayBookInfo();
    return 0;
}