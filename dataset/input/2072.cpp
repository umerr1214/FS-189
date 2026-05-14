#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Setters - passing std::string by value (inefficient copy)
    void setTitle(std::string newTitle) {
        this->title = newTitle; // Excessive use of this->
    }

    void setAuthor(std::string newAuthor) {
        this->author = newAuthor; // Excessive use of this->
    }

    void setISBN(std::string newISBN) {
        this->isbn = newISBN; // Excessive use of this->
    }

    // Getters - not marked const
    std::string getTitle() {
        return this->title; // Excessive use of this->
    }

    std::string getAuthor() {
        return this->author; // Excessive use of this->
    }

    std::string getISBN() {
        return this->isbn; // Excessive use of this->
    }

    // Method to display book details
    void displayBookDetails() {
        std::cout << "Book Details:\n";
        std::cout << "  Title: " << this->title << "\n";
        std::cout << "  Author: " << this->author << "\n";
        std::cout << "  ISBN: " << this->isbn << "\n";
    }
};

int main() {
    Book myBook;

    myBook.setTitle("The C++ Programming Language");
    myBook.setAuthor("Bjarne Stroustrup");
    myBook.setISBN("978-0321563842");

    myBook.displayBookDetails();

    return 0;
}