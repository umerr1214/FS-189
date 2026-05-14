#include <iostream>
#include <vector>
#include <string>

// Book class (simplified from Q1)
class Book {
private:
    std::string title;
    std::string author;
public:
    Book(std::string t, std::string a) : title(t), author(a) {}
    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }
    std::string getTitle() const { return title; }
};

class Library {
private:
    std::vector<Book*> books; // Aggregation
public:
    void addBook(Book* book) {
        if (book) {
            books.push_back(book);
        }
    }
    void displayAllBooks() const {
        if (books.empty()) {
            std::cout << "Library is empty." << std::endl;
            return;
        }
        std::cout << "Books in Library:" << std::endl;
        for (const auto& book : books) {
            book->display();
        }
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // Create Book objects on the stack (externally owned)
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2("1984", "George Orwell");

    Library myLibrary;
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.displayAllBooks();

    // Books are owned externally, so no deletion is expected here.
    return 0;
}