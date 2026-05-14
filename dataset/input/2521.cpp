#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor allows empty strings, which is a robustness issue if not intended
    Book(std::string title_val, std::string author_val, std::string isbn_val) {
        title = title_val;
        author = author_val;
        isbn = isbn_val;
    }

    void displayDetails() { // Missing const qualifier
        std::cout << "Book Details:" << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---" << std::endl;

    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayDetails();
    std::cout << "---" << std::endl;

    // Demonstrating the robustness issue: creating a book with empty details
    Book book3("", "", "");
    book3.displayDetails();
    std::cout << "---" << std::endl;

    return 0;
}