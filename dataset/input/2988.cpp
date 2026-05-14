#include <iostream>
#include <vector>
#include <string>
#include <limits> // For debugging potentially uninitialized values

class Date {
private:
    int day;
    int month;
    int year;

public:
    // SEMANTIC ERROR: Constructor parameters shadow member variables.
    // Assignments like `day = day;` assign the parameter to itself,
    // leaving the member variables (`this->day`, `this->month`, `this->year`) uninitialized.
    // Accessing them later will lead to undefined behavior.
    Date(int day, int month, int year) {
        // These assignments are effectively no-ops for the member variables.
        day = day;
        month = month;
        year = year;
        // The member variables 'this->day', 'this->month', 'this->year' remain uninitialized.
    }

    // Getters for testing (will return garbage if members are uninitialized)
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool isValidDate() {
        // Accessing uninitialized member variables here leads to undefined behavior.
        // The comparisons will operate on garbage values.
        if (year < 1 || month < 1 || month > 12 || day < 1) {
            return false;
        }

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Correct leap year logic (but operating on garbage 'year')
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap) {
            daysInMonth[2] = 29;
        }

        if (day > daysInMonth[month]) { // Operating on garbage 'day' and 'month'
            return false;
        }

        return true;
    }
};

int main() {
    // This main function is minimal for the C++ file, the comprehensive driver is in JSON.
    // Due to the semantic error, the Date object will be constructed with uninitialized members.
    // Calling isValidDate() will operate on these garbage values, leading to unpredictable results.
    Date d_test(15, 6, 2023); // Attempt to create a valid date

    std::cout << "Attempting to validate date (values might be garbage): " << d_test.getDay() << "/"
              << d_test.getMonth() << "/" << d_test.getYear() << std::endl;
    // The printed values here will likely be garbage.

    if (d_test.isValidDate()) {
        std::cout << "isValidDate() returned true (unpredictable due to uninitialized members)." << std::endl;
    } else {
        std::cout << "isValidDate() returned false (unpredictable due to uninitialized members)." << std::endl;
    }

    // Another example
    Date d_invalid(32, 1, 2023); // Attempt to create an invalid date
    std::cout << "Attempting to validate date (values might be garbage): " << d_invalid.getDay() << "/"
              << d_invalid.getMonth() << "/" << d_invalid.getYear() << std::endl;
    if (d_invalid.isValidDate()) {
        std::cout << "isValidDate() returned true (unpredictable due to uninitialized members)." << std::endl;
    } else {
        std::cout << "isValidDate() returned false (unpredictable due to uninitialized members)." << std::endl;
    }

    return 0;
}