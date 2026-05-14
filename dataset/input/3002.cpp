#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;

public:
    // Default constructor: Initializes members in the constructor body, not initializer list.
    // This is less efficient as std::string members are default-constructed then assigned.
    Book() {
        this->title = ""; // Unnecessary use of 'this->' and less efficient assignment.
        this->author = "";
    }

    // Parameterized constructor: Initializes members in the constructor body.
    Book(const std::string& title_param, const std::string& author_param) {
        this->title = title_param; // Less efficient due to default construction + assignment.
        this->author = author_param;
    }

    // Copy constructor: Initializes members in the constructor body.
    Book(const Book& other) {
        this->title = other.title; // Less efficient due to default construction + assignment.
        this->author = other.author;
    }

    void display() const {
        // Unnecessary use of 'this->' for member access.
        std::cout << "Title: " << this->title << ", Author: " << this->author << std::endl;
    }
};

int main() {
    // 1. Demonstrate Default constructor
    Book book1;
    std::cout << "Book 1 (Default): ";
    book1.display();

    // 2. Demonstrate Parameterized constructor
    Book book2("1984", "George Orwell");
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