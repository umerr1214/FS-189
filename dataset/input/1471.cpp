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
    // Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Getter methods
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    const std::string& getIsbn() const {
        return isbn;
    }

    // Method to display book information
    // Robustness Issue: Does not check std::cout's state before printing.
    // If the output stream is in a bad state (e.g., redirected to a closed pipe, disk full if writing to file),
    // these operations might fail silently or lead to undefined behavior without explicit checks (e.g., std::cout.good()).
    // Also, using std::endl on every line causes frequent flushing, which can impact performance in high-throughput scenarios.
    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
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