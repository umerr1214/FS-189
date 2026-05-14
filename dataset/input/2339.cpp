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
        // LOGICAL ERROR: Loop starts from index 1, skipping the first book
        for (size_t i = 1; i < books.size(); ++i) {
            books[i]->display();
        }
    }
};

int main() {
    // Create Book objects on the stack (externally owned)
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams");
    Book book2("1984", "George Orwell");
    Book book3("Dune", "Frank Herbert");

    Library myLibrary;
    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(&book3);

    myLibrary.displayAllBooks();

    // Books are owned externally, so no deletion is expected here.
    return 0;
}