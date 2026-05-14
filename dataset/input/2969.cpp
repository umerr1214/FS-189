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
        // Logical Error: Accidentally printing isbn for title and author
        std::cout << "Title: " << isbn << std::endl;
        std::cout << "Author: " << isbn << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("1984", "George Orwell", "978-0451524935");
    myBook.displayBookInfo();
    return 0;
}