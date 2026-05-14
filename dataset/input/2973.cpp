#include <iostream> // Required for std::cout
#include <string>   // Required for std::string

// Defines a Book class with private members and public methods as specified.
class Book {
private:
    std::string title_;  // Descriptive name for book title, using a common suffix for members
    std::string author_; // Descriptive name for book author
    std::string isbn_;   // Descriptive name for book ISBN

public:
    // Parameterized constructor:
    // Uses 'const std::string&' for parameters to efficiently pass string arguments
    // without unnecessary copies.
    // Uses a member initializer list for direct and efficient initialization of member variables,
    // avoiding default construction followed by assignment.
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title_(title), author_(author), isbn_(isbn) {
        // Constructor body can be empty if no other logic is needed,
        // as all initialization is handled by the initializer list.
    }

    // Public method to display all book details:
    // Marked as 'const' because it does not modify the object's state,
    // which is good practice for accessor methods.
    // Uses '\n' for newlines, which is generally more efficient than std::endl
    // as it doesn't force a flush of the output buffer unless explicitly needed.
    void displayBookInfo() const {
        std::cout << "Title: " << title_ << "\n";
        std::cout << "Author: " << author_ << "\n";
        std::cout << "ISBN: " << isbn_ << "\n";
    }
};

int main() {
    // Create an instance of the Book class with valid details
    Book myBook("The Martian", "Andy Weir", "978-0553448138");

    // Call the method to display its information
    myBook.displayBookInfo();

    std::cout << "\n--- Another book ---\n";
    // Create another instance and display its details
    Book anotherBook("Dune", "Frank Herbert", "978-0441172719");
    anotherBook.displayBookInfo();

    return 0;
}