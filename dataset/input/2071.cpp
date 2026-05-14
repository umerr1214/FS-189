#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Setters - No input validation, allowing empty strings
    void setTitle(std::string newTitle) {
        title = newTitle;
    }

    void setAuthor(std::string newAuthor) {
        author = newAuthor;
    }

    void setISBN(std::string newISBN) {
        isbn = newISBN;
    }

    // Getters
    std::string getTitle() {
        return title;
    }

    std::string getAuthor() {
        return author;
    }

    std::string getISBN() {
        return isbn;
    }

    // Method to display book details
    void displayBookDetails() {
        std::cout << "Book Details:\n";
        std::cout << "  Title: " << title << "\n";
        std::cout << "  Author: " << author << "\n";
        std::cout << "  ISBN: " << isbn << "\n";
    }
};

int main() {
    Book myBook;

    // Setting details
    myBook.setTitle("The C++ Programming Language");
    myBook.setAuthor("Bjarne Stroustrup");
    myBook.setISBN("978-0321563842");

    myBook.displayBookDetails();

    std::cout << "\n--- Testing with empty fields ---\n";
    Book emptyBook;
    emptyBook.setTitle(""); // Allowing empty title
    emptyBook.setAuthor(""); // Allowing empty author
    emptyBook.setISBN("");   // Allowing empty ISBN
    emptyBook.displayBookDetails();

    return 0;
}