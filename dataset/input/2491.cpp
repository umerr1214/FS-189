#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if
#include <sstream>   // For std::stringstream
#include <utility>   // For std::move

// Book class (from previous question context)
class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)) {}

    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getISBN() const { return isbn; }

    // For comparison (e.g., in removeBook or finding duplicates)
    bool operator==(const Book& other) const {
        return this->isbn == other.isbn;
    }

    // For easy printing
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "\"" << book.title << "\" by " << book.author << " (ISBN: " << book.isbn << ")";
        return os;
    }
};

// Library class with robustness issues: allows duplicate ISBNs, removeBook only removes first occurrence.
class Library {
private:
    std::vector<Book> books; // Aggregation

public:
    void addBook(const Book& book) {
        // Robustness issue: Allows adding books with duplicate ISBNs.
        // A robust library system would typically check for duplicates and prevent them,
        // or manage multiple copies explicitly, to maintain data integrity and consistency.
        books.push_back(book);
    }

    bool removeBook(const std::string& isbn) {
        // Robustness issue: Only removes the first book found with the given ISBN.
        // If multiple copies exist due to addBook's behavior, only one is removed,
        // which might not be the desired behavior.
        // Also, it doesn't provide specific feedback when a book is not found
        // beyond a boolean return, which could be improved for user experience.
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getISBN() == isbn) {
                books.erase(it);
                return true; // Book found and removed
            }
        }
        return false; // Book not found
    }

    std::string listAllBooks() const {
        std::stringstream ss;
        if (books.empty()) {
            ss << "Library is empty.";
        } else {
            ss << "Books in the library:\n";
            for (const auto& book : books) {
                ss << "- " << book << "\n";
            }
        }
        return ss.str();
    }
};

int main() {
    Library myLibrary;
    std::stringstream ss_output;

    Book book1("The Hobbit", "J.R.R. Tolkien", "978-0-345-33968-3");
    Book book2("The Lord of the Rings", "J.R.R. Tolkien", "978-0-618-05326-7");
    
    ss_output << "--- Adding Books ---\n";
    myLibrary.addBook(book1); // Add first copy of Hobbit
    ss_output << "Added: " << book1.getTitle() << "\n";
    myLibrary.addBook(book2);
    ss_output << "Added: " << book2.getTitle() << "\n";
    myLibrary.addBook(book1); // Add second copy of Hobbit (duplicate ISBN allowed by this implementation)
    ss_output << "Added: " << book1.getTitle() << " (duplicate ISBN allowed)\n";

    ss_output << "\n--- Listing All Books (after adding duplicates) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Removing a Book (one of two Hobbits) ---\n";
    bool removed = myLibrary.removeBook("978-0-345-33968-3"); // Remove one Hobbit
    ss_output << "Removed 'The Hobbit' (ISBN 978-0-345-33968-3): " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after removing one Hobbit) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Attempting to remove a non-existent Book ---\n";
    removed = myLibrary.removeBook("978-999-999-999-9"); // Non-existent ISBN
    ss_output << "Removed non-existent book (ISBN 978-999-999-999-9): " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after failed removal) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    std::cout << ss_output.str();
    return 0;
}