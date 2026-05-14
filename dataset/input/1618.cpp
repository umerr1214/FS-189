#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author // MISSING SEMICOLON HERE, WILL CAUSE SYNTAX ERROR
    double price;

public:
    // Parameterized constructor
    Book(std::string t, std::string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    // Public method to display book information
    void displayBookInfo() {
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: $" << price << std::endl;
    }
};

int main() {
    // Create a Book object
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", 12.99);

    // Display book information
    myBook.displayBookInfo();

    return 0;
}