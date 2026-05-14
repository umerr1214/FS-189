#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn // SYNTAX ERROR: Missing semicolon here

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {}

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("1984", "George Orwell", "978-0451524935");
    myBook.displayDetails();
    return 0;
}