#include <iostream>
#include <string>
#include <utility> // For std::move

class Book {
private:
    std::string title;
    std::string author;

public:
    // Constructor using std::move for efficiency
    Book(std::string title, std::string author)
        : title(std::move(title)), author(std::move(author)) {}

    // Getter methods for title and author
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }

    // Friend declaration: Allows the overloaded operator<< to access private members
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// Correct overload of the << (insertion) operator for Book objects
// Takes std::ostream& by non-const reference and const Book& by const reference.
// Returns std::ostream& to allow chaining.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    // Prints in a clear, readable format using direct streaming and '\n' for newlines
    os << "Title: \"" << book.title << "\", Author: \"" << book.author << "\"";
    return os;
}

int main() {
    // Test case 1: Basic printing of a Book object
    Book book1("The Lord of the Rings", "J.R.R. Tolkien");
    std::cout << "Book 1: " << book1 << '\n';

    // Test case 2: Printing another Book object
    Book book2("Dune", "Frank Herbert");
    std::cout << "Book 2: " << book2 << '\n';

    // Test case 3: Demonstrating chaining of the operator<<
    Book book3("Foundation", "Isaac Asimov");
    std::cout << "Book 3: " << book3 << "; " << "Another message." << '\n';

    // Test case 4: Book with empty title/author to ensure robustness
    Book book4("", "");
    std::cout << "Empty Book: " << book4 << '\n';

    return 0;
}