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
    // SEMANTIC ERROR: Default constructor does not initialize members.
    // This leads to undefined behavior when 'day', 'month', or 'year' are accessed
    // before being explicitly set by setters.
    Date() {} // Members day, month, year are uninitialized.

    void setDay(int d) {
        // Accessing uninitialized 'month' and 'year' here could lead to UB in daysInMonth
        int currentMaxDays = daysInMonth(month, year);
        if (d >= 1 && d <= currentMaxDays) {
            day = d;
        } else {
            std::cout << "Error: Invalid day " << d << " for month " << month << ", year " << year << ". Day not updated." << std::endl;
        }
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
            // Accessing uninitialized 'day' here could lead to UB in comparison
            int maxDays = daysInMonth(month, year);
            if (day > maxDays) {
                std::cout << "Warning: Day " << day << " is no longer valid for month " << month << ". Adjusting day to " << maxDays << "." << std::endl;
                day = maxDays;
            }
        } else {
            std::cout << "Error: Invalid month " << m << ". Month must be between 1 and 12. Month not updated." << std::endl;
        }
    }

    void setYear(int y) {
        if (y > 0) {
            year = y;
            // Accessing uninitialized 'day' and 'month' here could lead to UB
            int maxDays = daysInMonth(month, year);
            if (day > maxDays) {
                std::cout << "Warning: Day " << day << " is no longer valid for year " << year << ". Adjusting day to " << maxDays << "." << std::endl;
                day = maxDays;
            }
        } else {
            std::cout << "Error: Invalid year " << y << ". Year must be positive. Year not updated." << std::endl;
        }
    }

    std::string getDateString() const {
        // Accessing uninitialized 'month', 'day', 'year' here results in undefined behavior
        return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    }

    void printDate() const {
        std::cout << "Date: " << getDateString() << std::endl;
    }
};

int main() {
    // Test Case 1: Valid Date
    Date date1; // Members are uninitialized here!
    std::cout << "Test 1 - Valid Date" << std::endl;
    std::cout << "Initial Date: " << date1.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date1.setYear(2023);
    date1.setMonth(6);
    date1.setDay(15);
    std::cout << "Final Date: " << date1.getDateString() << std::endl << std::endl;

    // Test Case 2: Invalid Day for Feb
    Date date2; // Members are uninitialized here!
    std::cout << "Test 2 - Invalid Day for Feb" << std::endl;
    std::cout << "Initial Date: " << date2.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date2.setYear(2023);
    date2.setMonth(2);
    date2.setDay(30); // Invalid for Feb 2023
    std::cout << "Final Date: " << date2.getDateString() << std::endl << std::endl;

    // Test Case 3: Invalid Month
    Date date3; // Members are uninitialized here!
    std::cout << "Test 3 - Invalid Month" << std::endl;
    std::cout << "Initial Date: " << date3.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date3.setYear(2023);
    date3.setMonth(0); // Invalid month
    date3.setDay(15);
    std::cout << "Final Date: " << date3.getDateString() << std::endl << std::endl;

    // Test Case 4: Invalid Year
    Date date4; // Members are uninitialized here!
    std::cout << "Test 4 - Invalid Year" << std::endl;
    std::cout << "Initial Date: " << date4.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date4.setYear(-1); // Invalid year
    date4.setMonth(6);
    date4.setDay(15);
    std::cout << "Final Date: " << date4.getDateString() << std::endl << std::endl;

    // Test Case 5: Leap Year Day Adjustment (set day 29, then year 2024)
    Date date5; // Members are uninitialized here!
    std::cout << "Test 5 - Leap Year Day Adjustment" << std::endl;
    std::cout << "Initial Date: " << date5.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date5.setMonth(2);
    date5.setDay(28); // Start with valid day
    date5.setYear(2024); // Make it a leap year
    date5.setDay(29); // Now set to valid leap day
    std::cout << "Final Date: " << date5.getDateString() << std::endl << std::endl;

    // Test Case 6: Non-Leap Year Day Adjustment (set day 29, then year 2023)
    Date date6; // Members are uninitialized here!
    std::cout << "Test 6 - Non-Leap Year Day Adjustment" << std::endl;
    std::cout << "Initial Date: " << date6.getDateString() << std::endl; // UNDEFINED BEHAVIOR
    date6.setMonth(2);
    date6.setDay(29); // Set an invalid day initially (or valid for leap year)
    date6.setYear(2023); // Make it non-leap, day should adjust to 28
    std::cout << "Final Date: " << date6.getDateString() << std::endl << std::endl;

    return 0;
}