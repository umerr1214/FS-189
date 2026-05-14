#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    void setTitle(std::string newTitle) {
        title = newTitle;
    }

    void setAuthor(std::string newAuthor) {
        author = newAuthor;
    }

    void setISBN(std::string newISBN) {
        isbn = newISBN;
    }

    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        // Logical Error: Always prints a fixed ISBN instead of the actual `isbn` attribute
        std::cout << "ISBN: " << "Fixed ISBN-12345" << std::endl;
    }
};

int main() {
    Book myBook;
    myBook.setTitle("Effective Modern C++");
    myBook.setAuthor("Scott Meyers");
    myBook.setISBN("978-1491903995"); // This value will not be displayed correctly

    myBook.displayBookInfo();

    std::cout << "--- Another Book ---" << std::endl;
    Book anotherBook;
    anotherBook.setTitle("Clean Code");
    anotherBook.setAuthor("Robert C. Martin");
    anotherBook.setISBN("978-0132350884"); // This value will also not be displayed correctly
    anotherBook.displayBookInfo();

    return 0;
}