#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;

    // Default constructor
    Book() : title("Untitled"), author("Unknown") {
        std::cout << "Default constructor called for Book: " << title << " by " << author << std::endl;
    }

    // Parameterized constructor
    Book(std::string t, std::string a) : title(t), author(a) {
        std::cout << "Parameterized constructor called for Book: " << title << " by " << author << std::endl;
    }

    // Copy constructor with a logical error
    Book(const Book& other) : title(other.title), author("Unknown Author") { // Logical error: author is not copied from 'other'
        std::cout << "Copy constructor called for Book: " << title << " by " << author << std::endl;
    }

    void display() const {
        std::cout << "Book: \"" << title << "\" by " << author << std::endl;
    }
};

int main() {
    // Demonstrate usage
    Book book1; // Default constructor
    book1.display(); // Expected: Untitled by Unknown

    Book book2("The Hobbit", "J.R.R. Tolkien"); // Parameterized constructor
    book2.display(); // Expected: The Hobbit by J.R.R. Tolkien

    Book book3 = book2; // Copy constructor - will show logical error
    book3.display(); // Expected: The Hobbit by Unknown Author (ERROR)

    Book book4("1984", "George Orwell");
    book4.display(); // Expected: 1984 by George Orwell

    Book book5(book4); // Another way to use copy constructor - will show logical error
    book5.display(); // Expected: 1984 by Unknown Author (ERROR)

    return 0;
}