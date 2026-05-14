#include <iostream>
#include <string>
#include <utility> // For std::move

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string title, std::string author, std::string isbn)
        : title(std::move(title)), author(std::move(author)), isbn(std::move(isbn)) {}

    // No getters are strictly needed for a friend operator, direct access is used for conciseness.

    // Friend declaration for the overloaded operator<<.
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// Correct Version:
// - Returns std::ostream& to enable stream chaining.
// - Takes const Book& to ensure the book object is not modified and can accept const objects.
// - Prints directly to the stream in parts without intermediate string creation,
//   which is efficient and idiomatic C++.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title: " << book.title
       << ", Author: " << book.author
       << ", ISBN: " << book.isbn;
    return os;
}

int main() {
    Book book1("To Kill a Mockingbird", "Harper Lee", "978-0446310789");
    Book book2("Pride and Prejudice", "Jane Austen", "978-0141439518");

    std::cout << "Book 1: " << book1 << std::endl;
    // Demonstrate chaining with additional text after the book object
    std::cout << "Book 2: " << book2 << " - A timeless classic." << std::endl;

    return 0;
}