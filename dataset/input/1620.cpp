#include <iostream>
#include <string>
#include <iomanip>

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
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Price: $" << price << std::endl;
    }
};

int main() {
    Book myBook("The Catcher in the Rye", "J.D. Salinger", 8.75);

    // Semantic error: Attempting to access private members directly from main
    // This will cause a compilation error due to access violation.
    std::cout << "Attempting to access private title: " << myBook.title << std::endl;
    std::cout << "Attempting to access private author: " << myBook.author << std::endl;

    myBook.displayBookInfo(); // This line would be fine if the above lines didn't cause an error

    return 0;
}