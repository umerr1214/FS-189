#include <iostream>
#include <string>
#include <utility> // For std::move

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)) {}

    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getISBN() const { return isbn; }
};

// Overload the stream insertion operator for Book objects
// This version has a semantic error: it does not return the ostream reference.
// While it compiles, chaining `std::cout << book1 << book2;` would lead to undefined behavior
// or incorrect results as the return value is not correctly handled.
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Title: " << book.getTitle() << " Author: " << book.getAuthor() << " ISBN: " << book.getISBN();
    // return os; // Semantic error: Missing return statement for non-void function
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << book1 << std::endl; // This line might compile, but chaining would be problematic

    Book book2("1984", "George Orwell", "978-0451524935");
    std::cout << book2 << std::endl; // This line might compile, but chaining would be problematic

    // Example of problematic chaining (commented out as it might cause compilation issues depending on compiler settings)
    // std::cout << book1 << " -- " << book2 << std::endl;

    return 0;
}