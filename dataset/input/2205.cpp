#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    // Declare the non-member operator== as a friend function to allow direct access to private members
    // if ISBN were private. Here, it's public, so friend is not strictly necessary but good practice
    // for symmetric operators.
    friend bool operator==(const Book& b1, const Book& b2);
};

// Correct, efficient, and readable overload of == operator
// Implemented as a non-member function for symmetry and good practice
bool operator==(const Book& b1, const Book& b2) {
    // Efficiently compares ISBNs directly using std::string::operator==
    // Uses const references to avoid unnecessary copies and ensure const-correctness.
    return b1.isbn == b2.isbn;
}

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
        std::cout << "book1 ('" << book1.isbn << "') == book2 ('" << book2.isbn << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.isbn << "') == book2 ('" << book2.isbn << "'): False" << std::endl;
    }

    // Comparison 2: Identical ISBNs
    if (book1 == book4) {
        std::cout << "book1 ('" << book1.isbn << "') == book4 ('" << book4.isbn << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.isbn << "') == book4 ('" << book4.isbn << "'): False" << std::endl;
    }

    // Comparison 3: Different titles, same ISBN
    if (book1 == book5) {
        std::cout << "book1 ('" << book1.isbn << "') == book5 ('" << book5.isbn << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.isbn << "') == book5 ('" << book5.isbn << "'): False" << std::endl;
    }

    // Comparison 4: Empty ISBN (should work correctly)
    if (book1 == book6) {
        std::cout << "book1 ('" << book1.isbn << "') == book6 ('" << book6.isbn << "'): True" << std::endl;
    } else {
        std::cout << "book1 ('" << book1.isbn << "') == book6 ('" << book6.isbn << "'): False" << std::endl;
    }

    return 0;
}