#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {
        // Basic validation in constructor to ensure initial state is somewhat valid
        if (y <= 0) { year = 2000; std::cout << "Warning: Invalid initial year. Setting to 2000.\n"; }
        if (m < 1 || m > 12) { month = 1; std::cout << "Warning: Invalid initial month. Setting to 1.\n"; }
        // Day validation in constructor is also basic, not fully robust
        if (d < 1 || d > 31) { day = 1; std::cout << "Warning: Invalid initial day. Setting to 1.\n"; }
    }

    void setDay(int newDay) {
        // Robustness issue: Only checks a generic 1-31 range,
        // does not consider the actual month or leap year.
        if (newDay >= 1 && newDay <= 31) {
            day = newDay;
        } else {
            std::cout << "Error: Invalid day " << newDay << ". Day must be between 1 and 31.\n";
        }
    }

    void setMonth(int newMonth) {
        // Robustness issue: Only checks month range,
        // does NOT re-validate if the current 'day' is valid for the new month.
        if (newMonth >= 1 && newMonth <= 12) {
            month = newMonth;
        } else {
            std::cout << "Error: Invalid month " << newMonth << ". Month must be between 1 and 12.\n";
        }
    }

    void setYear(int newYear) {
        if (newYear > 0) {
            year = newYear;
        } else {
            std::cout << "Error: Invalid year " << newYear << ". Year must be positive.\n";
        }
    }

    void displayDate() const {
        std::cout << day << "/" << month << "/" << year << "\n";
    }
};

int main() {
    Date d(15, 6, 2023);
    std::cout << "Initial date: ";
    d.displayDate();

    std::cout << "\n--- Testing Robustness Issues ---\n";

    // Scenario 1: Set day that is invalid for current month (Feb)
    std::cout << "Attempting to set month to February (2) and then day to 30:\n";
    d.setMonth(2); // Sets month to 2
    d.setDay(30);  // Robustness issue: This will succeed because setDay only checks 1-31.
    std::cout << "Date after setting month to 2 and day to 30: ";
    d.displayDate(); // Expected: 30/2/2023 (INVALID DATE, but allowed by this code)

    std::cout << "\nAttempting to set day to 29 in a non-leap year (2023):\n";
    d.setYear(2023); // Set year to non-leap
    d.setMonth(2);   // Set month to February
    d.setDay(29);    // Robustness issue: This will succeed.
    std::cout << "Date after setting year to 2023, month to 2, day to 29: ";
    d.displayDate(); // Expected: 29/2/2023 (INVALID DATE, but allowed by this code)

    // Scenario 2: Set day to 31, then change month to one with fewer days (April)
    std::cout << "\nAttempting to set day to 31, then month to April (4):\n";
    d.setYear(2024); // Reset to a valid year
    d.setMonth(1);   // Set to January (31 days)
    d.setDay(31);    // Set day to 31 (valid for Jan)
    std::cout << "Date after setting to 31/1/2024: ";
    d.displayDate(); // Expected: 31/1/2024
    d.setMonth(4);   // Robustness issue: This will succeed, but day 31 is invalid for April.
    std::cout << "Date after setting month to 4: ";
    d.displayDate(); // Expected: 31/4/2024 (INVALID DATE, but allowed by this code)

    std::cout << "\n--- Testing other invalid inputs (should be caught by basic validation) ---\n";
    d.setYear(-100); // Invalid year
    d.displayDate(); // Expected: 31/4/2024 (year not updated)
    d.setMonth(0);   // Invalid month
    d.displayDate(); // Expected: 31/4/2024 (month not updated)
    d.setDay(0);     // Invalid day
    d.displayDate(); // Expected: 31/4/2024 (day not updated)

    return 0;
}