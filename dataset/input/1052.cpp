#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Default constructor - only initializes title explicitly, others implicitly default-construct
    Book() {
        title = "Untitled"; // Explicitly set title
        // author and isbn are implicitly default-constructed to empty strings.
        // This might not fully satisfy 'explicitly initialize attributes to empty or default values' for all.
    }

    // Parameterized constructor - logically incorrect, shadows member variables
    Book(std::string title, std::string author, std::string isbn) {
        std::string local_title = title;   // This declares a new local variable 'local_title'
        std::string local_author = author; // Member 'this->author' remains default-constructed (empty)
        std::string local_isbn = isbn;     // Member 'this->isbn' remains default-constructed (empty)
        // The member variables `this->title`, `this->author`, `this->isbn` are not initialized by the parameters.
        // They remain default-constructed to empty strings.
    }

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }

    void printDetails() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1; // Should use default constructor
    std::cout << "Default Book Details:" << std::endl;
    book1.printDetails();

    Book book2("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842"); // Parameterized
    std::cout << "\nParameterized Book Details:" << std::endl;
    book2.printDetails();

    return 0;
}