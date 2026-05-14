#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int yearPublished;
};

void printBookDetails(Book book) {
    std::cout << "Title: " << book.title << std::endl;
    // Logical error: Prints author again instead of yearPublished
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Year: " << book.author << std::endl; // Should be book.yearPublished
}

int main() {
    Book myBook;
    myBook.title = "To Kill a Mockingbird";
    myBook.author = "Harper Lee";
    myBook.yearPublished = 1960;

    printBookDetails(myBook);

    return 0;
}