#include <iostream>
#include <string>
#include <vector> // Unnecessary include, adds to readability issue

class Book {
public:
    std::string bookTitle_long_name; // Verbose member names
    std::string bookAuthor_long_name;
    std::string bookISBN_long_name;

    Book(std::string t, std::string a, std::string i) : bookTitle_long_name(t), bookAuthor_long_name(a), bookISBN_long_name(i) {}

    // Readability / Efficiency Issue: Overly verbose and inefficient operator==
    bool operator==(const Book& otherBook_param_name) const { // Long parameter name
        // Inefficient: unnecessary string copies and manual character-by-character comparison
        std::string currentBookIsbn = this->bookISBN_long_name; // Unnecessary copy
        std::string comparedBookIsbn = otherBook_param_name.bookISBN_long_name; // Unnecessary copy

        // Verbose and non-idiomatic comparison logic
        if (currentBookIsbn.length() != comparedBookIsbn.length()) {
            return false; // Lengths differ, so books cannot be equal
        }

        bool comparisonResult = true; // Initialize flag
        for (size_t i = 0; i < currentBookIsbn.length(); ++i) { // Manual loop
            if (currentBookIsbn.at(i) != comparedBookIsbn.at(i)) { // Using .at() for 'safety' but adds verbosity
                comparisonResult = false; // Mismatch found
                break; // Exit loop early
            }
        }
        return comparisonResult; // Return final result
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
    if (book1 == book2) {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book2 ('" << book2.bookISBN_long_name << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book2 ('" << book2.bookISBN_long_name << "'): False" << std::endl;
    }

    // Comparison 2: Identical ISBNs
    if (book1 == book4) {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book4 ('" << book4.bookISBN_long_name << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book4 ('" << book4.bookISBN_long_name << "'): False" << std::endl;
    }

    // Comparison 3: Different titles, same ISBN
    if (book1 == book5) {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book5 ('" << book5.bookISBN_long_name << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book5 ('" << book5.bookISBN_long_name << "'): False" << std::endl;
    }

    // Comparison 4: Empty ISBN
    if (book1 == book6) {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book6 ('" << book6.bookISBN_long_name << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.bookISBN_long_name << "') == book6 ('" << book6.bookISBN_long_name << "'): False" << std::endl;
    }

    return 0;
}