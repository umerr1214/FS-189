#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if (not used in buggy removeBook)

class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(std::string title, std::string author, int year)
        : title(std::move(title)), author(std::move(author)), year(year) {}

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }

    bool operator==(const Book& other) const {
        return title == other.title && author == other.author && year == other.year;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // LOGICAL ERROR: This removeBook only removes the FIRST book found
    // with the given title, then stops. If there are duplicates,
    // subsequent duplicates will remain in the library.
    // The common expectation for "remove by title" is to remove all matching entries.
    bool removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                return true; // Logical error: returns after removing only the first match
            }
        }
        return false;
    }

    void listAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932));
    myLibrary.addBook(Book("1984", "George Orwell", 1949)); // Adding a duplicate for testing logical error

    std::cout << "--- All Books (including duplicate) ---" << std::endl;
    myLibrary.listAllBooks();
    std::cout << std::endl;

    std::cout << "--- Removing '1984' ---" << std::endl;
    // This call will only remove the first '1984' book due to the logical error.
    if (myLibrary.removeBook("1984")) {
        std::cout << "Book '1984' removed (or at least one instance)." << std::endl;
    } else {
        std::cout << "Book '1984' not found." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Books after removal attempt ---" << std::endl;
    myLibrary.listAllBooks();
    std::cout << std::endl;

    std::cout << "--- Attempting to remove the remaining '1984' ---" << std::endl;
    if (myLibrary.removeBook("1984")) {
        std::cout << "Book '1984' removed (second instance)." << std::endl;
    } else {
        std::cout << "Book '1984' not found." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Final Book List ---" << std::endl;
    myLibrary.listAllBooks();

    return 0;
}