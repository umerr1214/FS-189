#include <iostream>
#include <string>
#include <array> // Using std::array for fixed size, but the core issue is input handling

struct Book {
    std::string title;
    std::string author;
    int publication_year;
};

int main() {
    std::array<Book, 3> books;

    std::cout << "Enter details for three books:\n";
    for (int i = 0; i < books.size(); ++i) {
        std::cout << "\nBook " << i + 1 << ":\n";
        
        std::cout << "Enter publication year: ";
        std::cin >> books[i].publication_year; // Leaves newline in buffer

        std::cout << "Enter title: ";
        // This std::getline will read the leftover newline from std::cin >> publication_year,
        // resulting in an empty string for title.
        std::getline(std::cin, books[i].title); 
        
        std::cout << "Enter author: ";
        // This std::getline will then read the user's intended title input.
        std::getline(std::cin, books[i].author);
    }

    std::cout << "\n--- Book Details ---\n";
    for (int i = 0; i < books.size(); ++i) {
        std::cout << "\nBook " << i + 1 << ":\n";
        std::cout << "Title: " << books[i].title << "\n";
        std::cout << "Author: " << books[i].author << "\n";
        std::cout << "Publication Year: " << books[i].publication_year << "\n";
    }

    return 0;
}