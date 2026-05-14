#include <iostream>
#include <vector>
using namespace std;

bool isLeapYear(int year) {
    // Efficiency Issue: Iterating from year 1 to check?
    // O(N) instead of O(1).
    // Or creating a list of leap years?
    
    vector<int> leapYears;
    for (int y = 0; y <= year + 400; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            leapYears.push_back(y);
        }
    }
    
    for (int ly : leapYears) {
        if (ly == year) return true;
    }
    return false;
}

int main() {
    cout << isLeapYear(2024) << endl;
    return 0;
}
