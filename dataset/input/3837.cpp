#include <iostream> // Required for std::cout
#include <string>   // Required for std::string

// Define the Book struct as specified
struct Book {
    std::string title;
    std::string author;
    int yearPublished;
};

// Function to print book details, taking a Book struct by value
void printBookDetails(Book b) { // Takes by value as requested
    std::cout << "Book Details:\n";
    std::cout << "  Title: " << b.title << '\n';
    std::cout << "  Author: " << b.author << '\n';
    std::cout << "  Year Published: " << b.yearPublished << '\n';
}

int main() {
    // Create a Book instance
    Book myBook = {"The Ultimate C++ Guide", "Bjarne Stroustrup", 2020};

    // Call the function to print its details
    printBookDetails(myBook);

    return 0;
}