#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // Required for std::numeric_limits

struct Book {
    std::string title;
    double price;
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Book books[3];

    std::cout << "Enter details for 3 books:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Book " << i + 1 << " Title: ";
        // After reading price for book i-1, a newline is left.
        // This ignore handles it before reading the next title.
        if (i > 0) { 
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::getline(std::cin, books[i].title);
        
        std::cout << "Book " << i + 1 << " Price: ";
        std::cin >> books[i].price;
    }

    double highestPrice = -1.0; 
    int highestBookIndex = -1;

    for (int i = 0; i < 3; ++i) {
        if (books[i].price > highestPrice) {
            highestPrice = books[i].price;
            highestBookIndex = i;
        }
    }

    if (highestBookIndex != -1) {
        std::cout << "\nBook with the highest price:\n";
        std::cout << "Title: " << books[highestBookIndex].title << "\n";
        std::cout << "Price: " << std::fixed << std::setprecision(2) << books[highestBookIndex].price << "\n";
    } else {
        std::cout << "\nNo books entered or prices are invalid.\n";
    }

    return 0;
}