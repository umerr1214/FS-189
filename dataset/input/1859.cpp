#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void displayDate() const {
        // Logical Error: This method always prints a hardcoded date,
        // ignoring the actual day, month, and year of the object.
        std::cout << "01/01/2000" << std::endl;
    }
};

int main() {
    Date today(25, 10, 2023);
    std::cout << "Non-const date: ";
    today.displayDate(); // Will incorrectly print 01/01/2000

    const Date anniversary(1, 1, 2024);
    std::cout << "Const date: ";
    anniversary.displayDate(); // Will incorrectly print 01/01/2000

    return 0;
}