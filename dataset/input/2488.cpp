#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if

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

    // Needed for comparison in removeBook
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

    bool removeBook(const std::string& title) {
        // Use erase-remove idiom to remove all books with the given title
        auto old_size = books.size();
        books.erase(std::remove_if(books.begin(), books.end(),
                                   [&](const Book& b) { return b.title == title; }),
                    books.end());
        return books.size() < old_size; // Return true if any book was removed
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
} // SYNTAX ERROR: Missing semicolon after class definition
; // This semicolon should be part of `};`

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932));

    std::cout << "--- All Books ---" << std::endl;
    myLibrary.listAllBooks();
    std::cout << std::endl;

    std::cout << "--- Removing '1984' ---" << std::endl;
    if (myLibrary.removeBook("1984")) {
        std::cout << "Book '1984' removed." << std::endl;
    } else {
        std::cout << "Book '1984' not found." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Books after removal ---" << std::endl;
    myLibrary.listAllBooks();
    std::cout << std::endl;

    std::cout << "--- Attempting to remove non-existent book ---" << std::endl;
    if (myLibrary.removeBook("Moby Dick")) {
        std::cout << "Book 'Moby Dick' removed." << std::endl;
    } else {
        std::cout << "Book 'Moby Dick' not found." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Final Book List ---" << std::endl;
    myLibrary.listAllBooks();

    return 0;
}