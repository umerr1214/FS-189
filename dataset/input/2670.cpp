#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    void setTitle(const std::string& title) { // Semantic Error: Parameter 'title' shadows member 'title'
        // This line assigns the parameter 'title' to itself, not to the member 'this->title'
        title = title;
    }

    void setAuthor(const std::string& author) { // Parameter 'author' shadows member 'author'
        author = author;
    }

    void setISBN(const std::string& isbn) { // Parameter 'isbn' shadows member 'isbn'
        isbn = isbn;
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