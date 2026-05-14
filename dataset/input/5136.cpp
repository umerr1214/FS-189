#include <iostream>
#include <string>
#include <iomanip>
// #include <limits> // Not included, which makes fixing the semantic error harder if cin.ignore() was intended

struct Book {
    std::string title;
    double price;
};

int main() {
    Book books[3];

    std::cout << "Enter details for 3 books:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Book " << i + 1 << " Title: ";
        // SEMANTIC ERROR: After std::cin >> books[i-1].price, a newline character is left in the buffer.
        // For i=0, getline works fine.
        // For i=1 and i=2, this std::getline will immediately read the leftover newline from the previous
        // std::cin >> price, resulting in an empty title for books[1] and books[2].
        // This also means the subsequent std::cin >> books[i].price will try to read the user's intended title
        // as a double, leading to input stream errors if the title is not a number.
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