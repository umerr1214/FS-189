#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), isbn(i) {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getIsbn() const { return isbn; }

    void displayBookInfo() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << title << std::endl; // Logical error: should be 'author'
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("1984", "George Orwell", "978-0451524935");
    myBook.displayBookInfo();
    return 0;
}