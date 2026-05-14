#include <iostream>
#include <string>

std::string classifyTriangle(int a, int b, int c) {
    if (a == b && b == c) {
        return "Equilateral";
    } else if ((a == b && a != c) || (b == c && b != a) || (a == c && c != b)) {
        // Semantic error: This condition explicitly checks for "strictly isosceles"
        // (exactly two sides equal). While this leads to the correct distinct categorization
        // (Equilateral, Isosceles, Scalene), the explicit exclusion of the third side
        // (e.g., 'a != c') is semantically redundant after the 'Equilateral' check.
        // In an 'if-else if' structure, if the first 'if' for Equilateral is false,
        // it's implicitly known that not all three sides are equal. A simpler and more
        // common way to express the "non-equilateral isosceles" condition would be
        // '(a == b || b == c || a == c)', as the Equilateral case is already handled.
        // This overly specific condition for Isosceles, though functionally correct here,
        // suggests a slight misinterpretation of how conditions are implicitly narrowed
        // in an if-else if chain, or an unnecessary verbosity in defining a term.
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

int main() {
    int s1, s2, s3;
    std::cout << "Enter three side lengths: ";
    std::cin >> s1 >> s2 >> s3;
    std::string type = classifyTriangle(s1, s2, s3);
    std::cout << "The triangle is: " << type << std::endl;
    return 0;
}