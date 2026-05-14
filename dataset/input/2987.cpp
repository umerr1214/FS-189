#include <iostream>
#include <vector>
#include <string>

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

        // LOGICAL ERROR: Incorrect leap year calculation.
        // This simplified check will incorrectly mark years like 1900, 2100 as leap years
        // because it only checks divisibility by 4, not the full leap year rule.
        bool isLeap = (year % 4 == 0); 
        if (isLeap) {
            daysInMonth[2] = 29;
        }

        if (day > daysInMonth[month]) {
            return false;
        }

        return true;
    }
};

int main() {
    // This main function is minimal for the C++ file, the comprehensive driver is in JSON.
    // This code compiles and runs, but isValidDate() has a logical error for certain years.
    Date d_1900_feb29(29, 2, 1900); // 1900 is NOT a leap year, but this logic will say it is.
    if (d_1900_feb29.isValidDate()) {
        std::cout << "Date 29/2/1900 is valid (INCORRECT)." << std::endl;
    } else {
        std::cout << "Date 29/2/1900 is invalid (correct)." << std::endl;
    }

    Date d_2000_feb29(29, 2, 2000); // 2000 IS a leap year, this logic will say it is.
    if (d_2000_feb29.isValidDate()) {
        std::cout << "Date 29/2/2000 is valid (correct)." << std::endl;
    } else {
        std::cout << "Date 29/2/2000 is invalid (incorrect)." << std::endl;
    }

    Date d_2023_feb29(29, 2, 2023); // 2023 is NOT a leap year, this logic will say it is not. (Correct)
    if (d_2023_feb29.isValidDate()) {
        std::cout << "Date 29/2/2023 is valid (incorrect)." << std::endl;
    } else {
        std::cout << "Date 29/2/2023 is invalid (correct)." << std::endl;
    }

    return 0;
}