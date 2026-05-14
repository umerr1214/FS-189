#include <iostream>
#include <string>
#include <limits> // Not strictly needed for this robust-issue, but good to include if year validation was more complex

struct Book {
    std::string title;
    std::string author;
    int yearPublished;
};

// Function to print book details, demonstrating a robustness issue
// It handles empty strings for title/author but not potentially invalid yearPublished values (like 0 or negative)
void printBookDetails(Book b) { // Takes by value as requested
    std::cout << "Book Details:\n";
    if (b.title.empty()) {
        std::cout << "Title: N/A\n";
    } else {
        std::cout << "Title: " << b.title << '\n';
    }

    if (b.author.empty()) {
        std::cout << "Author: N/A\n";
    } else {
        std::cout << "Author: " << b.author << '\n';
    }

    // Robustness Issue: Prints yearPublished directly, even if it's 0 or negative,
    // without any special handling or indication that it might be an invalid/unknown year.
    // This is inconsistent with the handling of empty strings for title/author.
    std::cout << "Year Published: " << b.yearPublished << '\n';
}

int main() {
    // Demonstrate with various Book instances to highlight the robustness issue
    Book book1 = {"The Great C++ Book", "", 2023}; // Empty author
    std::cout << "--- Book 1 ---\n";
    printBookDetails(book1);
    std::cout << "\n";

    Book book2 = {"", "Jane Doe", 0}; // Empty title, year 0
    std::cout << "--- Book 2 ---\n";
    printBookDetails(book2);
    std::cout << "\n";

    Book book3 = {"Another Book", "John Smith", -100}; // Negative year
    std::cout << "--- Book 3 ---\n";
    printBookDetails(book3);
    std::cout << "\n";
    
    Book book4 = {"Valid Title", "Valid Author", 1999}; // All valid
    std::cout << "--- Book 4 ---\n";
    printBookDetails(book4);

    return 0;
}