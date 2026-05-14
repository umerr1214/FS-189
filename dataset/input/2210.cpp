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

    // Getters are used here, which is fine, but direct private member access
    // is also an option for friend functions.
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getISBN() const { return isbn; }

    // Friend declaration for the overloaded operator<<.
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// Readability/Efficiency Issue:
// This implementation builds a complete temporary std::string object for the
// formatted output first, then streams that single string to 'os'.
// This is less efficient than directly streaming each part (title, author, isbn)
// to the output stream, as it involves an unnecessary string allocation and copy.
std::ostream& operator<<(std::ostream& os, const Book& book) {
    std::string temp_output = "Title: " + book.getTitle() +
                              ", Author: " + book.getAuthor() +
                              ", ISBN: " + book.getISBN();
    os << temp_output; // Prints the constructed temporary string
    return os;
}

int main() {
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618260274");
    Book book2("Dune", "Frank Herbert", "978-0441013593");

    std::cout << "Book 1 details (inefficient string construction):\n";
    std::cout << book1 << std::endl;
    std::cout << "\nBook 2 details (inefficient string construction):\n";
    std::cout << book2 << std::endl;

    return 0;
}