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

    // Semantic Error: displayBookInfo should be declared const as it does not modify object state.
    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    myBook.displayBookInfo();
    return 0;
}