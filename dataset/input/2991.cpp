#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    // Helper function to check if a year is a leap year.
    // Marked const as it does not modify the object's state.
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    // Parameterized constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Public method to validate the date.
    // Marked const as it does not modify the object's state.
    bool isValidDate() const {
        // 1. Validate month: must be between 1 and 12.
        if (month < 1 || month > 12) {
            return false;
        }

        // 2. Validate day: must be positive.
        if (day < 1) {
            return false;
        }

        // 3. Determine the maximum number of days for the given month, considering leap years for February.
        int daysInMonth;
        switch (month) {
            case 2: // February
                daysInMonth = isLeapYear(year) ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11: // April, June, September, November (30 days)
                daysInMonth = 30;
                break;
            default: // January, March, May, July, August, October, December (31 days)
                daysInMonth = 31;
                break;
        }

        // 4. Validate day against the determined maximum days for the month.
        if (day > daysInMonth) {
            return false;
        }

        // If all checks pass, the date is valid.
        return true;
    }

    // Public getters to allow external access to private members for display, etc.
    // Marked const as they do not modify the object's state.
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

int main() {
    // Test cases for isValidDate()
    Date d1(15, 6, 2023);  // Valid date
    Date d2(31, 2, 2024);  // Invalid: February 2024 is a leap year (29 days max)
    Date d3(29, 2, 2024);  // Valid: February 2024 is a leap year
    Date d4(31, 4, 2023);  // Invalid: April has 30 days
    Date d5(0, 1, 2023);   // Invalid: Day cannot be 0
    Date d6(29, 2, 1900);  // Invalid: 1900 is not a leap year (divisible by 100 but not 400)
    Date d7(29, 2, 2000);  // Valid: 2000 is a leap year (divisible by 400)
    Date d8(1, 13, 2023);  // Invalid: Month out of range
    Date d9(32, 1, 2023);  // Invalid: January has 31 days max
    Date d10(-5, 5, 2023); // Invalid: Day cannot be negative
    Date d11(1, -2, 2023); // Invalid: Month cannot be negative

    std::cout << "Date " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << " is " << (d1.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << " is " << (d2.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << " is " << (d3.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d4.getDay() << "/" << d4.getMonth() << "/" << d4.getYear() << " is " << (d4.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d5.getDay() << "/" << d5.getMonth() << "/" << d5.getYear() << " is " << (d5.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d6.getDay() << "/" << d6.getMonth() << "/" << d6.getYear() << " is " << (d6.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d7.getDay() << "/" << d7.getMonth() << "/" << d7.getYear() << " is " << (d7.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d8.getDay() << "/" << d8.getMonth() << "/" << d8.getYear() << " is " << (d8.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d9.getDay() << "/" << d9.getMonth() << "/" << d9.getYear() << " is " << (d9.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d10.getDay() << "/" << d10.getMonth() << "/" << d10.getYear() << " is " << (d10.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d11.getDay() << "/" << d11.getMonth() << "/" << d11.getYear() << " is " << (d11.isValidDate() ? "valid" : "invalid") << std::endl;

    return 0;
}