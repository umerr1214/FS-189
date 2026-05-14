#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    // Robustness Issue: Handling negative years? (BC)
    // Leap year rules for BC are different (historical), but usually function expects AD.
    // Or check for year 0 (doesn't exist in Gregorian).
    
    // Let's say function crashes or loops if negative? No, % operator works.
    // But logically, negative year is robust issue if not handled.
    
    // Actually, let's use a simpler robustness issue:
    // What if year is 0?
    // 0 % 4 == 0. 0 % 100 == 0. 0 % 400 == 0. Returns true.
    // Is year 0 valid? No.
    
    // Missing check for year > 0.
    
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    // 0
    cout << isLeapYear(0) << endl;
    return 0;
}
