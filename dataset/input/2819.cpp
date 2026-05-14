#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    void displayInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << title << std::endl; // Logical Error: Should print 'author', but prints 'title'
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayInfo();
    std::cout << "---" << std::endl;
    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayInfo();
    return 0;
}