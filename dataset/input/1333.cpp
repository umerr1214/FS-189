#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;

    // Default constructor
    Book() : title("Unknown Title"), author("Unknown Author") {
    }

    // Parameterized constructor
    Book(const std::string& t, const std::string& a) : title(t), author(a) {
    }

    // Copy constructor
    Book(const Book& other) : title(other.title), author(other.author) {
    }

    // Robustness Issue: Getters return non-const references, allowing external modification
    std::string& getTitle() {
        return title;
    }

    std::string& getAuthor() {
        return author;
    }

    void print() const {
        std::cout << "Book: \"" << title << "\" by " << author << std::endl;
    }
};

int main() {
    // 1. Default constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.print();

    // 2. Parameterized constructor
    Book book2("The Great Gatsby", "F. Scott Fitzgerald");
    std::cout << "Book 2 (Parameterized): ";
    book2.print();

    // 3. Copy constructor
    Book book3 = book2; // Calls copy constructor
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.print();

    // Demonstrate the robustness issue: modifying internal state via non-const getters
    std::cout << "\nDemonstrating robustness issue (modifying via getter):" << std::endl;
    std::cout << "Before modification:" << std::endl;
    book1.print();
    book2.print();

    book1.getTitle() = "New Default Title";
    book1.getAuthor() = "New Default Author";

    book2.getTitle() = "Modified Gatsby";
    // This could lead to unexpected behavior if class invariants depended on title/author not being externally modifiable.
    // For simple strings, it's less catastrophic but still breaks encapsulation.

    std::cout << "After modification:" << std::endl;
    book1.print();
    book2.print();
    book3.print(); // book3 should be unchanged, as it was a copy before modification

    return 0;
}