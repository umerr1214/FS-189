#include <iostream>
#include <string>
#include <vector> // Required for complete C++ program structure, even if not directly used by Book class
#include <sstream> // Required for complete C++ program structure, even if not directly used by Book class

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor to initialize all private data members
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Public getter methods, returning const references for efficiency and marked const
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    const std::string& getIsbn() const {
        return isbn;
    }

    // Method to display all book details, marked const as it doesn't modify the object
    // Uses '\n' for newlines and flushes only once at the end for efficiency.
    void displayBookInfo() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << isbn << std::endl; // std::endl flushes at the end
    }
};

int main() {
    // Test Case 1
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << "--- Book 1 ---" << std::endl;
    book1.displayBookInfo();
    std::cout << "--- End Book 1 ---" << std::endl;

    // Test Case 2
    Book book2("1984", "George Orwell", "978-0451524935");
    std::cout << "--- Book 2 ---" << std::endl;
    book2.displayBookInfo();
    std::cout << "--- End Book 2 ---" << std::endl;

    // Test Case 3 (empty fields)
    Book book3("", "Unknown Author", "");
    std::cout << "--- Book 3 ---" << std::endl;
    book3.displayBookInfo();
    std::cout << "--- End Book 3 ---" << std::endl;

    return 0;
}