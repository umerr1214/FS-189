#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but good practice for helper functions if they were more complex

class Date {
private:
    int _day;
    int _month;
    int _year;

    // Helper function (partially robust, but main issue is in setter usage)
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // This helper is not fully utilized by setDay, leading to robustness issue
    int getDaysInMonth(int month, int year) const {
        if (month < 1 || month > 12) return 0; // Invalid month
        if (month == 2) {
            return isLeapYear(year) ? 29 : 28;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        } else {
            return 31;
        }
    }

public:
    // Constructor: Initializes to a default valid date and then tries to set
    Date(int year = 2000, int month = 1, int day = 1) : _year(2000), _month(1), _day(1) {
        // Setters are called in an order that minimizes temporary invalid states
        // but the setDay itself has a robustness flaw in this version.
        setYear(year);
        setMonth(month);
        setDay(day);
    }

    // Setter for day: Robustness issue here. Only checks 1-31, not month-specific.
    // It allows days like Feb 30th or April 31st if the month is already set.
    bool setDay(int day) {
        if (day >= 1 && day <= 31) { // FLAW: This check is too generic.
            _day = day;
            return true;
        }
        return false;
    }

    // Setter for month: Basic validation
    bool setMonth(int month) {
        if (month >= 1 && month <= 12) {
            _month = month;
            // FLAW: Does not re-validate _day if _day becomes invalid for the new month.
            // e.g., if _day was 31 and month changes to 2 (February), _day remains 31.
            return true;
        }
        return false;
    }

    // Setter for year: Basic validation
    bool setYear(int year) {
        if (year > 0) { // Simple positive year check
            _year = year;
            // FLAW: Does not re-validate _day if _day was 29 and year changes from leap to non-leap.
            return true;
        }
        return false;
    }

    // Getters
    int getDay() const { return _day; }
    int getMonth() const { return _month; }
    int getYear() const { return _year; }

    // Method to print the date
    void printDate() const {
        std::cout << _year << "-"
                  << (_month < 10 ? "0" : "") << _month << "-"
                  << (_day < 10 ? "0" : "") << _day;
    }
};

int main() {
    Date d1(2023, 1, 15);
    std::cout << "d1 initial: "; d1.printDate(); std::cout << std::endl; // 2023-01-15

    d1.setMonth(2); // Set month to February
    d1.setDay(30);  // Try to set day to 30 (FLAW: allows it)
    std::cout << "d1 after Feb 30: "; d1.printDate(); std::cout << std::endl; // 2023-02-30 (incorrect)

    Date d2(2024, 4, 1);
    std::cout << "d2 initial: "; d2.printDate(); std::cout << std::endl; // 2024-04-01

    d2.setDay(31); // Try to set day to 31 for April (FLAW: allows it)
    std::cout << "d2 after Apr 31: "; d2.printDate(); std::cout << std::endl; // 2024-04-31 (incorrect)

    Date d3(2023, 1, 1);
    d3.setMonth(13); // Invalid month
    d3.setYear(-100); // Invalid year
    std::cout << "d3 invalid attempts: "; d3.printDate(); std::cout << std::endl; // 2023-01-01 (remains unchanged due to basic validation)

    Date d4(2024, 2, 29); // Leap year
    std::cout << "d4 initial (leap): "; d4.printDate(); std::cout << std::endl; // 2024-02-29
    d4.setYear(2023); // Change to non-leap year (FLAW: day remains 29)
    std::cout << "d4 after non-leap year: "; d4.printDate(); std::cout << std::endl; // 2023-02-29 (incorrect)

    return 0;
}