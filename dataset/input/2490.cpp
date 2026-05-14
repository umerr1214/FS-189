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
        : title(std::move(title)), author(std::move(author)), year(year) {
        // std::cout << "Book '" << this->title << "' constructed at " << this << std::endl;
    }

    ~Book() {
        // std::cout << "Book '" << this->title << "' destructed from " << this << std::endl;
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }

    bool operator==(const Book& other) const {
        return title == other.title && author == other.author && year == other.year;
    }
};

class Library {
private:
    // SEMANTIC ERROR: Aggregating raw pointers without proper memory management.
    // The Library class stores pointers to Book objects, but does not own them (i.e., it doesn't
    // allocate them with 'new' nor deallocate them with 'delete').
    // This leads to dangling pointers when `addBook` is used with temporary Book objects.
    std::vector<Book*> books;

public:
    // SEMANTIC ERROR: `book` is a const reference to a temporary or stack-allocated object.
    // Storing its address (`&book`) leads to a dangling pointer once the temporary
    // object (created in `main` for `addBook`) is destroyed at the end of the full expression.
    void addBook(const Book& book) {
        books.push_back(&book); // Storing address of a temporary object which will soon be destroyed
    }

    // This method attempts to operate on potentially dangling pointers.
    bool removeBook(const std::string& title) {
        auto old_size = books.size();
        books.erase(std::remove_if(books.begin(), books.end(),
                                 [&](Book* b) {
                                     if (b) return b->title == title; // Dereferencing potentially dangling pointer
                                     return false;
                                 }),
                    books.end());
        return books.size() < old_size;
    }

    void listAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        for (const auto& bookPtr : books) {
            if (bookPtr) { // Check for nullptr (though not the main issue here)
                // SEMANTIC ERROR: Dereferencing potentially dangling pointers.
                // The memory pointed to by bookPtr might have been deallocated or reused.
                bookPtr->display();
            } else {
                std::cout << "Invalid (nullptr) book pointer found." << std::endl;
            }
        }
    }

    // SEMANTIC ERROR: No destructor to handle memory. If Library were intended to own
    // the books (e.g., if addBook used `new`), this would be a memory leak.
    // In this specific case, since `addBook` creates dangling pointers,
    // adding a `delete bookPtr;` here would lead to use-after-free or double-free.
    // The core semantic error is in the aggregation strategy (`std::vector<Book*>`)
    // combined with `addBook`'s implementation.
    ~Library() {
        // Correct implementation for `std::vector<Book*>` where Library *owns* the books:
        // for (Book* bookPtr : books) {
        //     delete bookPtr;
        // }
        // books.clear();
        // But doing this with the current `addBook` would be incorrect/dangerous.
    }
};

int main() {
    Library myLibrary;

    // These Book objects are temporaries. Their addresses are stored in myLibrary.
    // They are destroyed immediately after these statements.
    myLibrary.addBook(Book("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("Brave New World", "Aldous Huxley", 1932));

    std::cout << "--- All Books (expect undefined behavior/crash/garbage) ---" << std::endl;
    // Accessing dangling pointers here
    myLibrary.listAllBooks();
    std::cout << std::endl;

    std::cout << "--- Removing '1984' (might crash or not work as expected) ---" << std::endl;
    if (myLibrary.removeBook("1984")) {
        std::cout << "Book '1984' removed (from list of dangling pointers)." << std::endl;
    } else {
        std::cout << "Book '1984' not found (among dangling pointers)." << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Books after removal ---" << std::endl;
    myLibrary.listAllBooks();
    std::cout << std::endl;

    return 0;
}