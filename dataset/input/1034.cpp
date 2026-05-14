#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

std::ostream& operator<<(std::ostream& os, const Book& book) {
    // LOGICAL ERROR: Prints title for both title and author fields
    os << book.title << " by " << book.title << " (" << book.isbn << ")";
    return os;
}

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    Book book2("1984", "George Orwell", "978-0451524935");
    Book book3("Pride and Prejudice", "Jane Austen", "978-0141439518");

    std::cout << "Test Case 1: " << book1 << std::endl;
    std::cout << "Test Case 2: " << book2 << std::endl;
    std::cout << "Test Case 3: " << book3 << std::endl;

    return 0;
}