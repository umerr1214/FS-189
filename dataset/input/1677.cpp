#include <iostream>
#include <string>
#include <iomanip> // For std::setw and std::setfill
#include <vector>
#include <tuple>

class Date {
private:
    int day;
    int month;
    int year;

    // Helper to check for leap year
    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // isValidDate() method - checks if the date is valid
    bool isValidDate() const { // Made const as it doesn't modify object state
        if (year <= 0) return false; // Year must be positive
        if (month < 1 || month > 12) return false; // Month must be between 1 and 12
        if (day < 1) return false; // Day must be at least 1

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeap(year)) {
            daysInMonth[2] = 29; // Adjust for February in a leap year
        }

        return day <= daysInMonth[month]; // Check if day is within valid range for the month
    }

    // displayDate() method - displays the date in 'DD/MM/YYYY' format
    void displayDate() const { // Made const as it doesn't modify object state
        std::cout << std::setfill('0') << std::setw(2) << day << '/'
                  << std::setfill('0') << std::setw(2) << month << '/'
                  << std::setfill('0') << std::setw(4) << year;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::tuple<int, int, int>> inputs = {
        {15, 3, 2023},   // Valid
        {29, 2, 2024},   // Leap year
        {29, 2, 2023},   // Non-leap year Feb
        {31, 4, 2023},   // Month with 30 days, invalid day
        {31, 1, 2023},   // Month with 31 days, valid day
        {1, 13, 2023},   // Invalid month (too high)
        {1, 0, 2023},    // Invalid month (too low)
        {0, 1, 2023},    // Invalid day (too low)
        {29, 2, 2000},   // Century leap year (divisible by 400)
        {29, 2, 1900},   // Century non-leap year (divisible by 100 but not 400)
        {1, 1, 0},       // Year 0
        {1, 1, -2023}    // Negative year
    };

    for (const auto& input_tuple : inputs) {
        int d = std::get<0>(input_tuple);
        int m = std::get<1>(input_tuple);
        int y = std::get<2>(input_tuple);

        Date date(d, m, y);
        std::cout << "Input: " << d << " " << m << " " << y << "\n";
        std::cout << "isValid: " << (date.isValidDate() ? "true" : "false") << ", display: ";
        date.displayDate();
        std::cout << "\n";
    }
    return 0;
}