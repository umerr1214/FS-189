#include <iostream>
#include <string>
#include <algorithm> // For std::to_string

int main() {
    long long num;

    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Input must be a non-negative integer." << std::endl;
        return 1;
    }

    // Semantic error: The problem asks to use a 'while' loop to count digits *in that integer*.
    // This solution converts the integer to a string and then gets its length,
    // which effectively counts digits but doesn't use a while loop on the numerical value
    // as implied by "count the number of digits in that integer" using arithmetic operations.
    std::string s = std::to_string(num);
    int count = s.length();

    std::cout << "The number " << num << " has " << count << " digits." << std::endl;

    return 0;
}