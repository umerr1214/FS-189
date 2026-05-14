#include <iostream>
#include <string>

// Define a C++ struct named Book
struct Book {
    std::string title;
    std::string author;
    int publication_year;
};

int main() {
    // Create an array of three Book objects
    Book books[3]; // Valid indices are 0, 1, 2

    // Prompt the user to enter details for each book
    std::cout << "Please enter details for three books:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter details for Book " << (i + 1) << ":\n";
        std::cout << "Enter title: ";
        std::getline(std::cin >> std::ws, books[i].title); // Corrected input reading
        std::cout << "Enter author: ";
        std::getline(std::cin >> std::ws, books[i].author);
        std::cout << "Enter publication year: ";
        std::cin >> books[i].publication_year;
    }

    // Print the details of all books
    std::cout << "\nBook Details:\n";
    // SEMANTIC ERROR: Loop iterates one too many times, accessing books[3] which is out of bounds.
    for (int i = 0; i <= 3; ++i) { // Loop condition should be i < 3 for an array of size 3
        std::cout << "Title: " << books[i].title
                  << ", Author: " << books[i].author
                  << ", Year: " << books[i].publication_year << "\n";
    }

    return 0;
}