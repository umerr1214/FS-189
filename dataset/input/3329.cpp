#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
#include <cmath>     // For std::abs

bool is_palindrome(int num) {
    // LOGICAL ERROR: Negative numbers are converted to positive for checking,
    // which incorrectly treats numbers like -121 as palindromes.
    int temp_num = std::abs(num); 

    std::string s = std::to_string(temp_num);
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    return s == reversed_s;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "is_palindrome(121): " << is_palindrome(121) << std::endl;
    std::cout << "is_palindrome(123): " << is_palindrome(123) << std::endl;
    std::cout << "is_palindrome(0): " << is_palindrome(0) << std::endl;
    std::cout << "is_palindrome(7): " << is_palindrome(7) << std::endl;
    std::cout << "is_palindrome(1221): " << is_palindrome(1221) << std::endl;
    std::cout << "is_palindrome(-121): " << is_palindrome(-121) << std::endl; // Incorrect: should be false
    std::cout << "is_palindrome(10): " << is_palindrome(10) << std::endl;
    std::cout << "is_palindrome(-10): " << is_palindrome(-10) << std::endl;   // Incorrect: should be false

    return 0;
}