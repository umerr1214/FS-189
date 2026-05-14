#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages;
};

int main() {
    Book books[2]; // Array of size 2, valid indices are 0 and 1

    books[0].title = "The Hitchhiker's Guide to the Galaxy";
    books[0].pages = 193;

    books[1].title = "The Restaurant at the End of the Universe";
    books[1].pages = 193; // Set pages to be equal to trigger the semantic error path

    Book* chosenBook = nullptr;

    if (books[0].pages > books[1].pages) {
        chosenBook = &books[0];
    } else if (books[1].pages > books[0].pages) {
        chosenBook = &books[1];
    } else { // This path will be taken because pages are equal
        // Semantic Error: Dereferencing an uninitialized pointer
        Book* uninitializedPtr; // Declared but not initialized
        // Attempt to access a member of uninitializedPtr, leading to undefined behavior
        std::cout << "Books have the same number of pages. Attempting to access title from uninitialized pointer: " << uninitializedPtr->title << std::endl;
        // The program will likely crash here or print garbage due to undefined behavior.
        return 1; // Indicate an error exit
    }

    if (chosenBook) {
        std::cout << "Title of book with more pages: " << chosenBook->title << std::endl;
    }

    return 0;
}