#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Publication {
private:
    std::string title;
    double price;

public:
    // Constructor
    Publication(const std::string& title, double price)
        : title(title), price(price) {}

    // Setters (pass by const reference for strings)
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setPrice(double newPrice) {
        if (newPrice >= 0) { // Basic validation
            price = newPrice;
        } else {
            std::cerr << "Warning: Price cannot be negative. Setting to 0." << std::endl;
            price = 0.0;
        }
    }

    // Display method (const to indicate it doesn't modify object)
    virtual void display() const { // Use virtual for potential polymorphism, though not strictly required by question
        std::cout << "  Title: " << title << std::endl;
        std::cout << "  Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

class Book : public Publication {
private:
    std::string author;

public:
    // Constructor
    Book(const std::string& title, double price, const std::string& author)
        : Publication(title, price), author(author) {}

    // Setter
    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    // Override display method to include book-specific details
    void display() const override {
        Publication::display(); // Call base class display
        std::cout << "  Author: " << author << std::endl;
    }
};

class Magazine : public Publication {
private:
    int issueNumber;

public:
    // Constructor
    Magazine(const std::string& title, double price, int issueNumber)
        : Publication(title, price), issueNumber(issueNumber) {}

    // Setter
    void setIssueNumber(int newIssueNumber) {
        if (newIssueNumber > 0) { // Basic validation
            issueNumber = newIssueNumber;
        } else {
            std::cerr << "Warning: Issue number must be positive. Setting to 1." << std::endl;
            issueNumber = 1;
        }
    }

    // Override display method to include magazine-specific details
    void display() const override {
        Publication::display(); // Call base class display
        std::cout << "  Issue Number: " << issueNumber << std::endl;
    }
};

int main() {
    // Create objects using constructors for proper initialization
    Book myBook("The C++ Programming Language", 69.99, "Bjarne Stroustrup");
    Magazine myMagazine("C++ Magazine", 12.50, 25);

    // Demonstrate setters (optional, as initialized by constructor)
    myBook.setPrice(75.00); // Update price
    myMagazine.setIssueNumber(26); // Update issue number

    std::cout << "--- Displaying Complete Details ---" << std::endl;

    std::cout << "\nBook Details:" << std::endl;
    myBook.display(); // Calls Book's display, which in turn calls Publication's display

    std::cout << "\nMagazine Details:" << std::endl;
    myMagazine.display(); // Calls Magazine's display, which in turn calls Publication's display

    // Demonstrate with invalid setter input
    std::cout << "\n--- Demonstrating setter validation ---" << std::endl;
    myBook.setPrice(-10.00); // Should trigger warning
    myMagazine.setIssueNumber(0); // Should trigger warning

    std::cout << "\nBook Details (after invalid price attempt):" << std::endl;
    myBook.display();

    std::cout << "\nMagazine Details (after invalid issue attempt):" << std::endl;
    myMagazine.display();

    return 0;
}