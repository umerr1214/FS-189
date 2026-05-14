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
    Book(std::string initialTitle, std::string initialAuthor, std::string initialIsbn)
        : title(std::move(initialTitle)), author(std::move(initialAuthor)), isbn(std::move(initialIsbn)) {}

    // Accessor methods (getters)
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    // Setter for title - Readability/Efficiency Issue: passes by value, uses length() == 0, verbose message
    void setTitle(std::string newTitleValue) { // Passes by value, causes an unnecessary copy
        if (newTitleValue.length() == 0) { // Uses length() == 0 instead of the more idiomatic empty()
            std::cout << "Attention: The provided title string was found to be completely empty. Therefore, the book's title will not be modified from its current value. Please provide a non-empty title.\n";
            // Do not update, which is correct behavior, but the messaging and parameter passing are suboptimal.
        } else {
            this->title = newTitleValue; // Assignment causes another copy
        }
    }

    // Setter for author - Readability/Efficiency Issue: passes by value
    void setAuthor(std::string newAuthorValue) { // Passes by value, causes an unnecessary copy
        author = newAuthorValue; // Assignment causes another copy
    }

    // Setter for ISBN - Readability/Efficiency Issue: passes by value
    void setIsbn(std::string newIsbnValue) { // Passes by value, causes an unnecessary copy
        isbn = newIsbnValue; // Assignment causes another copy
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
    Book myBook("Learning C++", "Bjarne Stroustrup", "0-201-0345-X");
    printBookDetails(myBook, "Initial Book State:");

    myBook.setAuthor("B. Stroustrup");
    printBookDetails(myBook, "After updating author:");

    myBook.setIsbn("978-0321992789");
    printBookDetails(myBook, "After updating ISBN:");

    std::cout << "Attempting to set title to an empty string (expecting no change and verbose message)...\n";
    myBook.setTitle(""); // Should trigger the error message and not update
    printBookDetails(myBook, "After attempting to set empty title (should be unchanged):");

    myBook.setTitle("Effective Modern C++");
    printBookDetails(myBook, "After setting a new valid title:");

    return 0;
}