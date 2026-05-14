#include <iostream>
#include <string>
#include <iomanip> // This header is included, but its features for padding are not used for the error.

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValidDate() {
        if (year < 1 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (isLeap) {
                daysInMonth[2] = 29;
            }
        }

        if (day > daysInMonth[month]) {
            return false;
        }
        return true;
    }

    void displayDate() {
        // SEMANTIC ERROR: This implementation does not use leading zeros for single-digit
        // day and month, violating the 'DD/MM/YYYY' format requirement semantically.
        std::cout << day << "/" << month << "/" << year;
        // Correct implementation would be:
        // std::cout << std::setfill('0') << std::setw(2) << day << "/"
        //           << std::setfill('0') << std::setw(2) << month << "/"
        //           << year;
    }
};

int main() {
    // This main function is for local testing and will not be used by the JSON driver.
    Date d1(1, 1, 2023); // Should display 01/01/2023
    std::cout << "1/1/2023 display (expected 01/01/2023, actual "; d1.displayDate(); std::cout << ")" << std::endl;
    Date d2(9, 10, 2025); // Should display 09/10/2025
    std::cout << "9/10/2025 display (expected 09/10/2025, actual "; d2.displayDate(); std::cout << ")" << std::endl;
    Date d3(15, 7, 1999); // Should display 15/07/1999
    std::cout << "15/7/1999 display (expected 15/07/1999, actual "; d3.displayDate(); std::cout << ")" << std::endl;
    return 0;
}