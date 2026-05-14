#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int yearPublished;
};

void printBookDetails(Book book) {
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Year: " << book.yearPublished << std::endl;
    // Semantic error: Attempting to access a non-existent member 'publisher'
    // This will result in a compile-time error.
    std::cout << "Publisher: " << book.publisher << std::endl;
}

int main() {
    Book myBook;
    myBook.title = "The Great Gatsby";
    myBook.author = "F. Scott Fitzgerald";
    myBook.yearPublished = 1925;

    printBookDetails(myBook);

    return 0;
}