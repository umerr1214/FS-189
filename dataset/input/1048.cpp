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
        std::cout << "ISBN: " << isbn << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Book myBook;
    myBook.setTitle("The C++ Programming Language");
    myBook.setAuthor("Bjarne Stroustrup");
    myBook.setISBN("978-0321563842");

    myBook.displayBookInfo();

    return 0;
}