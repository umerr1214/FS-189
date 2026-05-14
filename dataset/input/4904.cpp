#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int publicationYear;
};

int main() {
    Book books[3]; // Declare an array of three Book structs

    std::cout << "Enter details for three books:\n";

    // Readability / Efficiency Issue: Highly repetitive code, no loops used.
    // Also, using `cin >> string` for title/author, which only reads a single word,
    // making it unsuitable for multi-word titles/authors and leading to incorrect data
    // if multi-word input is provided.

    // Book 1 Input
    std::cout << "\n--- Book 1 ---\n";
    std::cout << "Enter title for book 1 (single word): ";
    std::cin >> books[0].title;
    std::cout << "Enter author for book 1 (single word): ";
    std::cin >> books[0].author;
    std::cout << "Enter publication year for book 1: ";
    std::cin >> books[0].publicationYear;

    // Book 2 Input
    std::cout << "\n--- Book 2 ---\n";
    std::cout << "Enter title for book 2 (single word): ";
    std::cin >> books[1].title;
    std::cout << "Enter author for book 2 (single word): ";
    std::cin >> books[1].author;
    std::cout << "Enter publication year for book 2: ";
    std::cin >> books[1].publicationYear;

    // Book 3 Input
    std::cout << "\n--- Book 3 ---\n";
    std::cout << "Enter title for book 3 (single word): ";
    std::cin >> books[2].title;
    std::cout << "Enter author for book 3 (single word): ";
    std::cin >> books[2].author;
    std::cout << "Enter publication year for book 3: ";
    std::cin >> books[2].publicationYear;

    std::cout << "\n--- Details of all books ---\n";

    // Book 1 Output
    std::cout << "\nBook 1:\n";
    std::cout << "Title: " << books[0].title << "\n";
    std::cout << "Author: " << books[0].author << "\n";
    std::cout << "Publication Year: " << books[0].publicationYear << "\n";

    // Book 2 Output
    std::cout << "\nBook 2:\n";
    std::cout << "Title: " << books[1].title << "\n";
    std::cout << "Author: " << books[1].author << "\n";
    std::cout << "Publication Year: " << books[1].publicationYear << "\n";

    // Book 3 Output
    std::cout << "\nBook 3:\n";
    std::cout << "Title: " << books[2].title << "\n";
    std::cout << "Author: " << books[2].author << "\n";
    std::cout << "Publication Year: " << books[2].publicationYear << "\n";

    return 0;
}