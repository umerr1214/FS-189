#include <iostream>
#include <string>

class Date {
private // Missing semicolon here
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
        if (!setYear(y)) { /* std::cerr << "Invalid initial year: " << y << ". Keeping default." << std::endl; */ }
        if (!setMonth(m)) { /* std::cerr << "Invalid initial month: " << m << ". Keeping default." << std::endl; */ }
        if (!setDay(d)) { /* std::cerr << "Invalid initial day: " << d << ". Keeping default." << std::endl; */ }
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
    Date d1(29, 2, 2024); // Should be a valid date
    std::cout << "Date(29, 2, 2024): ";
    d1.display();

    Date d2(31, 4, 2023); // April only has 30 days
    std::cout << "Date(31, 4, 2023): ";
    d2.display(); // Should display default 1/1/2000 as 31/4/2023 is invalid

    return 0;
}