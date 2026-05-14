#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Getters for testing
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool isValidDate() {
        if (year < 1 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap) {
            daysInMonth[2] = 29;
        }

        if (day > daysInMonth[month]) {
            return false;
        }

        return true;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // This main function is minimal as the primary focus is the Date class with the syntax error.
    // The driver in the JSON will be more comprehensive.
    // This code will not compile due to the missing semicolon after the class definition.
    Date d(29, 2, 2023); // Should be invalid
    if (d.isValidDate()) {
        std::cout << "Date 29/2/2023 is valid (incorrect)." << std::endl;
    } else {
        std::cout << "Date 29/2/2023 is invalid (correct)." << std::endl;
    }

    Date d2(29, 2, 2024); // Should be valid
    if (d2.isValidDate()) {
        std::cout << "Date 29/2/2024 is valid (correct)." << std::endl;
    } else {
        std::cout << "Date 29/2/2024 is invalid (incorrect)." << std::endl;
    }
    return 0;
}