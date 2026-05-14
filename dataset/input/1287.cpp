#include <iostream>
#include <string>
#include <vector> // Not strictly needed for this solution, but good for larger classes

class Date {
private:
    int _day;
    int _month;
    int _year;

    // Private helper: Checks if a given year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Private helper: Returns the maximum number of days for a given month and year
    int getDaysInMonth(int month, int year) const {
        if (month < 1 || month > 12) {
            return 0; // Invalid month
        }
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    // Private helper: Checks if a combination of day, month, year forms a valid date
    bool isValidDate(int d, int m, int y) const {
        if (y <= 0) return false;
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > getDaysInMonth(m, y)) return false;
        return true;
    }

public:
    // Constructor: Initializes the date. If inputs are invalid, sets to a default valid date (e.g., 2000-01-01).
    Date(int year = 2000, int month = 1, int day = 1) : _day(1), _month(1), _year(2000) {
        // Use setters for initial validation to ensure consistent state
        if (!setYear(year) || !setMonth(month) || !setDay(day)) {
            // If initial values are invalid, the date remains at default 2000-01-01
            // A more sophisticated approach might throw an exception or log an error.
            // For this problem, keeping the default is a robust fallback.
        }
    }

    // Setter for day: Validates the day against the current month and year.
    // Only updates if the new day is valid.
    bool setDay(int day) {
        if (isValidDate(day, _month, _year)) {
            _day = day;
            return true;
        }
        return false;
    }

    // Setter for month: Validates the month and ensures the day remains valid.
    // If changing month invalidates current day (e.g., Feb 31), day is adjusted to max valid day.
    bool setMonth(int month) {
        if (month < 1 || month > 12) {
            return false;
        }
        int originalMonth = _month;
        _month = month; // Temporarily change month to check new max days
        int maxDays = getDaysInMonth(_month, _year);

        if (_day > maxDays) {
            _day = maxDays; // Adjust day to be valid for the new month
        }
        return true;
    }

    // Setter for year: Validates the year and ensures the day remains valid.
    // If changing year invalidates current day (e.g., Feb 29 in non-leap year), day is adjusted.
    bool setYear(int year) {
        if (year <= 0) {
            return false;
        }
        int originalYear = _year;
        _year = year; // Temporarily change year to check new max days
        int maxDays = getDaysInMonth(_month, _year);

        if (_day > maxDays) {
            _day = maxDays; // Adjust day to be valid for the new year
        }
        return true;
    }

    // Getters
    int getDay() const { return _day; }
    int getMonth() const { return _month; }
    int getYear() const { return _year; }

    // Method to print the date in YYYY-MM-DD format
    void printDate() const {
        std::cout << _year << "-"
                  << (_month < 10 ? "0" : "") << _month << "-"
                  << (_day < 10 ? "0" : "") << _day;
    }
};

int main() {
    Date d1(2023, 1, 15);
    std::cout << "d1 initial: "; d1.printDate(); std::cout << " (Expected: 2023-01-15)\n";

    // Test valid setters
    d1.setMonth(2); // Valid month
    std::cout << "d1 after setMonth(2): "; d1.printDate(); std::cout << " (Expected: 2023-02-15)\n";

    d1.setDay(28); // Valid day for Feb 2023
    std::cout << "d1 after setDay(28): "; d1.printDate(); std::cout << " (Expected: 2023-02-28)\n";

    d1.setYear(2024); // Change to leap year
    std::cout << "d1 after setYear(2024): "; d1.printDate(); std::cout << " (Expected: 2024-02-28)\n"; // Day was 28, remains 28

    d1.setDay(29); // Valid day for Feb 2024 (leap year)
    std::cout << "d1 after setDay(29): "; d1.printDate(); std::cout << " (Expected: 2024-02-29)\n";

    // Test invalid setters
    bool success = d1.setDay(30); // Invalid day for Feb
    std::cout << "d1 setDay(30) success: " << (success ? "true" : "false") << ", date: "; d1.printDate(); std::cout << " (Expected: false, 2024-02-29)\n";

    success = d1.setMonth(13); // Invalid month
    std::cout << "d1 setMonth(13) success: " << (success ? "true" : "false") << ", date: "; d1.printDate(); std::cout << " (Expected: false, 2024-02-29)\n";

    success = d1.setYear(-100); // Invalid year
    std::cout << "d1 setYear(-100) success: " << (success ? "true" : "false") << ", date: "; d1.printDate(); std::cout << " (Expected: false, 2024-02-29)\n";

    // Test month/year changes that affect day
    Date d2(2023, 3, 31); // March 31st
    std::cout << "d2 initial: "; d2.printDate(); std::cout << " (Expected: 2023-03-31)\n";
    d2.setMonth(4); // Change to April (only 30 days)
    std::cout << "d2 after setMonth(4): "; d2.printDate(); std::cout << " (Expected: 2023-04-30)\n"; // Day adjusted from 31 to 30

    Date d3(2024, 2, 29); // Feb 29th, leap year
    std::cout << "d3 initial: "; d3.printDate(); std::cout << " (Expected: 2024-02-29)\n";
    d3.setYear(2023); // Change to non-leap year
    std::cout << "d3 after setYear(2023): "; d3.printDate(); std::cout << " (Expected: 2023-02-28)\n"; // Day adjusted from 29 to 28

    // Test constructor with invalid values
    Date d4(0, 0, 0); // All invalid
    std::cout << "d4 invalid constructor: "; d4.printDate(); std::cout << " (Expected: 2000-01-01)\n";

    Date d5(2023, 2, 30); // Invalid day for Feb
    std::cout << "d5 invalid constructor (day): "; d5.printDate(); std::cout << " (Expected: 2023-02-28)\n"; // Day adjusted

    return 0;
}