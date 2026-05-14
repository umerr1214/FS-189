#include <iostream>
#include <string>
#include <utility> // For std::move

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor uses std::move for efficient string initialization
    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)) {}

    // Getters provide read-only access to private members
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    // Setter for title with validation - Robustness Issue: updates title even if empty
    void setTitle(std::string newTitle) { // Passes by value, could be const reference for efficiency
        if (newTitle.empty()) {
            std::cerr << "Error: Title cannot be an empty string. Attempted to set to: '" << newTitle << "'\n";
            // ROBUSTNESS ISSUE: Despite the error message, the title is still updated to the empty string.
            this->title = newTitle; // This line is the bug, it should be skipped.
        } else {
            this->title = newTitle; // Correct update for non-empty title
        }
    }

    // Setter for author
    void setAuthor(std::string newAuthor) { // Passes by value, could be const reference
        this->author = newAuthor;
    }

    // Setter for ISBN
    void setIsbn(std::string newIsbn) { // Passes by value, could be const reference
        this->isbn = newIsbn;
    }
};

// Helper function for printing book details
void printBookDetails(const Book& book, const std::string& message) {
    std::cout << message << "\n";
    std::cout << "  Title: " << book.getTitle() << "\n";
    std::cout << "  Author: " << book.getAuthor() << "\n";
    std::cout << "  ISBN: " << book.getIsbn() << "\n";
    std::cout << "--------------------------------\n";
}

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    printBookDetails(myBook, "Initial Book Details:");

    myBook.setAuthor("Douglas N. Adams");
    printBookDetails(myBook, "After setting author:");

    myBook.setIsbn("978-0345391804");
    printBookDetails(myBook, "After setting ISBN:");

    std::cout << "Attempting to set title to an empty string...\n";
    myBook.setTitle(""); // This should print an error and *not* change the title, but it will due to the bug.
    printBookDetails(myBook, "After attempting to set empty title (Robustness Issue: Title *was* updated):");

    myBook.setTitle("The Restaurant at the End of the Universe");
    printBookDetails(myBook, "After setting a valid title:");

    return 0;
}