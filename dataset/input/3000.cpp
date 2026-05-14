#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;

    // Default constructor (initializes with empty strings)
    Book() : title(""), author("") {
        // std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Book(const std::string& t, const std::string& a) : title(t), author(a) {
        // std::cout << "Parameterized constructor called." << std::endl;
    }

    // Copy constructor (SEMANTIC ERROR: takes non-const reference, violating standard copy constructor contract)
    // This prevents copying from const Book objects and is semantically incorrect for a copy constructor.
    Book(Book& other) : title(other.title), author(other.author) {
        // std::cout << "Copy constructor called." << std::endl;
    }

    void print() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Constructors ---" << std::endl;

    // 1. Default Constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.print();

    // 2. Parameterized Constructor
    Book book2("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    std::cout << "Book 2 (Parameterized): ";
    book2.print();

    // 3. Copy Constructor
    Book book3 = book2; // Uses copy constructor, works here because book2 is not const
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.print();

    // If we tried to copy a const book, this would fail to compile:
    // const Book const_book = book2;
    // Book book4 = const_book; // Error: invalid initialization of non-const reference from a const object

    // Modify book3 to show it's a separate copy
    book3.title = "A New Title";
    book3.author = "A New Author";
    std::cout << "Book 3 (Modified): ";
    book3.print();
    std::cout << "Book 2 (Original after Book 3 modified): ";
    book2.print(); // Should remain unchanged

    return 0;
}