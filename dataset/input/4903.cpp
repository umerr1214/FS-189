#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

int main() {
    Book books[3]; // Declare an array of three Book structs

    std::cout << "Enter details for three books:\n";

    for (int i = 0; i < 3; ++i) {
        std::cout << "\n--- Book " << i + 1 << " ---\n";

        // Robustness Issue 1: The `std::cin >> books[i].publicationYear;` will leave a newline character
        // in the input buffer. For the *next* iteration (i.e., for book i+1),
        // the subsequent `std::getline` for `books[i+1].title` will immediately read this leftover newline,
        // resulting in an empty string for the title.

        // For the first book (i=0), the first `getline` for title will work as expected
        // if no previous `cin >> int` was used.
        std::cout << "Enter title for book " << i + 1 << ": ";
        std::getline(std::cin, books[i].title);

        std::cout << "Enter author for book " << i + 1 << ": ";
        std::getline(std::cin, books[i].author);

        std::cout << "Enter publication year for book " << i + 1 << ": ";
        std::cin >> books[i].publicationYear;
        // Robustness Issue 2: No error checking for `std::cin.fail()` after reading year.
        // If non-numeric input is provided, `std::cin` enters a fail state, and subsequent
        // input operations (even `getline` for the next book) will fail or misbehave,
        // leading to unexpected program behavior or incorrect data.
    }

    std::cout << "\n--- Details of all books ---\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "\nBook " << i + 1 << ":\n";
        std::cout << "Title: " << books[i].title << "\n";
        std::cout << "Author: " << books[i].author << "\n";
        std::cout << "Publication Year: " << books[i].publicationYear << "\n";
    }

    return 0;
}