#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), isbn(i) {}

    void displayDetails() const {
        std::cout << "Title: " << title << std::endl;
        std::cout << "ISBN: " << isbn << std::endl; // LOGICAL ERROR: Should print author
        std::cout << "ISBN: " << isbn << std::endl; // LOGICAL ERROR: Prints ISBN again, author is skipped
    }
};

int main() {
    Book myBook("The Lord of the Rings", "J.R.R. Tolkien", "978-0618053267");
    myBook.displayDetails();
    return 0;
}