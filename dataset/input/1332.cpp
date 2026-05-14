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

    // Copy constructor with a semantic error: takes argument by value
    // This will cause infinite recursion and a stack overflow at runtime.
    Book(Book other) : title(other.title), author(other.author) { // Semantic error: should be 'const Book& other'
        std::cout << "Copy constructor called for Book: " << title << " by " << author << std::endl;
    }

    void display() const {
        std::cout << "Book: \"" << title << "\" by " << author << std::endl;
    }
};

int main() {
    // Demonstrate usage
    Book book1; // Default constructor
    book1.display();

    Book book2("The Hobbit", "J.R.R. Tolkien"); // Parameterized constructor
    book2.display();

    // The following line will trigger the semantic error (infinite recursion)
    // when the copy constructor tries to construct 'other' by value.
    Book book3 = book2; // Copy constructor - will cause stack overflow

    // The program will likely crash before reaching these lines
    book3.display();

    Book book4("1984", "George Orwell");
    Book book5(book4); // Another way to use copy constructor - will also cause stack overflow
    book5.display();

    return 0;
}