#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Efficiency issue: passing strings by value incurs unnecessary copies.
    // Readability issue: Overuse of 'this->' when not strictly necessary for disambiguation.
    Book(std::string title_param, std::string author_param, std::string isbn_param) {
        this->title = title_param;
        this->author = author_param;
        this->isbn = isbn_param;
    }

    // Readability issue: verbose printing, and also could be const
    void displayDetails() {
        std::cout << "Book Details:" << std::endl;
        std::cout << "    Title: " << this->title << std::endl;
        std::cout << "    Author: " << this->author << std::endl;
        std::cout << "    ISBN: " << this->isbn << std::endl;
        std::cout << "    --------------------" << std::endl; // Unnecessary extra line
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---" << std::endl;

    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayDetails();
    std::cout << "---" << std::endl;

    return 0;
}