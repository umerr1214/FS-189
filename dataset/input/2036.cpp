#include <iostream>
#include <string>
#include <vector> // For std::string, not for collection management directly

// Book class from Q1
class Book {
public:
    std::string title;
    std::string author;
    int year;

    // Default constructor
    Book(std::string t = "", std::string a = "", int y = 0) : title(t), author(a), year(y) {}

    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", Year: " << year << std::endl;
    }
};

// Library class with readability/efficiency issues (inefficient resizing, pass by value)
class Library {
private:
    Book* my_book_collection; // Poor variable name
    int current_size;         // Poor variable name, represents count
    int max_capacity;         // Poor variable name, represents allocated capacity

public:
    // Constructor
    Library() : my_book_collection(nullptr), current_size(0), max_capacity(0) {
        // Inefficient initial allocation, better to start with a small capacity or lazy allocate
        max_capacity = 1;
        my_book_collection = new Book[max_capacity];
    }

    // Destructor to free dynamically allocated memory
    ~Library() {
        delete[] my_book_collection;
    }

    // Method to add a book - inefficient resizing and pass by value
    void addBook(Book a_book_to_add) { // Passing by value causes unnecessary copy
        std::cout << "Attempting to add: " << a_book_to_add.title << std::endl;
        if (current_size == max_capacity) {
            // Inefficient resizing: always increasing capacity by just 1
            // A better strategy is to double the capacity
            max_capacity += 1; 
            Book* new_collection_storage = new Book[max_capacity];

            // Manual copy loop - fine, but could be avoided with proper growth strategy
            for (int i = 0; i < current_size; ++i) {
                new_collection_storage[i] = my_book_collection[i];
            }

            delete[] my_book_collection; // Free old memory
            my_book_collection = new_collection_storage; // Update pointer
        }
        my_book_collection[current_size++] = a_book_to_add; // Add the book
    }

    // Method to display all books
    void displayAllBooks() const {
        if (current_size == 0) {
            std::cout << "Library is currently empty." << std::endl;
            return;
        }
        std::cout << "--- Current Library Books ---" << std::endl;
        for (int i = 0; i < current_size; i++) { // Using C-style loop, less readable than range-based for if std::vector was used
            my_book_collection[i].display();
        }
        std::cout << "-----------------------------" << std::endl;
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Hobbit", "J.R.R. Tolkien", 1937));
    myLibrary.addBook(Book("Dune", "Frank Herbert", 1965));
    myLibrary.addBook(Book("Foundation", "Isaac Asimov", 1951));
    myLibrary.addBook(Book("Neuromancer", "William Gibson", 1984));

    myLibrary.displayAllBooks();

    return 0;
}