#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    // Logical Error: Compares 'title' instead of 'isbn'
    bool operator==(const Book& other) const {
        return title == other.title; // Should be isbn == other.isbn
    }
};

int main() {
    Book book1("The Hitchhiker's Guide", "Douglas Adams", "978-0345391803");
    Book book2("The Restaurant at the End of the Universe", "Douglas Adams", "978-0345391803"); // Same ISBN, different title
    Book book3("The Hitchhiker's Guide", "Douglas Adams", "978-0141439518"); // Same title, different ISBN

    // With the logical error, the output will be incorrect.
    // book1 == book2 will be false (different titles)
    // book1 == book3 will be true (same titles)

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