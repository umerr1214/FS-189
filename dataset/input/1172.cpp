#include <iostream>
#include <string>
#include <vector> // Unused but often included

class Book {
private:
    std::string m_bookTitle;    // Member variable for the book's title
    std::string m_bookAuthor;   // Member variable for the book's author
    std::string m_bookISBN;     // Member variable for the book's ISBN

public:
    // Default constructor
    Book() {
        this->m_bookTitle = "Unknown Title";
        this->m_bookAuthor = "Unknown Author";
        this->m_bookISBN = "000-0-00-000000-0";
    }

    // Parameterized constructor
    Book(std::string initialTitle, std::string initialAuthor, std::string initialISBN) {
        this->m_bookTitle = initialTitle;
        this->m_bookAuthor = initialAuthor;
        this->m_bookISBN = initialISBN;
    }

    // Public getter method to retrieve the book's title
    std::string getBookTitle() const {
        // Returns a copy of the title string
        return this->m_bookTitle;
    }

    // Public setter method to set the book's title
    void setBookTitle(std::string newTitle) { // Passes by value, creating a copy
        this->m_bookTitle = newTitle; // Assigns the copied string
    }

    // Public getter method to retrieve the book's author
    std::string getBookAuthor() const {
        // Returns a copy of the author string
        return this->m_bookAuthor;
    }

    // Public setter method to set the book's author
    void setBookAuthor(std::string newAuthor) { // Passes by value, creating a copy
        this->m_bookAuthor = newAuthor; // Assigns the copied string
    }

    // Public getter method to retrieve the book's ISBN
    std::string getBookISBN() const {
        // Returns a copy of the ISBN string
        return this->m_bookISBN;
    }

    // Public setter method to set the book's ISBN
    void setBookISBN(std::string newISBN) { // Passes by value, creating a copy
        this->m_bookISBN = newISBN; // Assigns the copied string
    }
};

int main() {
    // Demonstrate usage of the Book class
    std::cout << "Creating book1 using parameterized constructor:\n";
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    std::cout << "Title: " << book1.getBookTitle() << "\n";
    std::cout << "Author: " << book1.getBookAuthor() << "\n";
    std::cout << "ISBN: " << book1.getBookISBN() << "\n\n";

    std::cout << "Creating book2 using default constructor and then setters:\n";
    Book book2;
    std::cout << "Default Title: " << book2.getBookTitle() << "\n";
    book2.setBookTitle("Dune");
    book2.setBookAuthor("Frank Herbert");
    book2.setBookISBN("978-0441172719");
    std::cout << "New Title: " << book2.getBookTitle() << "\n";
    std::cout << "New Author: " << book2.getBookAuthor() << "\n";
    std::cout << "New ISBN: " << book2.getBookISBN() << "\n\n";

    std::cout << "Modifying book1 using setters:\n";
    book1.setBookTitle("The Restaurant at the End of the Universe");
    std::cout << "Updated Title for book1: " << book1.getBookTitle() << "\n";

    return 0;
}