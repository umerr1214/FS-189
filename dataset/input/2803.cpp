#include <iostream>
#include <string>
#include <vector> // Required for test driver
#include <utility> // Required for std::move

// Book class definition (from Q1 context)
class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)) {}
};

// Robustness Issue: Prints labels even for empty fields, potentially leading to confusing output
// or parsing issues. Doesn't explicitly indicate missing data.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << " Author: " << book.author << " ISBN: " << book.isbn << '\n';
    return os;
}

int main() {
    // Test cases for Robustness Issue
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "", "978-0451524935"); // Empty author
    Book book3("Brave New World", "Aldous Huxley", ""); // Empty ISBN
    Book book4("", "", ""); // All empty

    std::cout << book1;
    std::cout << book2;
    std::cout << book3;
    std::cout << book4;

    return 0;
}