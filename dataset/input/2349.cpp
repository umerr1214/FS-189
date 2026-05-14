#include <iostream>
#include <string>

class Date {
private:
    int m_day;
    int m_month;
    int m_year;

    // Helper function to check if a year is a leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Helper function to get the number of days in a given month and year
    int getDaysInMonth(int month, int year) const {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(year) ? 29 : 28;
            default: return 0; // Invalid month, should not happen if month is validated beforehand
        }
    }

public:
    // Constructor
    Date(int day = 1, int month = 1, int year = 2000) : m_day(1), m_month(1), m_year(2000) {
        // Use setters to ensure initial state is valid and performs validation
        setYear(year);
        setMonth(month);
        setDay(day);
    }

    void setDay(int newDay) {
        int maxDays = getDaysInMonth(m_month, m_year);
        if (newDay >= 1 && newDay <= maxDays) {
            m_day = newDay;
        } else {
            std::cout << "Error: Invalid day " << newDay << ". Day must be between 1 and " << maxDays << " for " << m_month << "/" << m_year << ".\n";
        }
    }

    void setMonth(int newMonth) {
        if (newMonth >= 1 && newMonth <= 12) {
            // Check if current day is valid for the new month
            int maxDaysForNewMonth = getDaysInMonth(newMonth, m_year);
            if (m_day <= maxDaysForNewMonth) {
                m_month = newMonth;
            } else {
                std::cout << "Error: Cannot set month to " << newMonth << " because current day " << m_day << " is invalid for this month (" << maxDaysForNewMonth << " days).\n";
            }
        } else {
            std::cout << "Error: Invalid month " << newMonth << ". Month must be between 1 and 12.\n";
        }
    }

    void setYear(int newYear) {
        if (newYear > 0) {
            // If year changes, re-validate day for February if current month is February
            if (newYear != m_year && m_month == 2) {
                int daysInNewFeb = getDaysInMonth(2, newYear);
                if (m_day > daysInNewFeb) {
                    std::cout << "Error: Cannot set year to " << newYear << " because current day " << m_day << " is invalid for February in a " << (isLeapYear(newYear) ? "leap" : "non-leap") << " year.\n";
                    return; // Do not update year
                }
            }
            m_year = newYear;
        } else {
            std::cout << "Error: Invalid year " << newYear << ". Year must be positive.\n";
        }
    }

    void displayDate() const {
        std::cout << m_day << "/" << m_month << "/" << m_year << "\n";
    }
};

int main() {
    Date d(15, 6, 2023);
    std::cout << "Initial date: ";
    d.displayDate();

    std::cout << "\n--- Testing setYear ---\n";
    d.setYear(2024); // Valid (leap year)
    d.displayDate();
    d.setYear(-100); // Invalid year
    d.displayDate();

    std::cout << "\n--- Testing setMonth ---\n";
    d.setMonth(12); // Valid
    d.displayDate();
    d.setMonth(0);  // Invalid month
    d.displayDate();
    d.setMonth(13); // Invalid month
    d.displayDate();

    std::cout << "\n--- Testing setDay ---\n";
    d.setDay(1);   // Valid
    d.displayDate();
    d.setDay(31);  // Valid for Dec
    d.displayDate();
    d.setDay(32);  // Invalid
    d.displayDate();

    // Specific month/day scenarios
    std::cout << "\n--- Specific Month/Day Scenarios ---\n";
    Date d2(1, 1, 2023); // Non-leap year
    std::cout << "\nResetting date to: ";
    d2.displayDate();

    std::cout << "\nTesting setDay with February in non-leap year (2023):\n";
    d2.setMonth(2); // Set month to February
    d2.setDay(28);  // Valid
    d2.displayDate();
    d2.setDay(29);  // Invalid for 2023
    d2.displayDate();

    std::cout << "\nTesting setDay with February in leap year (2024):\n";
    d2.setYear(2024); // Set year to leap year
    d2.setMonth(2);   // Set month to February
    d2.setDay(29);    // Valid for 2024
    d2.displayDate();
    d2.setDay(30);    // Invalid for Feb
    d2.displayDate();

    std::cout << "\nTesting setDay with April (30 days):\n";
    d2.setMonth(4); // Set month to April
    d2.setDay(30);  // Valid
    d2.displayDate();
    d2.setDay(31);  // Invalid for April
    d2.displayDate();

    // Test year change affecting February
    std::cout << "\nTesting setYear affecting February:\n";
    Date d3(29, 2, 2024); // Start with Feb 29 in a leap year
    std::cout << "Initial d3: ";
    d3.displayDate();
    d3.setYear(2023); // Change to non-leap year (should fail)
    d3.displayDate();
    d3.setYear(2025); // Change to another non-leap year (should fail)
    d3.displayDate();
    d3.setYear(2028); // Change to another leap year (should succeed)
    d3.displayDate();

    // Test month change affecting day
    std::cout << "\nTesting setMonth affecting day:\n";
    d3.setDay(31); // Set day to 31 (valid for current month, if month is not Feb)
    d3.setMonth(1); // Set month to January (31 days)
    d3.displayDate();
    d3.setMonth(4); // Change to April (30 days) - should fail because day 31 is invalid
    d3.displayDate();
    d3.setDay(30); // Set day to 30
    d3.setMonth(4); // Change to April (30 days) - should succeed
    d3.displayDate();

    return 0;
}