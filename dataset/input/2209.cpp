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

    // Getters are provided for completeness, though operator<< will access private members directly.
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }
    const std::string& getISBN() const { return isbn; }

    // Friend declaration for the overloaded operator<<.
    // Robustness issue: The operator takes Book by non-const reference.
    // Robustness issue: The operator returns std::ostream by value.
    friend std::ostream operator<<(std::ostream& os, Book& book);
};

// Robustness Issue:
// 1. Takes 'book' by non-const reference (Book& book). An output operator should
//    generally not modify the object it's printing, so it should take 'const Book&'.
//    This design choice makes the function less robust against accidental modification.
// 2. Returns 'std::ostream' by value instead of 'std::ostream&'. This breaks
//    stream chaining (e.g., std::cout << book1 << book2;) because subsequent
//    '<<' operations would apply to a *copy* of the stream, not the original.
std::ostream operator<<(std::ostream& os, Book& book) {
    os << "Title: " << book.title
       << ", Author: " << book.author
       << ", ISBN: " << book.isbn;
    return os; // Returns a copy of the ostream object
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "George Orwell", "978-0451524935");

    std::cout << "Printing book1 (non-const Book&, stream returned by value):\n";
    std::cout << book1 << std::endl; // std::endl will work as it's chained to std::cout directly

    std::cout << "\nPrinting book2 with chaining attempt:\n";
    // The text " - A classic dystopian novel." will still appear on console,
    // but it's technically being streamed to a temporary copy of std::cout
    // returned by the overloaded operator, not the original std::cout object.
    // This can lead to subtle bugs or unexpected behavior in more complex scenarios
    // (e.g., with std::stringstream or when manipulating stream state).
    std::cout << book2 << " - A classic dystopian novel." << std::endl;

    return 0;
}