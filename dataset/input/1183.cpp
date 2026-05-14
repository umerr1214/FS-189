#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for driver

class Book {
private:
    std::string title;
    std::string author;
    double price; // New private attribute

public:
    // Constructor initializes all attributes, using the setter for price
    Book(const std::string& title, const std::string& author, double initialPrice = 0.0)
        : title(title), author(author) {
        // Initialize price to a safe default before calling setPrice
        this->price = 0.0;
        setPrice(initialPrice); // Use the setter for initial validation
    }

    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }

    // Robustness Issue: Silently fails to update price if negative, without any feedback.
    // The price attribute remains at its previous valid value.
    void setPrice(double newPrice) {
        if (newPrice >= 0.0) {
            price = newPrice;
        }
        // else: price remains unchanged. No error message, no exception.
        // This is robust against invalid state, but not robust in terms of user feedback
        // or clear indication that the operation failed.
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
    book.setPrice(test_price);

    std::ostringstream oss;
    oss.precision(10); // Ensure consistent double output
    oss << book.getPrice();
    return oss.str();
}

int main() {
    // The main function here is primarily for compilation.
    // Actual testing is performed by the 'driver' code provided in the JSON.
    // Example usage:
    Book myBook("Example Title", "Example Author", 10.0);
    myBook.setPrice(-5.0); // This will not change the price due to robustness issue
    myBook.displayBook(); // Output: Price: $10.0
    myBook.setPrice(20.0);
    myBook.displayBook(); // Output: Price: $20.0
    return 0;
}