#include <iostream>
#include <string>
#include <iomanip>

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
            // LOGICAL ERROR: This line incorrectly assumes 29 days for February,
            // regardless of whether the year is a leap year or not.
            daysInMonth[2] = 29; 
            // Correct logic would be:
            // bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            // if (isLeap) { daysInMonth[2] = 29; }
        }

        if (day > daysInMonth[month]) {
            return false;
        }
        return true;
    }

    void displayDate() {
        std::cout << std::setfill('0') << std::setw(2) << day << "/"
                  << std::setfill('0') << std::setw(2) << month << "/"
                  << year;
    }
};

int main() {
    // This main function is for local testing and will not be used by the JSON driver.
    Date d1(29, 2, 2023); // 2023 is not a leap year, should be invalid
    std::cout << "29/2/2023 is valid (expected false, actual " << (d1.isValidDate() ? "true" : "false") << ")" << std::endl;
    Date d2(29, 2, 2024); // 2024 is a leap year, should be valid
    std::cout << "29/2/2024 is valid (expected true, actual " << (d2.isValidDate() ? "true" : "false") << ")" << std::endl;
    Date d3(1, 1, 2023);
    d3.displayDate();
    std::cout << std::endl;
    return 0;
}