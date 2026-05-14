#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int yearPublished;
} // Missing semicolon here, a classic syntax error

void printBookDetails(Book book) {
    std::cout << "Title: " << book.title << std::endl;
    std::cout << "Author: " << book.author << std::endl;
    std::cout << "Year: " << book.yearPublished << std::endl;
}

int main() {
    Book myBook;
    myBook.title = "1984";
    myBook.author = "George Orwell";
    myBook.yearPublished = 1949;

    printBookDetails(myBook);

    return 0;
}