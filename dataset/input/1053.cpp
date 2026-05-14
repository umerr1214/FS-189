#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Default constructor - correctly initializes to empty strings
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor - semantically swaps title and author initialization
    Book(std::string title_arg, std::string author_arg, std::string isbn_arg) :
        title(author_arg), // Semantic error: assigns author_arg to title
        author(title_arg), // Semantic error: assigns title_arg to author
        isbn(isbn_arg)     // Correctly assigns isbn_arg to isbn
    {}

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