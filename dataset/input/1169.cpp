#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor
    Book(std::string t = "", std::string a = "", std::string i = "") : title(t), author(a), isbn(i) {}

    // Getter for title
    std::string getTitle() const {
        return title;
    }

    // Setter for title
    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    // Getter for author
    std::string getAuthor() const {
        return author;
    }

    // Setter for author (Logical Error: Does not set the author correctly)
    void setAuthor(const std::string& newAuthor) {
        // This setter incorrectly assigns the title to the author,
        // or effectively clears the author instead of setting it to newAuthor.
        // It should be `author = newAuthor;`
        author = "Unknown Author"; // Logical error: Ignores the input parameter
    }

    // Getter for ISBN
    std::string getISBN() const {
        return isbn;
    }

    // Setter for ISBN
    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }
};

int main() {
    Book myBook("The Silent Patient", "Alex Michaelides", "978-1250301697");

    std::cout << "Initial Book Details:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl;
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    myBook.setTitle("Where the Crawdads Sing");
    myBook.setAuthor("Delia Owens"); // This call will have a logical error internally
    myBook.setISBN("978-0735219090");

    std::cout << "\nUpdated Book Details:" << std::endl;
    std::cout << "Title: " << myBook.getTitle() << std::endl;
    std::cout << "Author: " << myBook.getAuthor() << std::endl; // Will show "Unknown Author"
    std::cout << "ISBN: " << myBook.getISBN() << std::endl;

    return 0;
}