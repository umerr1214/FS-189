#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor to initialize empty strings
    Book() : title(""), author(""), isbn("") {}

    // Setters (Semantic Error: these setters do not actually update the private members)
    void setTitle(const std::string& t) { /* Intentionally left blank: title is not set */ } // SEMANTIC ERROR
    void setAuthor(const std::string& a) { /* Intentionally left blank: author is not set */ } // SEMANTIC ERROR
    void setISBN(const std::string& i) { /* Intentionally left blank: isbn is not set */ }   // SEMANTIC ERROR

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
    Book book1; // Members initialized to empty strings by constructor
    book1.setTitle("The Lord of the Rings");
    book1.setAuthor("J.R.R. Tolkien");
    book1.setISBN("978-0618053267");

    std::cout << "--- Book 1 Details ---" << std::endl;
    book1.displayBookDetails(); // Will print empty strings due to semantic error in setters
    std::cout << std::endl;

    Book book2;
    book2.setTitle("Dune");
    book2.setAuthor("Frank Herbert");
    book2.setISBN("978-0441172719");

    std::cout << "--- Book 2 Details ---" << std::endl;
    book2.displayBookDetails(); // Will print empty strings due to semantic error in setters

    return 0;
}