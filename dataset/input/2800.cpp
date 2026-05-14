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
std::ostream& operator<<(std::ostream& os, const Book& book)
{
    os << "Title: " << book.getTitle() << " Author: " << book.getAuthor() << " ISBN: " << book.getISBN();
    return os // Missing semicolon here, this is a syntax error
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << book1 << std::endl;

    Book book2("1984", "George Orwell", "978-0451524935");
    std::cout << book2 << std::endl;

    return 0;
}