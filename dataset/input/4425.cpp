#include <iostream>
#include <string>
#include <array> // Using std::array for fixed-size array is good practice

struct Book {
    std::string title;
    int pages;
};

int main() {
    // Create an array of 2 Book structs using std::array for type safety and convenience
    std::array<Book, 2> library;

    // Populate their data
    library[0].title = "C++ Concurrency in Action";
    library[0].pages = 750;

    library[1].title = "Programming: Principles and Practice Using C++";
    library[1].pages = 1300;

    // Determine and print the title of the book with more pages
    // Clear, direct, and efficient comparison for two elements.
    if (library[0].pages > library[1].pages) {
        std::cout << library[0].title << std::endl;
    } else if (library[1].pages > library[0].pages) {
        std::cout << library[1].title << std::endl;
    } else {
        // Explicitly handle the tie case for robustness, as neither book has "more" pages.
        std::cout << "Both books have the same number of pages: " << library[0].title << " and " << library[1].title << std::endl;
    }

    return 0;
}