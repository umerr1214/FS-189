#include <iostream>
#include <string>
#include <array>
#include <algorithm>

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        if (m < 1 || m > 12) return 0;
        std::array<int, 13> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeap(y)) return 29;
        return days[m];
    }

public:
    Date() : day(1), month(1), year(2000) {}

    void setDay(int d) {
        // LOGICAL ERROR: Incorrect validation, always allows up to 31 days regardless of month.
        // It should use daysInMonth(month, year) for proper validation.
        if (d >= 1 && d <= 31) { // This check is too permissive
            day = d;
        } else {
            std::cout << "Error: Invalid day " << d << ". Day not updated." << std::endl;
        }
    }

    void setMonth(int m) {
        // LOGICAL ERROR: Allows month 0, which is outside the valid range 1-12.
        if (m >= 0 && m <= 12) { // Should be m >= 1
            month = m;
            // No day adjustment logic here, which is fine for showing the month error.
            // Even if day adjustment was present, the fundamental month validation is flawed.
        } else {
            std::cout << "Error: Invalid month " << m << ". Month must be between 1 and 12. Month not updated." << std::endl;
        }
    }

    void setYear(int y) {
        if (y > 0) {
            year = y;
            // No day adjustment logic here, which is fine for showing the year error.
            // The logical error primarily targets setDay and setMonth for demonstration.
        } else {
            std::cout << "Error: Invalid year " << y << ". Year must be positive. Year not updated." << std::endl;
        }
    }

    std::string getDateString() const {
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }

    void printDate() const {
        std::cout << "Date: " << getDateString() << std::endl;
    }
};

int main() {
    // Test Case 1: Valid Date
    Date date1;
    std::cout << "Test 1 - Valid Date" << std::endl;
    std::cout << "Initial Date: " << date1.getDateString() << std::endl;
    date1.setYear(2023);
    date1.setMonth(6);
    date1.setDay(15);
    std::cout << "Final Date: " << date1.getDateString() << std::endl << std::endl;

    // Test Case 2: Invalid Day for Feb
    Date date2;
    std::cout << "Test 2 - Invalid Day for Feb" << std::endl;
    std::cout << "Initial Date: " << date2.getDateString() << std::endl;
    date2.setYear(2023);
    date2.setMonth(2);
    date2.setDay(30); // Invalid for Feb 2023 (should be max 28), but accepted due to logical error
    std::cout << "Final Date: " << date2.getDateString() << std::endl << std::endl;

    // Test Case 3: Invalid Month
    Date date3;
    std::cout << "Test 3 - Invalid Month" << std::endl;
    std::cout << "Initial Date: " << date3.getDateString() << std::endl;
    date3.setYear(2023);
    date3.setMonth(0); // Invalid month (should be 1-12), but accepted due to logical error
    date3.setDay(15);
    std::cout << "Final Date: " << date3.getDateString() << std::endl << std::endl;

    // Test Case 4: Invalid Year
    Date date4;
    std::cout << "Test 4 - Invalid Year" << std::endl;
    std::cout << "Initial Date: " << date4.getDateString() << std::endl;
    date4.setYear(-1); // Invalid year (correctly rejected)
    date4.setMonth(6);
    date4.setDay(15);
    std::cout << "Final Date: " << date4.getDateString() << std::endl << std::endl;

    // Test Case 5: Leap Year Day Adjustment (set day 29, then year 2024)
    Date date5;
    std::cout << "Test 5 - Leap Year Day Adjustment" << std::endl;
    std::cout << "Initial Date: " << date5.getDateString() << std::endl;
    date5.setMonth(2);
    date5.setDay(28); // Start with valid day
    date5.setYear(2024); // Make it a leap year
    date5.setDay(29); // Now set to valid leap day
    std::cout << "Final Date: " << date5.getDateString() << std::endl << std::endl;

    // Test Case 6: Non-Leap Year Day Adjustment (set day 29, then year 2023)
    Date date6;
    std::cout << "Test 6 - Non-Leap Year Day Adjustment" << std::endl;
    std::cout << "Initial Date: " << date6.getDateString() << std::endl;
    date6.setMonth(2);
    date6.setDay(29); // Set an invalid day for 2023 (should be max 28), but accepted due to logical error
    date6.setYear(2023); // Make it non-leap
    std::cout << "Final Date: " << date6.getDateString() << std::endl << std::endl;

    return 0;
}