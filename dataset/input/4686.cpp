#include <iostream>
#include <string>

template <typename T>
// Semantic Error: Parameters are non-const lvalue references, which cannot bind to rvalues (literals).
// This design works for lvalue variables, but fails for direct literals.
T& findMax(T& a, T& b) {
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
    std::string s1 = "apple", s2 = "banana";

    // These calls are fine because i1, i2, d1, d2, c1, c2, s1, s2 are lvalues
    std::cout << "Max of " << i1 << " and " << i2 << " is: " << findMax(i1, i2) << std::endl;
    std::cout << "Max of " << d1 << " and " << d2 << " is: " << findMax(d1, d2) << std::endl;
    std::cout << "Max of " << c1 << " and " << c2 << " is: " << findMax(c1, c2) << std::endl;
    std::cout << "Max of \"" << s1 << "\" and \"" << s2 << "\" is: " << findMax(s1, s2) << std::endl;

    // Semantic Error: Calling findMax with literals (rvalues)
    // Literals 5 and 10 are rvalues and cannot bind to non-const lvalue references T&
    // This will result in a compilation error.
    // std::cout << "Max of 5 and 10 is: " << findMax(5, 10) << std::endl;
    // std::cout << "Max of 3.14 and 2.71 is: " << findMax(3.14, 2.71) << std::endl;

    return 0;
}