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

// Correct Version: Efficiently prints formatted book details, handling empty fields gracefully.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << (book.title.empty() ? "N/A" : book.title)
       << " Author: " << (book.author.empty() ? "N/A" : book.author)
       << " ISBN: " << (book.isbn.empty() ? "N/A" : book.isbn)
       << '\n';
    return os;
}

int main() {
    // Test cases for Correct Version
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "", "978-0451524935"); // Empty author
    Book book3("Brave New World", "Aldous Huxley", ""); // Empty ISBN
    Book book4("", "", ""); // All empty
    Book book5("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");

    std::cout << book1;
    std::cout << book2;
    std::cout << book3;
    std::cout << book4;
    std::cout << book5;

    return 0;
}