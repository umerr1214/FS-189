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

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }
};

// Syntax Error: Missing comma between `os` and `const Book& book`
std::ostream& operator<<(std::ostream& os const Book& book) {
    os << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN();
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0-345-39180-3");
    std::cout << book1 << std::endl;

    Book book2("1984", "George Orwell", "978-0-451-52493-5");
    std::cout << book2 << std::endl;

    return 0;
}