#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Semantic Error: operator== is not const and modifies 'this->day'
    // A comparison operator should be const and not modify the objects being compared.
    bool operator==(const Date& other) { // Missing 'const' qualifier here
        this->day = other.day; // Semantic error: Modifying 'this' object during comparison
        return day == other.day && month == other.month && year == other.year;
    }

    void print() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

int main() {
    Date d1(1, 1, 2023);
    Date d2(1, 1, 2023);
    Date d3(2, 1, 2023); 
    Date d4(1, 2, 2023);
    Date d5(1, 1, 2024);

    std::cout << "Initial d1: "; d1.print(); std::cout << std::endl;
    std::cout << "Initial d3: "; d3.print(); std::cout << std::endl;

    std::cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << std::endl; 
    std::cout << "After d1 == d2, d1: "; d1.print(); std::cout << std::endl; // d1.day might change here if d1.day != d2.day initially

    std::cout << "d1 == d3: " << (d1 == d3 ? "true" : "false") << std::endl; 
    std::cout << "After d1 == d3, d1: "; d1.print(); std::cout << std::endl; // d1.day changes to d3.day (2)

    std::cout << "d1 == d4: " << (d1 == d4 ? "true" : "false") << std::endl; 
    std::cout << "After d1 == d4, d1: "; d1.print(); std::cout << std::endl; // d1.day changes to d4.day (1)

    std::cout << "d1 == d5: " << (d1 == d5 ? "true" : "false") << std::endl; 
    std::cout << "After d1 == d5, d1: "; d1.print(); std::cout << std::endl; // d1.day changes to d5.day (1)

    return 0;
}