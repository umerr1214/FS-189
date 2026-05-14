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
    void setISBN(const std::string& i) { isbn = i; }

    // Getters
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }

    // Display method (Logical Error: prints title for author and ISBN)
    void displayBookDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << title << std::endl; // LOGICAL ERROR: Should be 'author'
        std::cout << "ISBN: " << title << std::endl;   // LOGICAL ERROR: Should be 'isbn'
    }
};

int main() {
    Book book1;
    book1.setTitle("The Hitchhiker's Guide to the Galaxy");
    book1.setAuthor("Douglas Adams");
    book1.setISBN("978-0345391803");

    std::cout << "--- Book 1 Details ---" << std::endl;
    book1.displayBookDetails();
    std::cout << std::endl;

    Book book2;
    book2.setTitle("1984");
    book2.setAuthor("George Orwell");
    book2.setISBN("978-0451524935");

    std::cout << "--- Book 2 Details ---" << std::endl;
    book2.displayBookDetails();

    return 0;
}