#include <iostream>
#include <string> // Required for std::string

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Robustness Issue: Constructor uses C-style string pointers directly in initializer list.
    // If any of the char* arguments are nullptr, the std::string constructor will throw
    // a std::logic_error (or crash depending on stdlib implementation), which is not gracefully handled.
    // A robust solution would either check for nullptr before construction or use std::string arguments.
    Book(const char* t, const char* a, const char* i)
        : title(t), author(a), isbn(i) {
        // No explicit check for nullptr here, relying on std::string constructor behavior.
        // This can lead to a runtime crash if a nullptr is passed.
    }

    void displayInfo() const {
        std::cout << "Book Details:" << std::endl;
        std::cout << "  Title:  " << title << std::endl;
        std::cout << "  Author: " << author << std::endl;
        std::cout << "  ISBN:   " << isbn << std::endl;
    }
};

int main() {
    // Standard test cases that work (these inputs do not trigger the robustness issue)
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    book1.displayInfo();
    std::cout << "---" << std::endl;

    Book book2("1984", "George Orwell", "978-0451524935");
    book2.displayInfo();
    std::cout << "---" << std::endl;

    // The robustness issue (passing nullptr) is demonstrated in the JSON driver.
    // If you were to uncomment the line below, it would cause a runtime error:
    // Book book_crash(nullptr, "J.K. Rowling", "978-0747532743");

    return 0;
}