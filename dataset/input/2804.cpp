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

// Readability / Efficiency Issue: Uses std::endl (flushes buffer) and inefficient string concatenation
std::ostream& operator<<(std::ostream& os, const Book& book) {
    // Inefficient string concatenation and use of std::endl
    os << "Title: " + book.title + " Author: " + book.author + " ISBN: " + book.isbn + std::endl;
    return os;
}

int main() {
    // Test cases for Readability / Efficiency Issue
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "George Orwell", "978-0451524935");
    Book book3("To Kill a Mockingbird", "Harper Lee", "978-0061120084");

    std::cout << book1;
    std::cout << book2;
    std::cout << book3;

    return 0;
}