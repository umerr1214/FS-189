#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages;
};

int main() {
    // Create an array of 2 Book structs
    Book library[2];

    // Populate their data to demonstrate the robustness issue (tie case)
    library[0].title = "Book Alpha";
    library[0].pages = 300;

    library[1].title = "Book Beta";
    library[1].pages = 300; // Pages are equal

    // Print the title of the book with more pages.
    // Robustness issue: If pages are equal, this logic will implicitly print library[1]'s title.
    // The question asks for "more pages", so if equal, neither has "more".
    // A robust solution would explicitly handle this tie or specify behavior.
    if (library[0].pages > library[1].pages) {
        std::cout << library[0].title << std::endl;
    } else { // This branch is executed if library[1].pages >= library[0].pages
        std::cout << library[1].title << std::endl;
    }

    return 0;
}