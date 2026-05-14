#include <iostream>
#include <string>
#include <array> // Recommended for fixed-size arrays

// Define the Book struct
struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

// Helper function to print book details for better readability and reusability
void printBookDetails(const Book& book, int bookNumber) {
    std::cout << "Book " << bookNumber << ": ";
    std::cout << "Title: " << book.title << ", ";
    std::cout << "Author: " << book.author << ", ";
    std::cout << "Year: " << book.publicationYear << std::endl;
}

int main() {
    // Create an array of 3 Book structs using std::array
    std::array<Book, 3> books;

    // Populate the details for each book
    books[0] = {"Dune", "Frank Herbert", 1965};
    books[1] = {"Sapiens", "Yuval Noah Harari", 2011};
    books[2] = {"The Midnight Library", "Matt Haig", 2020};

    // Iterate through the array using a range-based for loop for conciseness and readability
    int bookCount = 1;
    for (const Book& book : books) {
        printBookDetails(book, bookCount++);
    }

    return 0;
}