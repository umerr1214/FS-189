#include <iostream>
#include <string>
#include <array>
#include <limits> // Required for numeric_limits

struct Book {
    std::string title;
    double price;
};

int main() {
    std::array<Book, 3> books;
    const int NUM_BOOKS = 3;

    std::cout << "Enter details for " << NUM_BOOKS << " books:\n";

    for (int i = 0; i < NUM_BOOKS; ++i) {
        std::cout << "Book " << i + 1 << " Title: ";
        std::getline(std::cin >> std::ws, books[i].title); // Clear whitespace before reading string

        std::cout << "Book " << i + 1 << " Price: ";
        std::cin >> books[i].price;
        // Robustness Issue: No input validation for price.
        // If non-numeric input is given, cin will enter a fail state,
        // subsequent reads will fail, and getline might read empty strings or be skipped.
        // This can lead to incorrect data or an infinite loop if not handled.
    }

    if (NUM_BOOKS == 0) {
        std::cout << "No books to compare.\n";
        return 0;
    }

    Book highestPriceBook = books[0];
    for (int i = 1; i < NUM_BOOKS; ++i) {
        if (books[i].price > highestPriceBook.price) {
            highestPriceBook = books[i];
        }
    }

    std::cout << "\nBook with the highest price:\n";
    std::cout << "Title: " << highestPriceBook.title << "\n";
    std::cout << "Price: " << highestPriceBook.price << "\n";

    return 0;
}