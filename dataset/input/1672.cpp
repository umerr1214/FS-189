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
        std::cout << std::setfill('0') << std::setw(2) << day << "/"
                  << std::setfill('0') << std::setw(2) << month << "/"
                  << year;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    // This main function is for local testing and will not be used by the JSON driver.
    // The missing semicolon above will cause a compilation error.
    Date d1(1, 1, 2023);
    d1.displayDate();
    std::cout << std::endl;
    return 0;
}