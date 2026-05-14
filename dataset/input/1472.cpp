#include <iostream>
#include <string>
#include <vector> // Required for complete C++ program structure, even if not directly used by Book class
#include <sstream> // Required for complete C++ program structure, even if not directly used by Book class

using namespace std; // Readability Issue: Global using directive, pollutes global namespace

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    // Constructor
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Getter methods
    // Efficiency Issue: Returns std::string by value, causing unnecessary copies.
    // Readability/Correctness Issue: Missing 'const' qualifier, indicating the method doesn't modify the object.
    string getTitle() { 
        return title;
    }

    string getAuthor() { 
        return author;
    }

    string getIsbn() { 
        return isbn;
    }

    // Method to display book information
    // Readability/Correctness Issue: Missing 'const' qualifier.
    // Efficiency Issue: Uses std::endl on every line, causing frequent flushing.
    void displayBookInfo() { 
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

int main() {
    // Test Case 1
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");
    cout << "--- Book 1 ---" << endl;
    book1.displayBookInfo();
    cout << "--- End Book 1 ---" << endl;

    // Test Case 2
    Book book2("1984", "George Orwell", "978-0451524935");
    cout << "--- Book 2 ---" << endl;
    book2.displayBookInfo();
    cout << "--- End Book 2 ---" << endl;

    // Test Case 3 (empty fields)
    Book book3("", "Unknown Author", "");
    cout << "--- Book 3 ---" << endl;
    book3.displayBookInfo();
    cout << "--- End Book 3 ---" << endl;

    return 0;
}