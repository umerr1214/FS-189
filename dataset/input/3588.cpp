#include <iostream>
#include <string>

int main() {
    int day_num; // Input is an integer
    std::cout << "Enter a day number (1-7): ";
    std::cin >> day_num;

    char day_char = day_num; // Semantic issue: implicit conversion from int to char.
                             // For day numbers 1-7, day_char will hold the integer value 1-7.

    switch (day_char) { // Switching on a char variable
        case '1': // Semantic issue: This case label is a char literal ('1'), which has an ASCII value of 49.
                  // It will only match if day_char holds the value 49, not the integer 1.
            std::cout << "Monday\n";
            break;
        case '2': // Matches if day_char is ASCII '2' (value 50)
            std::cout << "Tuesday\n";
            break;
        case '3': // Matches if day_char is ASCII '3' (value 51)
            std::cout << "Wednesday\n";
            break;
        case '4': // Matches if day_char is ASCII '4' (value 52)
            std::cout << "Thursday\n";
            break;
        case '5': // Matches if day_char is ASCII '5' (value 53)
            std::cout << "Friday\n";
            break;
        case '6': // Matches if day_char is ASCII '6' (value 54)
            std::cout << "Saturday\n";
            break;
        case '7': // Matches if day_char is ASCII '7' (value 55)
            std::cout << "Sunday\n";
            break;
        default:
            std::cout << "Invalid day number or unhandled case\n";
            break;
    }

    return 0;
}