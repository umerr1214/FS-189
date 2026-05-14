#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Setters - taking const std::string& for efficiency, returning *this for chaining
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }

    // Getters - marked const and returning const std::string& for efficiency and correctness
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    const std::string& getISBN() const {
        return isbn;
    }

    // Method to display book details
    void displayBookDetails() const {
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

    return 0;
}