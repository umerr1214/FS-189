#include <iostream>
#include <string>
#include <array>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // Required for std::fixed, std::setprecision

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
        // Clear any leftover newline characters from previous numeric input
        // and read the full title including spaces.
        std::getline(std::cin >> std::ws, books[i].title); 

        std::cout << "Book " << i + 1 << " Price: ";
        while (!(std::cin >> books[i].price)) {
            std::cout << "Invalid input. Please enter a numeric price: ";
            std::cin.clear(); // Clear the error flags
            // Ignore remaining characters in the input buffer up to the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // After successfully reading price, ignore the rest of the line (including newline)
        // to prevent it from being consumed by the next getline.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (NUM_BOOKS == 0) {
        std::cout << "No books to compare.\n";
        return 0;
    }

    // Initialize with the first book as the highest
    Book highestPriceBook = books[0]; 
    for (int i = 1; i < NUM_BOOKS; ++i) {
        if (books[i].price > highestPriceBook.price) {
            highestPriceBook = books[i];
        }
    }

    std::cout << "\nBook with the highest price:\n";
    std::cout << "Title: " << highestPriceBook.title << "\n";
    // Format price to two decimal places
    std::cout << "Price: " << std::fixed << std::setprecision(2) << highestPriceBook.price << "\n";

    return 0;
}