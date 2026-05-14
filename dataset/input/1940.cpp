#include <iostream>
#include <cstring> // For strlen, strcpy
#include <vector>  // To demonstrate object lifecycle in containers

// This version is functionally correct but uses raw char* for string management,
// which is generally less readable, more error-prone, and often less efficient
// than using std::string in modern C++.
class Book {
private:
    char* title; // Using char* requiring manual memory management
    int id;      // Unique ID for each book instance

    // Helper function for deep copying title
    void copyTitle(const char* otherTitle) {
        if (title) { // If `title` already points to memory, free it first
            delete[] title;
        }
        if (otherTitle) {
            title = new char[strlen(otherTitle) + 1];
            strcpy(title, otherTitle);
        } else {
            title = new char[1];
            title[0] = '\0';
        }
    }

public:
    // Constructor
    Book(const char* t, int bookId) : id(bookId) {
        title = nullptr; // Initialize before calling copyTitle
        copyTitle(t);
        std::cout << "Book '" << title << "' (ID: " << id << ") constructed." << std::endl;
    }

    // Copy Constructor (Deep Copy)
    Book(const Book& other) : id(other.id) {
        title = nullptr; // Initialize before copying
        copyTitle(other.title);
        std::cout << "Book '" << title << "' (ID: " << id << ") copied constructed from ID " << other.id << "." << std::endl;
    }

    // Copy Assignment Operator (Deep Copy)
    Book& operator=(const Book& other) {
        if (this != &other) { // Handle self-assignment
            // Clean up existing resource before acquiring new one
            delete[] title;
            id = other.id;
            title = nullptr; // Reset to nullptr before deep copying
            copyTitle(other.title);
            std::cout << "Book '" << title << "' (ID: " << id << ") copy assigned from ID " << other.id << "." << std::endl;
        }
        return *this;
    }

    // Destructor as per question
    // Correctly frees the dynamically allocated memory.
    ~Book() {
        std::cout << "Book '" << title << "' (ID: " << id << ") is being destroyed." << std::endl;
        delete[] title;
    }

    const char* getTitle() const {
        return title;
    }
};

// Function to demonstrate object lifecycles with copy constructor and assignment
void createAndManipulateBooks() {
    Book book1("The Hobbit", 101);
    Book book2 = book1; // Calls copy constructor
    
    // Create a temporary book and assign it
    book2 = Book("Effective C++", 102); // Calls constructor for temporary, then copy assignment
    
    Book book3("Clean Code", 103);
    book3 = book1; // Calls copy assignment

    std::cout << "--- Populating vector ---" << std::endl;
    std::vector<Book> shelf;
    shelf.reserve(3); // Pre-allocate to avoid reallocations which might involve extra copies/moves
    shelf.push_back(Book("The Pragmatic Programmer", 104)); // Calls constructor for temporary, then copy/move into vector
    shelf.emplace_back("Design Patterns", 105); // Constructs in-place
    shelf.push_back(Book("I, Robot", 106)); // Calls constructor for temporary, then copy/move into vector
    std::cout << "--- Vector populated ---" << std::endl;

    // Demonstrate block scope destruction
    {
        Book tempBook("Temporary Read", 107);
        std::cout << "Inside temporary block." << std::endl;
    } // tempBook is destroyed here
    std::cout << "Outside temporary block." << std::endl;
}

int main() {
    std::cout << "--- Starting Readability/Efficiency Test ---" << std::endl;
    createAndManipulateBooks();
    std::cout << "--- Readability/Efficiency Test Ended ---" << std::endl;
    // All remaining stack-allocated objects (book1, book2, book3) and vector elements are destroyed here.
    return 0;
}