#include <iostream>
#include <string>
#include <cctype> // For isupper, islower, isdigit

std::string getCategory(char ch) {
    std::string category;
    if (std::isupper(ch)) {
        category = "Uppercase Letter";
    } else if (std::islower(ch)) {
        category = "Lowercase Letter";
    } else if (std::isdigit(ch)) {
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
    std::string category = getCategory(ch);
    // Syntax Error: Missing semicolon here
    std::cout << "Category: " << category << std::endl
    
    return 0;
}