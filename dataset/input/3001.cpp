#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    // Default constructor: Initializes with "N/A" instead of empty strings (slight deviation from requirement)
    Book() : title("N/A"), author("N/A") {
        // This is a subtle robustness issue regarding strict adherence to the "empty strings" requirement.
    }

    // Parameterized constructor
    Book(const std::string& title_param, const std::string& author_param)
        : title(title_param), author(author_param) {}

    // Copy constructor: Takes by value instead of const reference, causing an unnecessary copy
    // This is a robustness issue in terms of efficiency and resource usage for larger objects.
    Book(Book other) : title(other.title), author(other.author) {
        // The 'other' parameter itself is a copy, then its members are copied again.
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    // 1. Demonstrate Default constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.display();

    // 2. Demonstrate Parameterized constructor
    Book book2("The Great Gatsby", "F. Scott Fitzgerald");
    std::cout << "Book 2 (Parameterized): ";
    book2.display();

    // 3. Demonstrate Copy constructor
    Book book3 = book2; // Calls copy constructor
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.display();

    Book book4(book1); // Calls copy constructor
    std::cout << "Book 4 (Copy of Book 1): ";
    book4.display();

    return 0;
}