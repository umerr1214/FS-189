#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor: Uses const std::string& for parameters to avoid unnecessary copies
    // and an initializer list for direct and efficient initialization of members.
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    // Public getter methods: All are declared const as they do not modify the object's state.
    // They return const references to avoid copying the string data.
    const std::string& getTitle() const {
        return title;
    }

    const std::string& getAuthor() const {
        return author;
    }

    const std::string& getIsbn() const {
        return isbn;
    }

    // displayBookInfo method: Declared const as it only reads and prints data.
    // Uses '\n' for newlines for efficiency, with a single std::endl at the end to flush.
    void displayBookInfo() const {
        std::cout << "Book Details:\n";
        std::cout << "  Title: " << title << "\n";
        std::cout << "  Author: " << author << "\n";
        std::cout << "  ISBN: " << isbn << std::endl; // Flush once at the end
    }
};

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");

    myBook.displayBookInfo();

    std::cout << "\nGetter Title: " << myBook.getTitle() << "\n";
    std::cout << "Getter Author: " << myBook.getAuthor() << "\n";
    std::cout << "Getter ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}