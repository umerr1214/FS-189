#include <iostream>
#include <string>

class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    // Constructor initializes with default values, but doesn't fully utilize setters for robust validation
    Date(int year = 2000, int month = 1, int day = 1) : _year(year), _month(month), _day(day) {
        // No robust validation in constructor, relies on external calls to setters
        // This is a minor efficiency/readability issue, as a correct constructor would validate.
        // For the purpose of this example, we focus on the setters themselves.
    }

    // Setter for day: Correct but very inefficient and hard to read due to duplicated logic
    bool setDay(int day_to_set) { // Using different variable name for clarity, but adds verbosity
        if (day_to_set < 1) {
            std::cout << "Invalid day: Day must be at least 1." << std::endl;
            return false;
        }

        // Duplicated leap year check logic
        bool current_year_is_leap = (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);

        // Very long and repetitive if-else if chain for max days in month
        if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
            if (day_to_set > 31) {
                std::cout << "Invalid day: Day cannot exceed 31 for month " << _month << "." << std::endl;
                return false;
            }
        } else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
            if (day_to_set > 30) {
                std::cout << "Invalid day: Day cannot exceed 30 for month " << _month << "." << std::endl;
                return false;
            }
        } else if (_month == 2) { // February
            if (current_year_is_leap) { // Duplicated leap year check
                if (day_to_set > 29) {
                    std::cout << "Invalid day: Day cannot exceed 29 for February in a leap year." << std::endl;
                    return false;
                }
            } else {
                if (day_to_set > 28) {
                    std::cout << "Invalid day: Day cannot exceed 28 for February in a common year." << std::endl;
                    return false;
                }
            }
        } else {
            // This case should ideally not be reached if _month is properly validated by setMonth,
            // but for completeness, it implies an invalid month state.
            std::cout << "Internal error: Month is not valid when setting day." << std::endl;
            return false;
        }

        _day = day_to_set;
        return true;
    }

    // Setter for month: Correct but could be more concise
    bool setMonth(int month_to_set) {
        if (month_to_set < 1 || month_to_set > 12) {
            std::cout << "Invalid month: Month must be between 1 and 12." << std::endl;
            return false;
        }
        _month = month_to_set;
        // This setter does not re-validate the day, which can lead to a temporarily inconsistent state.
        // E.g., if date is Jan 31, and month changes to Feb, day remains 31.
        // While not strictly an error (setDay should catch it), it's an efficiency/readability concern
        // as the object state can be invalid until setDay is called again.
        return true;
    }

    // Setter for year: Correct but could be more concise
    bool setYear(int year_to_set) {
        if (year_to_set <= 0) {
            std::cout << "Invalid year: Year must be positive." << std::endl;
            return false;
        }
        _year = year_to_set;
        // Similar to setMonth, this doesn't re-validate the day, potentially leaving 29th Feb in a non-leap year.
        return true;
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
    Date d(2023, 1, 1);
    std::cout << "Initial date: "; d.printDate(); std::cout << std::endl; // 2023-01-01

    d.setMonth(2); // Set to February
    d.setDay(28);  // Valid day for Feb 2023
    std::cout << "After setting Feb 28: "; d.printDate(); std::cout << std::endl; // 2023-02-28

    d.setDay(29); // Invalid day for Feb 2023 (not leap)
    std::cout << "Attempt Feb 29 (2023): "; d.printDate(); std::cout << std::endl; // Error msg, then 2023-02-28

    d.setYear(2024); // Set to leap year
    d.setDay(29);   // Valid day for Feb 2024 (leap)
    std::cout << "After setting Feb 29 (2024): "; d.printDate(); std::cout << std::endl; // 2024-02-29

    d.setDay(30); // Invalid day for Feb 2024
    std::cout << "Attempt Feb 30 (2024): "; d.printDate(); std::cout << std::endl; // Error msg, then 2024-02-29

    d.setMonth(4); // Set to April
    d.setDay(30);  // Valid day for April
    std::cout << "After setting Apr 30: "; d.printDate(); std::cout << std::endl; // 2024-04-30

    d.setDay(31); // Invalid day for April
    std::cout << "Attempt Apr 31: "; d.printDate(); std::cout << std::endl; // Error msg, then 2024-04-30

    d.setMonth(13); // Invalid month
    std::cout << "Attempt invalid month: "; d.printDate(); std::cout << std::endl; // Error msg, then 2024-04-30

    d.setYear(-1); // Invalid year
    std::cout << "Attempt invalid year: "; d.printDate(); std::cout << std::endl; // Error msg, then 2024-04-30

    return 0;
}