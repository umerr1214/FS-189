#include <iostream>
#include <vector>
#include <string>
#include <sstream> // For stringstream for less efficient output formatting
#include <utility> // For std::move

// Book class (from Q1, simplified for this context)
class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(std::string title, std::string author, int year)
        : title(std::move(title)), author(std::move(author)), year(year) {}

    // Method to get a formatted string, for less efficient output (sstream per call)
    std::string getBookInfo() const {
        std::stringstream ss;
        ss << "Book Title: \"" << title << "\", Author Name: \"" << author << "\", Publication Year: " << year << ".";
        return ss.str();
    }
};

class Library {
private:
    std::vector<Book*> books; // Stores pointers to externally owned Book objects

public:
    // Adds a book pointer. Includes a basic nullptr check for safety, but the main issue
    // is in displayAllBooks.
    void addBook(Book* book) {
        if (book != nullptr) {
            books.push_back(book);
        } else {
            std::cerr << "Warning: Attempted to add a null book pointer (ignored)." << std::endl;
        }
    }

    // Readability / Efficiency Issues:
    // 1. Uses an old-style index-based loop instead of a more modern and readable range-based for loop.
    // 2. Relies on `Book::getBookInfo()` which uses `stringstream` for each book, potentially less efficient
    //    than direct stream insertion and adds an unnecessary string copy.
    // 3. Output formatting is slightly more verbose than necessary, impacting readability.
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is currently empty." << std::endl;
            return;
        }

        std::cout << "--- Current Books in Library (Inefficient Display) ---" << std::endl;
        for (size_t i = 0; i < books.size(); ++i) { // Old-style loop
            if (books[i] != nullptr) {
                std::cout << "Entry " << (i + 1) << ": " << books[i]->getBookInfo() << std::endl; // Less efficient string formatting
            } else {
                // This branch should ideally not be hit if addBook filters nullptr,
                // but included for robustness if state is corrupted.
                std::cout << "Entry " << (i + 1) << ": [Invalid Book Pointer in collection]" << std::endl;
            }
        }
        std::cout << "--- End of Inefficient Display ---" << std::endl;
    }
};

int main() {
    Book bookA("Dune", "Frank Herbert", 1965);
    Book bookB("Foundation", "Isaac Asimov", 1951);
    Book bookC("Neuromancer", "William Gibson", 1984);

    Library sciFiLibrary;

    sciFiLibrary.addBook(&bookA);
    sciFiLibrary.addBook(&bookB);
    // sciFiLibrary.addBook(nullptr); // Not adding nullptr to keep stdout clean for expected output
    sciFiLibrary.addBook(&bookC);

    sciFiLibrary.displayAllBooks();
    std::cout << std::endl; // Add a newline for separation

    // Test empty library case
    Library emptyLibrary;
    emptyLibrary.displayAllBooks();

    return 0;
}