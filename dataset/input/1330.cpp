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

    // Copy constructor
    Book(const Book& other) : title(other.title), author(other.author) {
        std::cout << "Copy constructor called for Book: " << title << " by " << author << std::endl;
    }

    void display() const {
        std::cout << "Book: \"" << title << "\" by " << author << std::endl;
    }
} // ERROR: Missing semicolon here

int main() {
    // Demonstrate usage
    Book book1; // Default constructor
    book1.display();

    Book book2("The Hobbit", "J.R.R. Tolkien"); // Parameterized constructor
    book2.display();

    Book book3 = book2; // Copy constructor
    book3.display();

    Book book4("1984", "George Orwell");
    Book book5(book4); // Another way to use copy constructor
    book5.display();

    return 0;
}