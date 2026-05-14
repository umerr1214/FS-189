#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Default constructor
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor
    Book(std::string title, std::string author, std::string isbn) :
        title(title), author(author), isbn(isbn) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }

    void printDetails() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Book book1; // Should use default constructor
    std::cout << "Default Book Details:" << std::endl;
    book1.printDetails();

    Book book2("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842"); // Parameterized
    std::cout << "\nParameterized Book Details:" << std::endl;
    book2.printDetails();

    return 0;
}