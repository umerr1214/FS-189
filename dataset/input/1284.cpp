#include <iostream>
#include <string>

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
        // Note: Due to semantic error in setters, even constructor might set invalid states.
        if (!setYear(y)) { std::cerr << "Constructor: Invalid initial year " << y << ". Setting anyway due to semantic error." << std::endl; }
        if (!setMonth(m)) { std::cerr << "Constructor: Invalid initial month " << m << ". Setting anyway due to semantic error." << std::endl; }
        if (!setDay(d)) { std::cerr << "Constructor: Invalid initial day " << d << ". Setting anyway due to semantic error." << std::endl; }
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Semantic Error: Setter validates but still assigns invalid value to the member
    bool setDay(int d) {
        if (d >= 1 && d <= daysInMonth(month, year)) {
            day = d;
            return true;
        } else {
            std::cerr << "Semantic Error: Attempted to set invalid day " << d << " for " << month << "/" << year << ". Assigning anyway!" << std::endl;
            day = d; // THIS IS THE SEMANTIC ERROR - assigns invalid value
            return false; // Returns false, but the object's state is corrupted
        }
    }

    // Semantic Error: Setter validates but still assigns invalid value to the member
    bool setMonth(int m) {
        if (m >= 1 && m <= 12) {
            // Check if current day is valid for the new month
            if (day <= daysInMonth(m, year)) {
                month = m;
                return true;
            } else {
                std::cerr << "Semantic Error: Month " << m << " would make current day " << day << " invalid for year " << year << ". Assigning month anyway!" << std::endl;
                month = m; // THIS IS THE SEMANTIC ERROR
                return false;
            }
        } else {
            std::cerr << "Semantic Error: Attempted to set invalid month " << m << ". Assigning anyway!" << std::endl;
            month = m; // THIS IS THE SEMANTIC ERROR
            return false;
        }
    }

    // Semantic Error: Setter validates but still assigns invalid value to the member
    bool setYear(int y) {
        if (y >= 1900 && y <= 2100) { // Arbitrary reasonable year range
            // Check if current day/month is valid for the new year
            if (day <= daysInMonth(month, y)) {
                year = y;
                return true;
            } else {
                std::cerr << "Semantic Error: Year " << y << " would make current day " << day << " invalid for month " << month << ". Assigning year anyway!" << std::endl;
                year = y; // THIS IS THE SEMANTIC ERROR
                return false;
            }
        } else {
            std::cerr << "Semantic Error: Attempted to set invalid year " << y << ". Assigning anyway!" << std::endl;
            year = y; // THIS IS THE SEMANTIC ERROR
            return false;
        }
    }

    void display() const {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

int main() {
    std::cout << "Testing Date class with Semantic Error (setters assign invalid values):" << std::endl;

    Date d(15, 6, 2023);
    std::cout << "Initial date: ";
    d.display(); // 15/6/2023

    // Try to set an invalid day for June (June has 30 days)
    std::cout << "Attempting to set day to 31 for June:" << std::endl;
    if (!d.setDay(31)) {
        std::cout << "setDay returned false, but checking state: ";
        d.display(); // Expected: 15/6/2023 (original), Actual: 31/6/2023 (invalid due to semantic error)
    }

    // Try to set an invalid month (0)
    std::cout << "Attempting to set month to 0:" << std::endl;
    if (!d.setMonth(0)) {
        std::cout << "setMonth returned false, but checking state: ";
        d.display(); // Expected: 31/6/2023, Actual: 31/0/2023 (invalid due to semantic error)
    }

    // Try to set an invalid year (1800, outside 1900-2100 range)
    std::cout << "Attempting to set year to 1800:" << std::endl;
    if (!d.setYear(1800)) {
        std::cout << "setYear returned false, but checking state: ";
        d.display(); // Expected: 31/0/2023, Actual: 31/0/1800 (invalid due to semantic error)
    }

    // Test constructor with invalid values (Feb 2023 has 28 days)
    std::cout << "\nTesting constructor with invalid values (31, 2, 2023):" << std::endl;
    Date d_invalid_ctor(31, 2, 2023); 
    std::cout << "Date created with (31, 2, 2023): ";
    d_invalid_ctor.display(); // Expected: 1/1/2000 (defaults), Actual: 31/2/2023 (invalid due to semantic error)

    return 0;
}