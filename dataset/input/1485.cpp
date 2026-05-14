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

    // Setter for title with validation
    void setTitle(const std::string& newTitle) { // Pass by const reference for efficiency
        if (newTitle.empty()) { // Use empty() for clear and idiomatic check
            std::cerr << "Error: Title cannot be set to an empty string. Title remains: '" << this->title << "'\n";
            // Do not update, as per requirement
        } else {
            this->title = newTitle; // Update title
        }
    }

    // Setter for author
    void setAuthor(const std::string& newAuthor) { // Pass by const reference for efficiency
        this->author = newAuthor;
    }

    // Setter for ISBN
    void setIsbn(const std::string& newIsbn) { // Pass by const reference for efficiency
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
    Book myBook("Effective C++", "Scott Meyers", "0-321-33487-6");
    printBookDetails(myBook, "Initial Book State:");

    myBook.setAuthor("Scott W. Meyers");
    printBookDetails(myBook, "After updating author:");

    myBook.setIsbn("978-0321334879");
    printBookDetails(myBook, "After updating ISBN:");

    std::cout << "Attempting to set title to an empty string (expecting error and no change)...\n";
    myBook.setTitle(""); // Should trigger error and not update the title
    printBookDetails(myBook, "After attempting to set empty title (should be unchanged):");

    myBook.setTitle("More Effective C++");
    printBookDetails(myBook, "After setting a new valid title:");

    return 0;
}