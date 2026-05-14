#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // No friend declaration for operator<<
    // No public getters for title, author, isbn
    // (Note: The previous problems often had getters, but for a semantic error,
    // we assume they are not present or not used correctly to demonstrate the error.)
};

// Semantic Error: Attempts to access private members (book.title, book.author, book.isbn)
// directly from a non-member, non-friend function.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0-345-39180-3");
    std::cout << book1 << std::endl;

    Book book2("1984", "George Orwell", "978-0-451-52493-5");
    std::cout << book2 << std::endl;

    return 0;
}