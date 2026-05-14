#include <iostream>
#include <string>
#include <iomanip> // For std::setw, std::setfill

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
};

// Semantic Error: The operator<< takes a non-const reference (Date& d)
// instead of a const reference (const Date& d). While it compiles and
// produces correct output in this specific case (because 'd' is not modified),
// it semantically implies that the Date object *could* be modified during
// stream insertion, which violates the expected read-only nature of operator<<
// for objects, and prevents it from being used with const Date objects.
std::ostream& operator<<(std::ostream& os, Date& d) {
    os << std::setw(2) << std::setfill('0') << d.getDay() << "/"
       << std::setw(2) << std::setfill('0') << d.getMonth() << "/"
       << d.getYear();
    return os;
}

int main() {
    Date d1(1, 5, 2023); // Non-const Date object
    Date d2(25, 12, 1999);
    Date d3(9, 7, 2020);

    std::cout << "Date 1: " << d1 << std::endl;
    std::cout << "Date 2: " << d2 << std::endl;
    std::cout << "Date 3: " << d3 << std::endl;

    // If d1 was 'const Date d1(1, 5, 2023);', this would cause a compilation error
    // because operator<< expects a non-const reference. This highlights the semantic issue.

    return 0;
}