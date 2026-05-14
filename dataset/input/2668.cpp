#include <iostream>
#include <string>

class Book {
private:
    std::strng title; // Syntax Error: Typo 'strng' instead of 'string'
    std::string author;
    std::string isbn;

public:
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }

    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook;
    myBook.setTitle("The Hitchhiker's Guide to the Galaxy");
    myBook.setAuthor("Douglas Adams");
    myBook.setISBN("978-0345391803");
    myBook.displayBookInfo();
    return 0;
}