#include <iostream>
#include <string>
#include <cstring> // For strlen, strcpy

// Helper to safely copy C-style strings
char* string_copy(const char* src) {
    if (!src) return nullptr;
    char* dest = new char[std::strlen(src) + 1];
    std::strcpy(dest, src);
    return dest;
}

class Book {
private:
    char* title;
    char* author;

public:
    // Constructor
    Book(const char* title_str, const char* author_str) {
        title = string_copy(title_str);
        author = string_copy(author_str);
    }

    // Destructor to free dynamically allocated memory
    ~Book() {
        delete[] title;
        delete[] author;
    }

    // ROBUSTNESS ISSUE:
    // Missing copy constructor and copy assignment operator.
    // The default implicitly generated ones will perform shallow copies,
    // leading to double-free errors when Book objects are copied
    // and then destructed. This violates the Rule of Three/Five.

    const char* getTitle() const { return title; }
    const char* getAuthor() const { return author; }

    // Friend declaration for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// Overload the << operator for Book objects
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << (book.title ? book.title : "N/A")
       << ", Author: " << (book.author ? book.author : "N/A");
    return os;
}

int main() {
    // Test case 1: Basic printing of a Book object
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    std::cout << "Book 1: " << book1 << '\n';

    // Test case 2: Implicit call to default copy constructor
    // This performs a shallow copy, making book_copy.title point to the same memory as book1.title.
    // When both book1 and book_copy are destructed, 'title' and 'author' will be double-freed.
    Book book_copy = book1;
    std::cout << "Book Copy: " << book_copy << '\n';

    // Test case 3: Implicit call to default copy assignment operator
    // This also performs a shallow copy without proper memory management.
    Book book_assigned("Temporary Title", "Temporary Author");
    book_assigned = book1; // book_assigned's original memory is leaked, then points to book1's memory
    std::cout << "Book Assigned: " << book_assigned << '\n';

    // The program will likely crash upon exiting main due to double-free errors
    // when book1, book_copy, and book_assigned are destructed.
    // The operator<< itself works correctly for valid pointers.
    return 0;
}