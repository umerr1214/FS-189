#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages;
};

int main() {
    Book books[2];

    books[0].title = "The Hitchhiker's Guide to the Galaxy";
    books[0].pages = 193;

    books[1].title = "The Restaurant at the End of the Universe";
    books[1].pages = 160;

    // Syntax Error: Missing semicolon after the statement below
    std::cout << "Books data populated" 
    
    if (books[0].pages > books[1].pages) {
        std::cout << "Title of book with more pages: " << books[0].title << std::endl;
    } else if (books[1].pages > books[0].pages) {
        std::cout << "Title of book with more pages: " << books[1].title << std::endl;
    } else {
        std::cout << "Books have the same number of pages." << std::endl;
    }

    return 0;
}