#include <iostream>

void solve() {
    int yr_val; // Unclear variable name
    std::cout << "Enter a year: ";
    std::cin >> yr_val;

    // Overly verbose and nested logic for leap year check, reducing readability
    bool is_div_by_4 = (yr_val % 4 == 0);
    bool is_div_by_100 = (yr_val % 100 == 0);
    bool is_div_by_400 = (yr_val % 400 == 0);

    if (is_div_by_4) {
        if (is_div_by_100) {
            if (is_div_by_400) {
                std::cout << yr_val << " is a leap year." << std::endl;
            } else {
                std::cout << yr_val << " is not a leap year." << std::endl;
            }
        } else {
            std::cout << yr_val << " is a leap year." << std::endl;
        }
    } else {
        std::cout << yr_val << " is not a leap year." << std::endl;
    }
}

int main() {
    solve();
    return 0;
}