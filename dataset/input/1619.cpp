#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Book {
private:
    std::string title;
    std::string author;
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
        // Logical error: Prints author again instead of price
        std::cout << "Author (repeated): " << author << std::endl; // Should be price
    }
};

int main() {
    // Create a Book object
    Book myBook("1984", "George Orwell", 9.50);

    // Display book information
    myBook.displayBookInfo();

    std::cout << "--- Another Book ---" << std::endl;
    Book anotherBook("The Great Gatsby", "F. Scott Fitzgerald", 10.25);
    anotherBook.displayBookInfo();

    return 0;
}