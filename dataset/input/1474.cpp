#include <string>
#include <iostream>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    // Parameterized constructor
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.display();
    return 0;
}