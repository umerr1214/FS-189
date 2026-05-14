#include <iostream>
#include <string>
#include <stdexcept> // For std::runtime_error

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    // Robustness Issue: operator== is a member function that is NOT const.
    // It also throws an exception for empty ISBNs, which is unexpected for an equality operator.
    bool operator==(Book& other) { // Should be 'const Book& other) const' for robustness
        if (this->isbn.empty() || other.isbn.empty()) {
            throw std::runtime_error("Robustness Issue: Cannot compare books with empty ISBNs!");
        }
        return this->isbn == other.isbn;
    }
};

int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    Book book2("1984", "George Orwell", "978-0451524935");
    Book book3("Brave New World", "Aldous Huxley", "978-0060850524");
    Book book4("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565"); // Same ISBN as book1
    Book book5("Another Book", "Another Author", "978-0743273565"); // Same ISBN as book1
    Book book6("Empty ISBN Book", "Someone", ""); // Book with empty ISBN

    std::cout << "Comparing books:" << std::endl;

    // Comparison 1: Different ISBNs
    try {
        if (book1 == book2) { // Compiles because book1 and book2 are not const
            std::cout << "book1 ('" << book1.isbn << "') == book2 ('" << book2.isbn << "'): True" << std::endl;
        } else {
            std::cout << "book1 ('" << book1.isbn << "') == book2 ('" << book2.isbn << "'): False" << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error during comparison: " << e.what() << std::endl;
    }

    // Comparison 2: Identical ISBNs
    try {
        if (book1 == book4) {
            std::cout << "book1 ('" << book1.isbn << "') == book4 ('" << book4.isbn << "'): True" << std::endl;
        } else {
            std::cout << "book1 ('" << book1.isbn << "') == book4 ('" << book4.isbn << "'): False" << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error during comparison: " << e.what() << std::endl;
    }

    // Comparison 3: Different titles, same ISBN
    try {
        if (book1 == book5) {
            std::cout << "book1 ('" << book1.isbn << "') == book5 ('" << book5.isbn << "'): True" << std::endl;
        } else {
            std::cout << "book1 ('" << book1.isbn << "') == book5 ('" << book5.isbn << "'): False" << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Error during comparison: " << e.what() << std::endl;
    }

    // Comparison 4: Triggering the robustness issue (empty ISBN)
    std::cout << "\nAttempting comparison with empty ISBN:" << std::endl;
    try {
        if (book1 == book6) { // This will throw an exception
            std::cout << "book1 ('" << book1.isbn << "') == book6 ('" << book6.isbn << "'): True" << std::endl;
        } else {
            std::cout << "book1 ('" << book1.isbn << "') == book6 ('" << book6.isbn << "'): False" << std::endl;
        }
    } catch (const std::runtime_error& e) {
        std::cout << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}