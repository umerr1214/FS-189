#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) :
        title(t), author(a), isbn(i) {}

    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    myBook.displayBookInfo();
    return 0;
}