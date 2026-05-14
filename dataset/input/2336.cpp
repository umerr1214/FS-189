#include <iostream>
#include <string>
#include <vector>

// A simple Book class
class Book {
public:
    std::string isbn;
    std::string title;
    std::string author;

    Book(std::string isbn_val, std::string title_val = "Unknown", std::string author_val = "Unknown")
        : isbn(std::move(isbn_val)), title(std::move(title_val)), author(std::move(author_val)) {}

    Book() : isbn(""), title(""), author("") {}
};

// Overloaded == operator with readability/efficiency issues:
// 1. Efficiency: Books are passed by value, leading to unnecessary copies of potentially large objects.
// 2. Readability: Uses an explicit if-else block for a simple boolean comparison, which could be
//    expressed more concisely with a direct return statement.
bool operator==(Book lhs, Book rhs) { // Passed by value - efficiency issue
    // Readability issue: verbose if-else for a simple comparison
    if (lhs.isbn == rhs.isbn) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Book book1("978-0321992789", "The C++ Programming Language", "Bjarne Stroustrup");
    Book book2("978-0321992789", "C++ Primer", "Stanley B. Lippman"); // Same ISBN as book1
    Book book3("978-1234567890", "Effective C++", "Scott Meyers");
    Book book4("978-1234567890"); // Only ISBN provided
    Book book5("978-9999999999", "Another Book");
    Book book6; // Default constructed, empty ISBN

    std::cout << (book1 == book2 ? "true" : "false") << std::endl; // Expected: true
    std::cout << (book1 == book3 ? "true" : "false") << std::endl; // Expected: false
    std::cout << (book3 == book4 ? "true" : "false") << std::endl; // Expected: true
    std::cout << (book1 == book1 ? "true" : "false") << std::endl; // Expected: true
    std::cout << (book5 == book6 ? "true" : "false") << std::endl; // Expected: false (ISBNs "978-999..." vs "")
    std::cout << (book6 == Book("") ? "true" : "false") << std::endl; // Expected: true (ISBNs "" vs "")

    return 0;
}