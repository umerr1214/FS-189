#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    // Logical Error: Incorrect leap year calculation
    // This function incorrectly marks years divisible by 100 but not 400 (e.g., 1900, 2100) as leap years.
    bool isLeap(int y) const {
        return (y % 4 == 0); // Should also include (y % 100 != 0 || y % 400 == 0)
    }

    int daysInMonth(int m, int y) const {
        if (m < 1 || m > 12) return 0; // Invalid month
        switch (m) {
            case 2: return isLeap(y) ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(1), month(1), year(2000) {
        // Setters are called in a specific order for robust validation
        // (year first, then month, then day, as day/month validation depends on year)
        if (!setYear(y)) { /* std::cerr << "Constructor: Invalid initial year " << y << ". Keeping default." << std::endl; */ }
        if (!setMonth(m)) { /* std::cerr << "Constructor: Invalid initial month " << m << ". Keeping default." << std::endl; */ }
        if (!setDay(d)) { /* std::cerr << "Constructor: Invalid initial day " << d << ". Keeping default." << std::endl; */ }
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool setDay(int d) {
        if (d >= 1 && d <= daysInMonth(month, year)) {
            day = d;
            return true;
        }
        return false;
    }

    bool setMonth(int m) {
        if (m >= 1 && m <= 12) {
            // Check if current day is valid for the new month
            if (day <= daysInMonth(m, year)) {
                month = m;
                return true;
            }
        }
        return false;
    }

    bool setYear(int y) {
        if (y >= 1900 && y <= 2100) { // Arbitrary reasonable year range
            // Check if current day/month is valid for the new year (e.g., Feb 29 in a non-leap year)
            if (day <= daysInMonth(month, y)) {
                year = y;
                return true;
            }
        }
        return false;
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    std::cout << "Testing Date class with Logical Error (incorrect leap year check):" << std::endl;

    // Year 1900 is NOT a leap year (divisible by 100 but not 400).
    // Our 'isLeap' will incorrectly mark it as a leap year, allowing 29/2/1900.
    Date d_1900(29, 2, 1900); // Should be invalid, but will be set due to error
    std::cout << "Date(29, 2, 1900): ";
    d_1900.display(); // Expected: 1/1/2000 (if handled correctly), Actual: 29/2/1900

    // Year 2000 IS a leap year (divisible by 400). This case will work correctly.
    Date d_2000(29, 2, 2000);
    std::cout << "Date(29, 2, 2000): ";
    d_2000.display();

    // Year 2100 is NOT a leap year (divisible by 100 but not 400).
    // Our 'isLeap' will incorrectly mark it as a leap year, allowing 29/2/2100.
    Date d_2100(29, 2, 2100); // Should be invalid, but will be set due to error
    std::cout << "Date(29, 2, 2100): ";
    d_2100.display(); // Expected: 1/1/2000 (if handled correctly), Actual: 29/2/2100

    Date testDate;
    std::cout << "Initial date: ";
    testDate.display(); // 1/1/2000

    // Try to set 29 Feb 1900 - should fail, but will succeed due to logical error
    std::cout << "Attempting to set 29/2/1900 (should be invalid): ";
    if (testDate.setYear(1900) && testDate.setMonth(2) && testDate.setDay(29)) {
        std::cout << "set(29, 2, 1900) succeeded (LOGICAL ERROR): ";
    } else {
        std::cout << "set(29, 2, 1900) failed (CORRECT BEHAVIOR): ";
    }
    testDate.display(); // Will display 29/2/1900, which is incorrect

    return 0;
}