#include <iostream>
#include <string>
#include <vector>

// Define a C++ struct named Book
struct Book {
    std::string title;
    std::string author;
    int publication_year;
} // SYNTAX ERROR: Missing semicolon after struct definition

int main() {
    // Create an array of three Book objects
    Book books[3];

    // Prompt the user to enter details for each book
    std::cout << "Please enter details for three books:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter details for Book " << (i + 1) << ":\n";
        std::cout << "Enter title: ";
        std::getline(std::cin >> std::ws, books[i].title); // std::ws consumes leading whitespace, including newlines
        std::cout << "Enter author: ";
        std::getline(std::cin >> std::ws, books[i].author);
        std::cout << "Enter publication year: ";
        std::cin >> books[i].publication_year;
    }

    // Print the details of all books
    std::cout << "\nBook Details:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Title: " << books[i].title
                  << ", Author: " << books[i].author
                  << ", Year: " << books[i].publication_year << "\n";
    }

    return 0;
}