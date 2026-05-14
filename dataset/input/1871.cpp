#include <iostream>
#include <string>
#include <iomanip>

// Base class Publication
class Publication {
private:
    std::string title;
    double price;

public:
    // Constructor
    Publication(const std::string& t = "", double p = 0.0) : title(t), price(p) {}

    // Setters
    void setTitle(const std::string& t) {
        title = t;
    }

    void setPrice(double p) {
        price = p;
    }

    // Display method
    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price << std::endl;
    }
};

// Derived class Book
class Book : public Publication {
private:
    std::string author;

public:
    // Constructor
    Book(const std::string& t = "", double p = 0.0, const std::string& a = "")
        : Publication(t, p), author(a) {}

    // Setter
    void setAuthor(const std::string& a) {
        author = a;
    }

    // Logical Error: Does not call base class Publication::display(), resulting in incomplete output.
    void display() const {
        // Publication::display(); // Correct implementation would include this call
        std::cout << "Author: " << author << std::endl;
    }
};

// Derived class Magazine
class Magazine : public Publication {
private:
    int issueNumber;

public:
    // Constructor
    Magazine(const std::string& t = "", double p = 0.0, int i = 0)
        : Publication(t, p), issueNumber(i) {}

    // Setter
    void setIssueNumber(int i) {
        issueNumber = i;
    }

    // Logical Error: Does not call base class Publication::display(), resulting in incomplete output.
    void display() const {
        // Publication::display(); // Correct implementation would include this call
        std::cout << "Issue Number: " << issueNumber << std::endl;
    }
};

// Main function for demonstration
int main() {
    // Create Book object
    Book myBook("The C++ Programming Language", 59.99, "Bjarne Stroustrup");
    std::cout << "--- Book Details ---" << std::endl;
    myBook.display(); // Will only show author due to logical error
    std::cout << std::endl;

    // Create Magazine object
    Magazine myMagazine("C++ Magazine", 9.50, 123);
    std::cout << "--- Magazine Details ---" << std::endl;
    myMagazine.display(); // Will only show issue number due to logical error
    std::cout << std::endl;

    // Demonstrate setters
    Book anotherBook;
    anotherBook.setTitle("Effective C++");
    anotherBook.setPrice(45.00);
    anotherBook.setAuthor("Scott Meyers");
    std::cout << "--- Another Book Details (using setters) ---" << std::endl;
    anotherBook.display(); // Will only show author due to logical error
    std::cout << std::endl;

    return 0;
}