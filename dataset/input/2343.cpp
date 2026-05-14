#include <iostream>
#include <vector>
#include <string>
#include <utility> // For std::move

// Book class (from Q1, simplified for this context)
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
};

class Library {
private:
    std::vector<Book*> books; // Stores pointers to externally owned Book objects

public:
    // Adds a book pointer to the collection. Robustly checks for nullptr.
    void addBook(Book* book) {
        if (book != nullptr) {
            books.push_back(book);
        } else {
            std::cerr << "Error: Attempted to add a nullptr Book to the library (ignored)." << std::endl;
        }
    }

    // Displays all book details. Correct, readable, and efficient.
    // Uses range-based for loop and checks for nullptr before dereferencing (defensive programming).
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Collection ---" << std::endl;
        for (const Book* bookPtr : books) { // Modern range-based for loop, const correctness
            if (bookPtr != nullptr) { // Defensive check, though addBook should prevent this
                bookPtr->display();
            } else {
                std::cout << "[Invalid or Null Book Pointer encountered in collection]" << std::endl;
            }
        }
        std::cout << "--------------------------" << std::endl;
    }
};

int main() {
    // Externally owned Book objects (on stack for simplicity)
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", 1954);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3("The Great Gatsby", "F. Scott Fitzgerald", 1925);

    Library myLibrary;

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(nullptr); // Attempt to add nullptr, which should be handled gracefully (ignored with error message to cerr)
    myLibrary.addBook(&book3);

    myLibrary.displayAllBooks();
    std::cout << std::endl;

    // Test with an empty library
    Library emptyLibrary;
    emptyLibrary.displayAllBooks();

    return 0;
}