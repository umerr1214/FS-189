#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Default constructor
    Book() : title(""), author(""), isbn("") {}

    // Parameterized constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Getter for title
    const std::string& getTitle() const {
        return title;
    }

    // Setter for title
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    // Getter for author
    const std::string& getAuthor() const {
        return author;
    }

    // Setter for author
    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    // Getter for ISBN
    const std::string& getIsbn() const {
        return isbn;
    }

    // Setter for ISBN
    void setIsbn(const std::string& newIsbn) {
        isbn = newIsbn;
    }
};

int main() {
    // Test Case 1: Create a book using the parameterized constructor
    Book book1("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    std::cout << "Book 1 Details:\n";
    std::cout << "Title: " << book1.getTitle() << "\n";
    std::cout << "Author: " << book1.getAuthor() << "\n";
    std::cout << "ISBN: " << book1.getIsbn() << "\n\n";

    // Test Case 2: Create a book using the default constructor and then setters
    Book book2;
    book2.setTitle("Pride and Prejudice");
    book2.setAuthor("Jane Austen");
    book2.setIsbn("978-0141439518");
    std::cout << "Book 2 Details:\n";
    std::cout << "Title: " << book2.getTitle() << "\n";
    std::cout << "Author: " << book2.getAuthor() << "\n";
    std::cout << "ISBN: " << book2.getIsbn() << "\n\n";

    // Test Case 3: Modify an existing book
    book1.setTitle("The Hobbit");
    std::cout << "Updated Book 1 Title: " << book1.getTitle() << "\n\n";

    // Test Case 4: Test with empty strings (valid input for string types)
    Book book3("", "", "");
    std::cout << "Book 3 (Empty fields) Details:\n";
    std::cout << "Title: '" << book3.getTitle() << "'\n";
    std::cout << "Author: '" << book3.getAuthor() << "'\n";
    std::cout << "ISBN: '" << book3.getIsbn() << "'\n\n";

    return 0;
}