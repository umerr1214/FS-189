#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year <= 0) return false; // Basic validation
    
    // Leap year logic:
    // Divisible by 4 AND NOT divisible by 100
    // OR divisible by 400
    
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    cout << "2024: " << isLeapYear(2024) << endl; // 1
    cout << "1900: " << isLeapYear(1900) << endl; // 0
    cout << "2000: " << isLeapYear(2000) << endl; // 1
    cout << "2023: " << isLeapYear(2023) << endl; // 0
    cout << "0: " << isLeapYear(0) << endl; // 0
    return 0;
}
