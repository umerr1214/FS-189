#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits, if using ignore, but not strictly needed with std::ws

struct Book {
    std::string title;
    std::string author;
    int publication_year;
};

int main() {
    Book books[3]; // Uses a C-style array instead of std::array or std::vector

    std::cout << "Enter details for three books:" << std::endl; // Inefficient std::endl
    for (int i = 0; i < 3; ++i) {
        std::cout << std::endl << "Book " << i + 1 << ":" << std::endl; // Inefficient std::endl
        
        std::cout << "Enter title: ";
        // Using std::ws to correctly handle newlines from previous inputs, ensuring correctness.
        std::getline(std::cin >> std::ws, books[i].title); 
        
        std::cout << "Enter author: ";
        std::getline(std::cin, books[i].author);
        
        std::cout << "Enter publication year: ";
        std::cin >> books[i].publication_year; // Leaves newline, handled by std::ws in next iteration
    }

    std::cout << std::endl << "--- Book Details ---" << std::endl; // Inefficient std::endl
    for (int i = 0; i < 3; ++i) {
        std::cout << std::endl << "Book " << i + 1 << ":" << std::endl; // Inefficient std::endl
        std::cout << "Title: " << books[i].title << std::endl; // Inefficient std::endl
        std::cout << "Author: " << books[i].author << std::endl; // Inefficient std::endl
        std::cout << "Publication Year: " << books[i].publication_year << std::endl; // Inefficient std::endl
    }

    return 0;
}