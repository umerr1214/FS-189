#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for driver

class Book {
private:
    std::string title;
    std::string author;
    double price; // Private price attribute

public:
    // Constructor initializes all attributes, using the setter for price
    Book(const std::string& title, const std::string& author, double initialPrice = 0.0)
        : title(title), author(author) {
        // Ensure price is initialized to a valid state, even if setPrice fails
        this->price = 0.0;
        setPrice(initialPrice); // Use the setter for initial validation
    }

    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }

    // Public setter method for price with validation.
    // Returns true if price was set successfully, false otherwise.
    // This provides clear feedback to the caller without side effects like printing.
    bool setPrice(double newPrice) {
        if (newPrice >= 0.0) {
            price = newPrice;
            return true; // Price was set successfully
        }
        return false; // Price was not set due to negative value
    }

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    double getPrice() const { return price; }

    void displayBook() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << std::endl;
    }
};

// Driver for testing
std::string run_test(const std::string& input_title, const std::string& input_author, double initial_price, double test_price) {
    Book book(input_title, input_author, initial_price);
    bool set_success = book.setPrice(test_price);

    std::ostringstream oss;
    oss.precision(10); // Ensure consistent double output
    oss << book.getPrice() << "," << (set_success ? "true" : "false");
    return oss.str();
}

int main() {
    // The main function here is primarily for compilation.
    // Actual testing is performed by the 'driver' code provided in the JSON.
    // Example usage:
    Book myBook("Example Title", "Example Author", 15.99);
    bool success1 = myBook.setPrice(-5.0); // Should return false
    myBook.displayBook(); // Output: Price: $15.99
    bool success2 = myBook.setPrice(20.50); // Should return true
    myBook.displayBook(); // Output: Price: $20.50
    std::cout << "Set 1 success: " << (success1 ? "true" : "false") << std::endl;
    std::cout << "Set 2 success: " << (success2 ? "true" : "false") << std::endl;
    return 0;
}