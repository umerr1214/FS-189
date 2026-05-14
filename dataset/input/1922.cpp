#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string theBookTitle; // Verbose member name
    std::string theBookAuthor; // Verbose member name
    std::string theBookISBN;   // Verbose member name

public:
    Book() : theBookTitle(""), theBookAuthor(""), theBookISBN("") {}
    Book(std::string initialTitle, std::string initialAuthor, std::string initialISBN) // Pass by value in constructor
        : theBookTitle(initialTitle), theBookAuthor(initialAuthor), theBookISBN(initialISBN) {}

    // Setters - Efficiency issue: pass by value (creates unnecessary copies)
    // Readability issue: verbose method names
    void updateBookTitle(std::string newTitle) {
        theBookTitle = newTitle;
    }
    void updateBookAuthor(std::string newAuthor) {
        theBookAuthor = newAuthor;
    }
    void updateBookISBN(std::string newISBN) {
        theBookISBN = newISBN;
    }

    // Getters - Efficiency issue: returning by value (creates unnecessary copies)
    // Readability issue: verbose method names, not const-qualified
    std::string retrieveBookTitle() {
        return theBookTitle;
    }
    std::string retrieveBookAuthor() {
        return theBookAuthor;
    }
    std::string retrieveBookISBN() {
        return theBookISBN;
    }
};

int main() {
    Book myBook;
    myBook.updateBookTitle("1984");
    myBook.updateBookAuthor("George Orwell");
    myBook.updateBookISBN("978-0451524935");

    std::cout << "Book Details:" << std::endl;
    std::cout << "Title: " << myBook.retrieveBookTitle() << std::endl;
    std::cout << "Author: " << myBook.retrieveBookAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.retrieveBookISBN() << std::endl;

    myBook.updateBookTitle("Animal Farm");
    std::cout << "\nUpdated Title: " << myBook.retrieveBookTitle() << std::endl;

    return 0;
}