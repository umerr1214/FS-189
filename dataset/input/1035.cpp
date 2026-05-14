#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Friend declaration for operator<<
    // The definition below uses incorrect parameter and return types for std::ostream
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// SEMANTIC ERROR: operator<< takes and returns std::ostream by value instead of by reference.
// This compiles but is semantically incorrect for stream operators, leading to inefficient copies
// and breaking the ability to chain operations properly.
std::ostream operator<<(std::ostream os, const Book& book) {
    os << book.title << " by " << book.author << " (" << book.isbn << ")";
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "George Orwell", "978-0451524935");
    Book book3("Pride and Prejudice", "Jane Austen", "978-0141439518");

    std::cout << "Test Case 1: " << book1 << std::endl;
    // Chaining might not work as expected due to semantic error
    // std::cout << "Test Case 2: " << book2 << " - Chained\n"; // This line would fail to compile or behave unexpectedly
    std::cout << "Test Case 2: " << book2 << std::endl;
    std::cout << "Test Case 3: " << book3 << std::endl;

    return 0;
}