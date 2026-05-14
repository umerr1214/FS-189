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

// Library class with readability/efficiency issues: inefficient removeBook, inefficient string building.
class Library {
private:
    std::vector<Book> books; // Aggregation

public:
    void addBook(const Book& book) {
        // Allowing duplicates here to keep focus on efficiency/readability issues in other methods.
        books.push_back(book);
    }

    bool removeBook(const std::string& isbn) {
        // Efficiency issue: Using a manual loop with `std::vector::erase` inside.
        // Each `erase` operation on a `std::vector` can be O(N) because elements after the erased one
        // need to be shifted. Doing this repeatedly in a loop (especially if multiple matches are found)
        // leads to an O(N^2) worst-case complexity for the entire `removeBook` operation.
        // A more efficient and idiomatic C++ approach is to use `std::remove_if` followed by `vector::erase`.
        bool removed = false;
        for (auto it = books.begin(); it != books.end(); /* no increment here */) {
            if (it->getISBN() == isbn) {
                it = books.erase(it); // erase returns iterator to the next element
                removed = true;
            } else {
                ++it;
            }
        }
        return removed; // Returns true if at least one book was removed
    }

    std::string listAllBooks() const {
        // Efficiency issue: String concatenation using the `+` operator repeatedly in a loop.
        // For many concatenations, this can lead to frequent memory reallocations and data copying,
        // making it less efficient than using `std::stringstream` or pre-allocating string capacity.
        // Also, the formatting is manually constructed, which can be less readable than using
        // stream operators with `Book::operator<<`.
        std::string result = "";
        if (books.empty()) {
            result += "Library is empty.";
        } else {
            result += "Books in the library:\n";
            for (const auto& book : books) {
                result += "  - ";
                result += book.getTitle();
                result += ", ";
                result += book.getAuthor();
                result += " (ISBN: ";
                result += book.getISBN();
                result += ")\n";
            }
        }
        return result;
    }
};

int main() {
    Library myLibrary;
    std::stringstream ss_output; // Capture output for test cases

    Book book1("The Hobbit", "J.R.R. Tolkien", "978-0-345-33968-3");
    Book book2("The Lord of the Rings", "J.R.R. Tolkien", "978-0-618-05326-7");
    Book book3("Pride and Prejudice", "Jane Austen", "978-0-141-43951-8");
    Book book4("1984", "George Orwell", "978-0-451-52493-5");
    Book book5("Brave New World", "Aldous Huxley", "978-0-060-85052-0");

    ss_output << "--- Adding Books ---\n";
    myLibrary.addBook(book1); ss_output << "Added: " << book1.getTitle() << "\n";
    myLibrary.addBook(book2); ss_output << "Added: " << book2.getTitle() << "\n";
    myLibrary.addBook(book3); ss_output << "Added: " << book3.getTitle() << "\n";
    myLibrary.addBook(book4); ss_output << "Added: " << book4.getTitle() << "\n";
    myLibrary.addBook(book5); ss_output << "Added: " << book5.getTitle() << "\n";
    myLibrary.addBook(book1); // Add duplicate for removal test
    ss_output << "Added: " << book1.getTitle() << " (duplicate ISBN allowed)\n";


    ss_output << "\n--- Listing All Books (initial) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Removing 'The Lord of the Rings' (ISBN 978-0-618-05326-7) ---\n";
    bool removed = myLibrary.removeBook("978-0-618-05326-7");
    ss_output << "Removed: " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after first removal) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Removing 'The Hobbit' (ISBN 978-0-345-33968-3, multiple copies) ---\n";
    removed = myLibrary.removeBook("978-0-345-33968-3"); // Should remove both copies due to loop
    ss_output << "Removed: " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (after second removal) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    ss_output << "\n--- Attempting to remove a non-existent Book ---\n";
    removed = myLibrary.removeBook("978-999-999-999-9");
    ss_output << "Removed non-existent: " << (removed ? "Yes" : "No") << "\n";

    ss_output << "\n--- Listing All Books (final) ---\n";
    ss_output << myLibrary.listAllBooks() << "\n";

    std::cout << ss_output.str();
    return 0;
}