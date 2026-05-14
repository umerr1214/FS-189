#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor with abbreviated parameter names (readability issue).
    // Takes std::string by value and assigns, leading to extra copies (efficiency issue).
    Book(std::string t, std::string a, std::string i) {
        this->title = t;   // Verbose use of this-> (readability issue)
        this->author = a;  // Verbose use of this-> (readability issue)
        this->isbn = i;    // Verbose use of this-> (readability issue)
    }

    // Getter methods, also using verbose this->
    std::string getTitle() const {
        return this->title;
    }

    std::string getAuthor() const {
        return this->author;
    }

    std::string getIsbn() const {
        return this->isbn;
    }

    void displayBookInfo() const {
        std::cout << "Book Details:" << std::endl; // Frequent std::endl (efficiency issue)
        std::cout << "  Title: " << this->title << std::endl; // Frequent std::endl, verbose this->
        std::cout << "  Author: " << this->author << std::endl; // Frequent std::endl, verbose this->
        std::cout << "  ISBN: " << this->isbn << std::endl; // Frequent std::endl, verbose this->
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