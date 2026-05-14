#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor vulnerable to nullptr char* arguments.
    // std::string(const char*) expects a valid, non-null pointer.
    // Passing a nullptr will lead to undefined behavior or a crash.
    // A robust implementation would check for nullptr before assignment
    // or, preferably, use std::string parameters directly.
    Book(const char* t, const char* a, const char* i) {
        title = t;
        author = a;
        isbn = i;
    }

    void displayDetails() {
        std::cout << "Book Details:" << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
    }
};

int main() {
    // These calls pass valid C-strings (including empty ones), which std::string handles fine.
    // The robustness issue is with *nullptr* specifically, not empty strings.
    // To demonstrate the actual crash, one would need to pass nullptr directly,
    // e.g., Book book4(nullptr, "Crash Author", "Crash ISBN"); which would crash the program.
    // We avoid executing such a line to ensure the test runner completes successfully.
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