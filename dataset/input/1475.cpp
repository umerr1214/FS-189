#include <string>
#include <iostream>

class Book {
public:
    std::string title;
    std::string author;
    std::string isbn;

    // Parameterized constructor with a logical error:
    // All members are incorrectly initialized with the 't' parameter.
    Book(std::string t, std::string a, std::string i) : title(t), author(t), isbn(t) {}

    void display() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    book1.display();
    return 0;
}