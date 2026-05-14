#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Setters
    void setTitle(const std::string& t) { title = t; }
    void setAuthor(const std::string& a) { author = a; }
    void setISBN(const std::strin& i) { isbn = i; } // SYNTAX ERROR: 'std::strin' instead of 'std::string'

    // Getters
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }

    // Display method
    void displayBookDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1;
    book1.setTitle("The C++ Programming Language");
    book1.setAuthor("Bjarne Stroustrup");
    book1.setISBN("978-0321992789"); // This line will cause a compilation error due to the syntax error in setISBN's signature.
    book1.displayBookDetails();

    return 0;
}