#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // This helper function is defined but not used in isValidDate, leading to redundant logic.
    bool isLeapYearVerbose() const {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    bool isValidDate() const {
        // Correctness: This implementation is functionally correct.
        // Readability/Efficiency: Suffers from verbose and repetitive logic.

        if (month < 1 || month > 12) {
            return false; // Month out of range
        }

        if (day < 1) { // Explicitly check day > 0
            return false;
        }

        int maxDays;

        // Overly verbose and repetitive if-else if chain for days in month
        if (month == 1) { // January
            maxDays = 31;
        } else if (month == 2) { // February
            // Repetitive and verbose leap year calculation directly embedded
            bool isCurrentYearLeap = false;
            if (year % 4 == 0) {
                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        isCurrentYearLeap = true;
                    } else {
                        isCurrentYearLeap = false;
                    }
                } else {
                    isCurrentYearLeap = true;
                }
            } else {
                isCurrentYearLeap = false;
            }
            maxDays = isCurrentYearLeap ? 29 : 28;
        } else if (month == 3) { // March
            maxDays = 31;
        } else if (month == 4) { // April
            maxDays = 30;
        } else if (month == 5) { // May
            maxDays = 31;
        } else if (month == 6) { // June
            maxDays = 30;
        } else if (month == 7) { // July
            maxDays = 31;
        } else if (month == 8) { // August
            maxDays = 31;
        } else if (month == 9) { // September
            maxDays = 30;
        } else if (month == 10) { // October
            maxDays = 31;
        } else if (month == 11) { // November
            maxDays = 30;
        } else if (month == 12) { // December
            maxDays = 31;
        } else {
            // This else branch is technically unreachable due to the initial month validation,
            // but its presence adds unnecessary verbosity and complexity.
            return false;
        }

        if (day > maxDays) {
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
    Date d5(0, 1, 2023);  // Invalid (day < 1)
    Date d6(29, 2, 1900); // Invalid (1900 not leap year)
    Date d7(29, 2, 2000); // Valid (2000 is leap year)
    Date d8(1, 13, 2023); // Invalid (month > 12)
    Date d9(32, 1, 2023); // Invalid (day > 31)

    std::cout << "Date " << d1.getDay() << "/" << d1.getMonth() << "/" << d1.getYear() << " is " << (d1.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d2.getDay() << "/" << d2.getMonth() << "/" << d2.getYear() << " is " << (d2.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d3.getDay() << "/" << d3.getMonth() << "/" << d3.getYear() << " is " << (d3.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d4.getDay() << "/" << d4.getMonth() << "/" << d4.getYear() << " is " << (d4.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d5.getDay() << "/" << d5.getMonth() << "/" << d5.getYear() << " is " << (d5.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d6.getDay() << "/" << d6.getMonth() << "/" << d6.getYear() << " is " << (d6.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d7.getDay() << "/" << d7.getMonth() << "/" << d7.getYear() << " is " << (d7.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d8.getDay() << "/" << d8.getMonth() << "/" << d8.getYear() << " is " << (d8.isValidDate() ? "valid" : "invalid") << std::endl;
    std::cout << "Date " << d9.getDay() << "/" << d9.getMonth() << "/" << d9.getYear() << " is " << (d9.isValidDate() ? "valid" : "invalid") << std::endl;

    return 0;
}