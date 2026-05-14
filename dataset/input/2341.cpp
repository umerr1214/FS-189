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
    // Robustness Issue: No nullptr check. Allows adding nullptr to the collection.
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Robustness Issue: Dereferences bookPtr directly without checking if it's nullptr.
    // If a nullptr was added via addBook, this method will cause a crash or undefined behavior.
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "--- Library Collection ---" << std::endl;
        for (const auto& bookPtr : books) {
            bookPtr->display(); // Potential crash if bookPtr is nullptr
        }
        std::cout << "--------------------------" << std::endl;
    }
};

int main() {
    // Externally owned Book objects (on stack for simplicity)
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 1979);
    Book book2("Pride and Prejudice", "Jane Austen", 1813);
    Book book3("1984", "George Orwell", 1949);

    Library myLibrary;

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(nullptr); // Adding a nullptr intentionally to trigger the robustness issue
    myLibrary.addBook(&book3);

    myLibrary.displayAllBooks(); // This call is expected to crash or exhibit undefined behavior

    return 0;
}