#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValidDate() {
        // Robustness issue 1: Does not explicitly check for day <= 0.
        // If day is 0 or negative, it will be considered valid as long as day <= daysInMonth.
        // For example, Date(0, 1, 2023) would be considered valid if day is only checked against daysInMonth.

        // Robustness issue 2: Simplified leap year check.
        // This check `(year % 4 == 0)` is incorrect for years divisible by 100 but not by 400 (e.g., 1900).
        // It incorrectly classifies such years as leap years.
        bool isLeap = (year % 4 == 0);

        if (month < 1 || month > 12) {
            return false;
        }

        int daysInMonth;
        switch (month) {
            case 2: // February
                daysInMonth = isLeap ? 29 : 28;
                break;
            case 4: case 6: case 9: case 11: // April, June, September, November
                daysInMonth = 30;
                break;
            default: // January, March, May, July, August, October, December
                daysInMonth = 31;
                break;
        }

        // Only checks upper bound for day. Fails to check day > 0.
        if (day > daysInMonth) {
            return false;
        }

        return true;
    }

    // Public getters for driver to access private members for printing
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

int main() {
    Date d1(15, 6, 2023); // Valid
    Date d2(31, 2, 2024); // Invalid (Feb 2024 is leap, has 29 days)
    Date d3(29, 2, 2024); // Valid (Leap year)
    Date d4(31, 4, 2023); // Invalid (April has 30 days)
    Date d5(0, 1, 2023);  // Expected: Invalid (day <= 0). Actual: Valid due to robustness issue.
    Date d6(29, 2, 1900); // Expected: Invalid (1900 not leap year). Actual: Valid due to leap year flaw.
    Date d7(29, 2, 2000); // Expected: Valid (2000 is leap year). Actual: Valid.
    Date d8(1, 13, 2023); // Invalid (month > 12)

    std::cout << "Date " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << " is " << (d1.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << " is " << (d2.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << " is " << (d3.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d4.getDay() << "/" << d4.getMonth() << "/" << d4.getYear() << " is " << (d4.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d5.getDay() << "/" << d5.getMonth() << "/" << d5.getYear() << " is " << (d5.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d6.getDay() << "/" << d6.getMonth() << "/" << d6.getYear() << " is " << (d6.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d7.getDay() << "/" << d7.getMonth() << "/" << d7.getYear() << " is " << (d7.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d8.getDay() << "/" << d8.getMonth() << "/" << d8.getYear() << " is " << (d8.isValidDate() ? "valid" : "invalid") << std::endl;

    return 0;
}