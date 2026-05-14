#include <iostream>
#include <string> // Required for std::string

class Book {
private:
    std::string title;
    std::string author;

public:
    // Default constructor: Initializes title and author with empty strings.
    Book() : title(""), author("") {}

    // Parameterized constructor: Initializes title and author with provided values.
    // Uses const references for efficiency and to prevent accidental modification.
    Book(const std::string& title_param, const std::string& author_param)
        : title(title_param), author(author_param) {}

    // Copy constructor: Initializes members by copying from another Book object.
    // Uses a const reference to the 'other' object for efficiency and correctness.
    Book(const Book& other)
        : title(other.title), author(other.author) {}

    // Display method: Prints the book's title and author.
    // Marked const as it does not modify the object's state.
    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
};

int main() {
    // 1. Demonstrate Default constructor
    Book book1; // Creates a Book object using the default constructor
    std::cout << "Book 1 (Default): ";
    book1.display();

    // 2. Demonstrate Parameterized constructor
    Book book2("To Kill a Mockingbird", "Harper Lee"); // Creates a Book object using the parameterized constructor
    std::cout << "Book 2 (Parameterized): ";
    book2.display();

    // 3. Demonstrate Copy constructor
    Book book3 = book2; // Creates book3 as a copy of book2 using the copy constructor
    std::cout << "Book 3 (Copy of Book 2): ";
    book3.display();

    Book book4(book1); // Another way to call the copy constructor
    std::cout << "Book 4 (Copy of Book 1): ";
    book4.display();

    return 0;
}