#include <iostream>
#include <string>

class Book {
private: // isbn is private
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    // A public getter would be needed if operator== is a non-member and not a friend.
    // std::string getIsbn() const { return isbn; }
};

// Semantic Error: operator== is defined as a non-member function,
// but it attempts to access the private member 'isbn' directly.
// This will result in a compilation error due to access violation.
bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.isbn == rhs.isbn; // Error: 'Book::isbn' is private
}

int main() {
    Book book1("The Hitchhiker's Guide", "Douglas Adams", "978-0345391803");
    Book book2("The Restaurant at the End of the Universe", "Douglas Adams", "978-0345391803"); // Same ISBN
    Book book3("Pride and Prejudice", "Jane Austen", "978-0141439518");

    if (book1 == book2) {
        std::cout << "Book 1 and Book 2 are equal (same ISBN)." << std::endl;
    } else {
        std::cout << "Book 1 and Book 2 are not equal." << std::endl;
    }

    if (book1 == book3) {
        std::cout << "Book 1 and Book 3 are equal (same ISBN)." << std::endl;
    } else {
        std::cout << "Book 1 and Book 3 are not equal." << std::endl;
    }

    return 0;
}