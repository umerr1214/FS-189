#include <iostream>
#include <iomanip> // Essential for std::setw and std::setfill

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

// Correct Version: Implements the << operator using iomanip for proper 'DD-MM-YYYY' formatting.
// It also saves and restores the stream's fill character and format flags for good practice.
std::ostream& operator<<(std::ostream& os, const Date& date) {
    // Save current stream state
    std::ios_base::fmtflags oldFlags = os.flags();
    char oldFill = os.fill();

    os << std::setw(2) << std::setfill('0') << date.day << "-"
       << std::setw(2) << std::setfill('0') << date.month << "-"
       << date.year;

    // Restore original stream state
    os.fill(oldFill);
    os.flags(oldFlags);

    return os;
}

int main() {
    Date d1(1, 1, 2023);
    Date d2(15, 7, 1999);
    Date d3(5, 12, 2010);
    Date d4(28, 2, 2024);

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;

    return 0;
}