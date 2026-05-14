#include <iostream>
#include <string>

class Date {
private:
    int m_day;    // Inconsistent naming
    int _month;   // Inconsistent naming
    int currentYear; // Inconsistent naming

    // Helper function for leap year
    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    // Constructor
    Date(int d = 1, int m = 1, int y = 2000) : m_day(1), _month(1), currentYear(2000) {
        // Constructor uses setters to ensure initial state is valid
        setYear(y);
        setMonth(m);
        setDay(d); 
    }

    void setDay(int newDay) {
        // Readability/Efficiency Issue: Very verbose and repetitive logic for day validation.
        // Instead of a helper function or an array, it uses a long if-else if chain.
        if (newDay < 1 || newDay > 31) { // Basic range check
            std::cout << "Error: Invalid day " << newDay << ". Day must be between 1 and 31.\n";
            return;
        }

        int daysInCurrentMonth;
        if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
            daysInCurrentMonth = 31;
        } else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
            daysInCurrentMonth = 30;
        } else if (_month == 2) {
            if (isLeap(currentYear)) {
                daysInCurrentMonth = 29;
            } else {
                daysInCurrentMonth = 28;
            }
        } else {
            // This case should ideally not be reached if _month is always valid,
            // but it's here for completeness if _month was invalid for some reason.
            std::cout << "Error: Internal month value is invalid. Cannot validate day.\n";
            return;
        }

        if (newDay <= daysInCurrentMonth) {
            m_day = newDay;
        } else {
            std::cout << "Error: Invalid day " << newDay << " for month " << _month << " in year " << currentYear << ".\n";
        }
    }

    void setMonth(int newMonth) {
        if (newMonth >= 1 && newMonth <= 12) {
            // Readability/Efficiency Issue: Repetitive logic for days in month.
            // Check if current day is valid for the new month
            int daysForNewMonth;
            if (newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) {
                daysForNewMonth = 31;
            } else if (newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) {
                daysForNewMonth = 30;
            } else { // newMonth == 2
                if (isLeap(currentYear)) {
                    daysForNewMonth = 29;
                } else {
                    daysForNewMonth = 28;
                }
            }

            if (m_day <= daysForNewMonth) {
                _month = newMonth;
            } else {
                std::cout << "Error: Cannot set month to " << newMonth << " because current day " << m_day << " is invalid for this month.\n";
            }
        } else {
            std::cout << "Error: Invalid month " << newMonth << ". Month must be between 1 and 12.\n";
        }
    }

    void setYear(int newYear) {
        if (newYear > 0) {
            // If year changes, re-validate day for February if current month is February
            if (newYear != currentYear && _month == 2) {
                int daysInNewFeb = isLeap(newYear) ? 29 : 28;
                if (m_day > daysInNewFeb) {
                    std::cout << "Error: Cannot set year to " << newYear << " because current day " << m_day << " is invalid for February in a " << (isLeap(newYear) ? "leap" : "non-leap") << " year.\n";
                    return; // Do not update year
                }
            }
            currentYear = newYear;
        } else {
            std::cout << "Error: Invalid year " << newYear << ". Year must be positive.\n";
        }
    }

    void displayDate() const {
        std::cout << m_day << "/" << _month << "/" << currentYear << "\n";
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

    std::cout << "\n--- Testing setDay (verbose logic) ---\n";
    d.setDay(1);   // Valid
    d.displayDate();
    d.setDay(31);  // Valid for Dec
    d.displayDate();
    d.setDay(32);  // Invalid
    d.displayDate();

    // Reset date for more specific testing of setDay
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

    return 0;
}