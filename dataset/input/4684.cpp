#include <iostream>

// Syntax Error: 'template' keyword is misspelled
templete <typename T>
T findMax(T a, T b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int i1 = 10, i2 = 20;
    double d1 = 5.5, d2 = 15.3;
    char c1 = 'a', c2 = 'z';

    // These calls will cause a compilation error due to the misspelled template keyword
    // std::cout << "Max of " << i1 << " and " << i2 << " is: " << findMax(i1, i2) << std::endl;
    // std::cout << "Max of " << d1 << " and " << d2 << " is: " << findMax(d1, d2) << std::endl;
    // std::cout << "Max of " << c1 << " and " << c2 << " is: " << findMax(c1, c2) << std::endl;

    return 0;
}