#include <iostream>
#include <string>
#include <array> // Using std::array for fixed-size array

// Define the Book struct
struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

int main() {
    // Create an array of 3 Book structs
    std::array<Book, 3> books;

    // Populate the details for each book
    books[0].title = "The Hitchhiker's Guide to the Galaxy";
    books[0].author = "Douglas Adams";
    books[0].publicationYear = 1979;

    books[1].title = "1984";
    books[1].author = "George Orwell";
    books[1].publicationYear = 0; // Robustness issue: an invalid publication year (0) is accepted and printed without validation.

    books[2].title = "Pride and Prejudice";
    books[2].author = "Jane Austen";
    books[2].publicationYear = 1813;

    // Iterate through the array and print the details of each book
    for (size_t i = 0; i < books.size(); ++i) {
        std::cout << "Book " << i + 1 << ": ";
        std::cout << "Title: " << books[i].title << ", ";
        std::cout << "Author: " << books[i].author << ", ";
        std::cout << "Year: " << books[i].publicationYear << std::endl;
    }

    return 0;
}