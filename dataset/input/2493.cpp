#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::find_if, std::remove_if
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

// Library class - Correct Version: Robust, efficient, and readable.
class Library {
private:
    std::vector<Book> books; // Aggregation

public:
    // Adds a book if its ISBN is not already present.
    // Returns true if the book was added, false if a book with the same ISBN already exists.
    bool addBook(const Book& book) {
        // Robustness: Checks for duplicate ISBN to ensure data integrity.
        // Efficiency: Uses `std::find_if` to check for existence.
        auto it = std::find_if(books.begin(), books.end(),
                               [&](const Book& existingBook) {
                                   return existingBook.getISBN() == book.getISBN();
                               });
        if (it == books.end()) {
            books.push_back(book);
            return true; // Book added successfully
        }
        return false; // Book with this ISBN already exists
    }

    // Removes all books with the given ISBN.
    // Returns true if at least one book was removed, false if no book with the ISBN was found.
    bool removeBook(const std::string& isbn) {
        // Efficiency & Readability: Uses the erase-remove idiom with `std::remove_if`
        // for efficient and clear removal of elements from a `std::vector`.
        auto old_size = books.size();
        books.erase(std::remove_if(books.begin(), books.end(),
                                   [&](const Book& book) {
                                       return book.getISBN() == isbn;
                                   }),
                    books.end());
        return books.size() < old_size; // True if any book was removed
    }

    // Lists all books in the library in a well-formatted string.
    std::string listAllBooks() const {
        // Efficiency & Readability: Uses `std::stringstream` for efficient and clear string building.
        // Leverages `Book::operator<<` for consistent and readable book formatting.
        std::stringstream ss;
        if (books.empty()) {
            ss << "Library is empty.";
        } else {
            ss << "Books in the library:\n";
            for (const auto& book : books) {
                ss << "- " << book << "\n"; // Uses Book's operator<< for readable output
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
    Book book3("Pride and Prejudice", "Jane Austen", "978-0-141-43951-8");

    ss_output << "--- Adding Books ---\n";
    bool added = myLibrary.addBook(book1);
    ss_output << "Added '" << book1.getTitle() << "': " << (added ? "Yes" : "No") << "\n";
    added = myLibrary.addBook(book2);
    ss_output << "Added '" << book2.getTitle() << "': " << (added ? "Yes" : "No") << "\n";
    added = myLibrary.addBook(book3);
    ss_output << "Added '" << book3.getTitle() << "': " << (added ? "Yes" : "No") << "\n";

    ss_output << "\n--- Attempting to Add a Duplicate Book ---\n";
    Book duplicateBook1("The Hobbit (2nd Copy)", "J.R.R. Tolkien", "978-0-345-33968-3");
    added = myLibrary.addBook(duplicateBook1); // Should fail
    ss_output << "Attempted to add duplicate '" << duplicateBook1.getTitle() << "': " << (added ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after adding and duplicate attempt) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Removing 'The Lord of the Rings' (ISBN 978-0-618-05326-7) ---\n";
    bool removed = myLibrary.removeBook("978-0-618-05326-7");
    ss_output << "Removed 'The Lord of the Rings': " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after removal) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Attempting to Remove a Non-Existent Book ---\n";
    removed = myLibrary.removeBook("978-999-999-999-9"); // Non-existent ISBN
    ss_output << "Removed non-existent book (ISBN 978-999-999-999-9): " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after failed removal) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Removing 'The Hobbit' ---\n";
    removed = myLibrary.removeBook("978-0-345-33968-3");
    ss_output << "Removed 'The Hobbit': " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (final) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    std::cout << ss_output.str();
    return 0;
}