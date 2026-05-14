#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

int main() {
    Book library[3];

    // Populate books
    library[0].title = "The Hitchhiker's Guide to the Galaxy";
    library[0].author = "Douglas Adams";
    library[0].publicationYear = 1979;

    library[1].title = "Pride and Prejudice";
    library[1].author = "Jane Austen";
    library[1].publicationYear = 1813;

    library[2].title = "1984";
    library[2].author = "George Orwell";
    library[2].publicationYear = 1949;

    // Logical Error: The loop iterates only 2 times instead of 3,
    // so the details of the third book are not printed.
    for (int i = 0; i < 2; ++i) { // Should be i < 3
        std::cout << "Book " << i + 1 << ":\n";
        std::cout << "  Title: " << library[i].title << "\n";
        std::cout << "  Author: " << library[i].author << "\n";
        std::cout << "  Year: " << library[i].publicationYear << "\n";
        std::cout << "\n";
    }

    return 0;
}