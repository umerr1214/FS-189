#include <iostream>
#include <vector>
#include <string>

// Book class (simplified from Q1)
class Book {
private:
    std::string title;
    std::string author;
public:
    Book(std::string t, std::string a) : title(t), author(a) {
        // std::cout << "Book '" << title << "' created." << std::endl;
    }
    ~Book() {
        // std::cout << "Book '" << title << "' destroyed." << std::endl;
    }
    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
    std::string getTitle() const { return title; }
};

class Library {
private:
    std::vector<Book*> books; // Aggregation
public:
    Library() = default;

    // SEMANTIC ERROR: Library attempts to delete externally owned Book objects
    ~Library() {
        std::cout << "Library destructor called. Attempting to free books..." << std::endl;
        for (Book* book : books) {
            // This delete is incorrect as the Library does not own the Book objects.
            // These books are created on the stack in main, leading to a double-free
            // or deleting memory it doesn't own, causing undefined behavior.
            delete book;
        }
        books.clear(); // Clear pointers after (incorrect) deletion
        std::cout << "Library destructor finished." << std::endl;
    }

    void addBook(Book* book) {
        if (book) {
            books.push_back(book);
        }
    }
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "Books in Library:" << std::endl;
        for (const auto& book : books) {
            book->display();
        }
    }
};

int main() {
    // Books created on the stack (externally owned)
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2("1984", "George Orwell");

    { // Scope to demonstrate Library destruction
        Library myLibrary;
        myLibrary.addBook(&book1);
        myLibrary.addBook(&book2);
        myLibrary.displayAllBooks();
    } // myLibrary goes out of scope, its destructor is called, leading to UB

    std::cout << "Main function ending." << std::endl;
    // book1 and book2 will be destroyed here as they go out of scope in main.
    // If Library's destructor deleted them, this will be a double-free.
    return 0;
}