#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Efficiency Issue: std::string parameters passed by value, causing unnecessary copies.
    // Readability Issue: Direct assignment in constructor body, less efficient than initializer list.
    Book(std::string t, std::string a, std::string i) {
        this->title = t; // Another copy
        this->author = a; // Another copy
        this->isbn = i; // Another copy
    }

    // Readability Issue: Method is not const, even though it doesn't modify the object.
    // Efficiency Issue: Uses std::endl which flushes the buffer on each line, less efficient than '\n'.
    void displayDetails() {
        std::cout << "Book Details:" << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayDetails();
    std::cout << "---\n";

    Book book2("Pride and Prejudice", "Jane Austen", "978-0141439518");
    book2.displayDetails();
    std::cout << "---\n";

    Book book3("Empty Title", "", "No ISBN");
    book3.displayDetails();

    return 0;
}