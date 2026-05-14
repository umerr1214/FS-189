#include <iostream>
#include <string>
#include <iomanip> // Not used for formatting in displayDate, but included for consistency
#include <vector>
#include <tuple>
#include <sstream> // For stringstream in displayDate

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValidDate() {
        if (year <= 0) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1) return false;

        // Readability/Efficiency Issue: verbose if-else if chain instead of an array or more concise logic.
        // The leap year calculation is also repeated implicitly within this structure if expanded.
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day > 31) return false;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) return false;
        } else if (month == 2) { // February
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // Correct leap year logic
            if (isLeap) {
                if (day > 29) return false;
            } else {
                if (day > 28) return false;
            }
        }
        return true;
    }

    void displayDate() {
        // Readability/Efficiency Issue: Uses stringstream and manual conditional padding
        // which is less efficient and less idiomatic C++ for fixed-width output
        // compared to using <iomanip> (std::setw, std::setfill).
        // Also, year formatting doesn't ensure 'YYYY' (4-digit with leading zeros).
        std::stringstream ss;
        if (day < 10) ss << '0';
        ss << day << '/';
        if (month < 10) ss << '0';
        ss << month << '/';
        ss << year; // Does not ensure 4-digit year with leading zeros
        
        std::cout << ss.str();
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