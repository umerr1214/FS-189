#include <iostream>
#include <string>
#include <array> // Preferred for fixed-size arrays in modern C++

struct Book {
    std::string title;
    std::string author;
    int publication_year;
};

int main() {
    std::array<Book, 3> books; // Use std::array for a fixed-size collection

    std::cout << "Enter details for three books:\n"; // Use '\n' for efficiency
    for (int i = 0; i < books.size(); ++i) {
        std::cout << "\nBook " << i + 1 << ":\n";
        
        std::cout << "Enter title: ";
        // Use std::ws manipulator to skip any leading whitespace (including newlines)
        // before reading the title with std::getline, ensuring robust input handling.
        std::getline(std::cin >> std::ws, books[i].title);
        
        std::cout << "Enter author: ";
        std::getline(std::cin, books[i].author); // No prior std::cin >> int, so this is fine
        
        std::cout << "Enter publication year: ";
        std::cin >> books[i].publication_year; // Leaves newline, handled by std::ws in next iteration
    }

    std::cout << "\n--- Book Details ---\n";
    for (int i = 0; i < books.size(); ++i) { // Use index for "Book X" output
        std::cout << "\nBook " << i + 1 << ":\n";
        std::cout << "Title: " << books[i].title << "\n";
        std::cout << "Author: " << books[i].author << "\n";
        std::cout << "Publication Year: " << books[i].publication_year << "\n";
    }

    return 0;
}