#include <iostream>
#include <string>

std::string getCategory(char ch) {
    std::string category;
    if (ch >= 'A' && ch <= 'Z') { // Check for uppercase letter
        category = "Uppercase Letter";
    } else if (ch >= 'a' && ch <= 'z') { // Check for lowercase letter
        category = "Lowercase Letter";
    } else if (ch > '0' && ch < '9') { // Logical Error: This condition misses '0' and '9'
        category = "Digit";
    } else { // Otherwise, it's a special character (or '0', '9' due to the error)
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