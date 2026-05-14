#include <iostream>
#include <iomanip> // Required for std::setw and std::setfill

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    // Public method to display the date
    // This method has a logical error: it prints in MM-DD-YYYY format instead of DD-MM-YYYY
    void displayDate() {
        std::cout << std::setw(2) << std::setfill('0') << month << "-" // Logical error: month first
                  << std::setw(2) << std::setfill('0') << day << "-"   // then day
                  << year;
    }
};

int main() {
    // Test cases
    Date d1(1, 1, 2023);
    std::cout << "Date 1: ";
    d1.displayDate();
    std::cout << std::endl;

    Date d2(15, 12, 2024);
    std::cout << "Date 2: ";
    d2.displayDate();
    std::cout << std::endl;

    Date d3(5, 7, 1999);
    std::cout << "Date 3: ";
    d3.displayDate();
    std::cout << std::endl;

    return 0;
}