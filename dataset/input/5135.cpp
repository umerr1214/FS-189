#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // Required for std::numeric_limits

struct Book {
    std::string title;
    double price;
};

int main() {
    Book books[3];

    std::cout << "Enter details for 3 books:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Book " << i + 1 << " Title: ";
        if (i > 0) { 
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::getline(std::cin, books[i].title);
        
        std::cout << "Book " << i + 1 << " Price: ";
        std::cin >> books[i].price;
    }

    // Initialize with the first book
    double highestPrice = books[0].price;
    int highestBookIndex = 0; // LOGICAL ERROR: This index is initialized but never updated in the loop

    for (int i = 0; i < 3; ++i) {
        if (books[i].price > highestPrice) {
            highestPrice = books[i].price;
            // The line 'highestBookIndex = i;' is missing here,
            // which means highestBookIndex will always remain 0.
        }
    }

    // Even if highestPrice finds the correct maximum price,
    // highestBookIndex will incorrectly point to the first book (index 0).
    std::cout << "\nBook with the highest price:\n";
    std::cout << "Title: " << books[highestBookIndex].title << "\n"; // Will always print books[0]'s title
    std::cout << "Price: " << std::fixed << std::setprecision(2) << books[highestBookIndex].price << "\n"; // Will always print books[0]'s price

    return 0;
}