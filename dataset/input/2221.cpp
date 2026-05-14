#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor taking std::string by value for parameters.
    // This can lead to an extra copy if the arguments passed are already std::string objects,
    // impacting resource robustness in scenarios with many objects or large strings.
    Book(std::string t, std::string a, std::string i) {
        title = t;
        author = a;
        isbn = i;
    }

    // Getter methods are correctly const
    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getIsbn() const {
        return isbn;
    }

    // displayBookInfo is NOT const. This is a robustness issue because a method
    // that only displays information should not logically modify the object's state
    // and should be callable on const Book objects.
    void displayBookInfo() { // Missing const qualifier
        std::cout << "Book Details:" << std::endl;
        std::cout << "  Title: " << title << std::endl;
        std::cout << "  Author: " << author << std::endl;
        std::cout << "  ISBN: " << isbn << std::endl;
    }
};

int main() {
    Book myBook("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803");

    myBook.displayBookInfo();

    std::cout << "\nGetter Title: " << myBook.getTitle() << std::endl;
    std::cout << "Getter Author: " << myBook.getAuthor() << std::endl;
    std::cout << "Getter ISBN: " << myBook.getIsbn() << std::endl;

    return 0;
}