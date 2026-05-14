#include <iostream>
#include <string>

std::string getCategory(char ch) {
    std::string category;
    // Semantic Error: Using magic numbers (ASCII values) instead of character literals
    if (ch >= 65 && ch <= 90) { // 'A' (65) to 'Z' (90)
        category = "Uppercase Letter";
    } else if (ch >= 97 && ch <= 122) { // 'a' (97) to 'z' (122)
        category = "Lowercase Letter";
    } else if (ch >= 48 && ch <= 57) { // '0' (48) to '9' (57)
        category = "Digit";
    } else {
        category = "Special Character";
    }
    return category;
}

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;
    std::cout << "Category: " << getCategory(ch) << std::endl;
    return 0;
}