#include <iostream>
#include <string>

template <typename T>
T findMax(T a, T b) {
    // Logical Error: This function incorrectly returns the smaller value
    if (a < b) {
        return a; // Should return b for the maximum
    } else {
        return b; // Should return a for the maximum
    }
}

int main() {
    int i1 = 10, i2 = 20;
    double d1 = 5.5, d2 = 15.3;
    char c1 = 'a', c2 = 'z';
    std::string s1 = "apple", s2 = "banana";

    std::cout << "Max of " << i1 << " and " << i2 << " is: " << findMax(i1, i2) << " (Expected: 20)" << std::endl;
    std::cout << "Max of " << d1 << " and " << d2 << " is: " << findMax(d1, d2) << " (Expected: 15.3)" << std::endl;
    std::cout << "Max of " << c1 << " and " << c2 << " is: " << findMax(c1, c2) << " (Expected: z)" << std::endl;
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" is: " << findMax(s1, s2) << " (Expected: banana)" << std::endl;

    return 0;
}