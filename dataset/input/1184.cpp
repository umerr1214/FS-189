#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for driver

class Book {
private:
    std::string title;
    std::string author;
  double price; // Inconsistent indentation for readability issue

public:
    // Constructor initializes all attributes, using the setter for price
    Book(const std::string& title, const std::string& author, double initialPrice = 0.0)
        : title(title), author(author)
    {
        // Use the setter for initial price, which has the readability/efficiency issue
        setPrice(initialPrice);
    }

    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }

    // Readability/Efficiency Issue: Overly verbose validation, unnecessary boolean,
    // redundant comparison, and unnecessary output to console within a setter.
    void setPrice(double newPrice) {
        bool price_is_non_negative = (newPrice >= 0.0); // Unnecessary temporary boolean variable
        if (price_is_non_negative == true) { // Redundant comparison to true, reducing readability
            this->price = newPrice;
        }
        else {
            // Efficiency issue: Printing to console inside a setter can be inefficient
            // if called frequently, and affects separation of concerns.
            std::cout << "Warning: Attempted to set a negative price. Price will be set to 0.0 instead." << std::endl;
            this->price = 0.0; // Ensures price is never negative, but chosen default might be unexpected by user
        }
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
    std::ostringstream oss_output;
    std::streambuf* old_cout = std::cout.rdbuf();
    std::cout.rdbuf(oss_output.rdbuf()); // Redirect cout to capture warning messages

    Book book(input_title, input_author, initial_price);
    book.setPrice(test_price);

    std::cout.rdbuf(old_cout); // Restore cout to its original buffer

    std::ostringstream oss_price;
    oss_price.precision(10); // Ensure consistent double output
    oss_price << book.getPrice();
    return oss_output.str() + oss_price.str(); // Return both captured output and final price
}

int main() {
    // The main function here is primarily for compilation.
    // Actual testing is performed by the 'driver' code provided in the JSON.
    // Example usage:
    Book myBook("Example Title", "Example Author", 15.99);
    myBook.setPrice(-5.0); // Should print warning and set price to 0.0
    myBook.displayBook();
    myBook.setPrice(20.50); // Should set price and not print a warning
    myBook.displayBook();
    return 0;
}