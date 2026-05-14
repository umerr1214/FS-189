#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

int main() {
    Book library[3];

    // Prompt for input
    for (int i = 0; i < 3; ++i) {
        std::cout << "Enter details for Book " << i + 1 << ":\n";
        std::cout << "Title: ";
        // Logical Error: std::cin >> library[i].publicationYear leaves a newline in the buffer.
        // The subsequent std::getline for the next book's title will read this newline,
        // resulting in an empty title, and shifting subsequent inputs.
        std::getline(std::cin, library[i].title);
        std::cout << "Author: ";
        std::getline(std::cin, library[i].author);
        std::cout << "Publication Year: ";
        std::cin >> library[i].publicationYear;
        // Missing std::cin.ignore() or std::ws here to clear the buffer.
    }

    // Print details
    std::cout << "\n--- Book Details ---\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Book " << i + 1 << ":\n";
        std::cout << "  Title: " << library[i].title << "\n";
        std::cout << "  Author: " << library[i].author << "\n";
        std::cout << "  Publication Year: " << library[i].publicationYear << "\n";
    }

    return 0;
}