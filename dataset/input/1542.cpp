#include <iostream>
#include <string>

class Book {
private:
    const std::string title; // Make title const
    std::string author;
    std::string isbn;

public:
    Book(const std::string& titleParam, const std::string& authorParam, const std::string& isbnParam)
        : author(authorParam), isbn(isbnParam) { // Semantic Error: 'title' (const member) is not initialized in the initializer list
        title = titleParam; // This assignment is invalid for a const member
    }

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
    }

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getISBN() const { return isbn; }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.display();
    Book book2("1984", "George Orwell", "978-0451524935");
    book2.display();
    return 0;
}