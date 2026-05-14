#include <iostream>
#include <string>

class Book {
private:
    std::string bookTitle;
    std::string bookAuthor;
    std::string bookISBN;

public:
    // Readability/Efficiency Issue:
    // 1. Passing std::string by value causes unnecessary copies.
    // 2. Member initialization in the constructor body leads to extra copy assignments.
    // 3. Inconsistent formatting.
    Book(std::string t, std::string a, std::string i) { // Arguments passed by value
        this->bookTitle = t; // First copy for 't', then assignment to bookTitle (another copy)
        this->bookAuthor = a;
        this->bookISBN = i;
    }

    // Readability Issue: Method not marked const, even though it doesn't modify object state.
    void displayInfo() { // Missing const qualifier
        std::cout << "Details:" << std::endl; // Slightly less descriptive label
        std::cout << " Title: " << bookTitle << std::endl;
        std::cout << " Author: " << bookAuthor << std::endl;
        std::cout << " ISBN: " << bookISBN << std::endl;
    }
};

int main() {
    Book b1("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    b1.displayInfo();
    std::cout << "---" << std::endl;

    Book b2("Moby Dick", "Herman Melville", "978-0142437247");
    b2.displayInfo();
    std::cout << "---" << std::endl;

    return 0;
}