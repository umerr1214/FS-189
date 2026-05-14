#include <iostream>
#include <string>

class Book {
private:
    std::string title;
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
        // Logical Error: Prints hardcoded empty strings instead of the actual member variables
        std::cout << "Title: " << "" << std::endl;
        std::cout << "Author: " << "" << std::endl;
        std::cout << "ISBN: " << "" << std::endl;
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