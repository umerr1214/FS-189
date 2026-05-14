#include <iostream>

// Function to reverse an integer
int reverseNumber(int n) {
    int reversed_n = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed_n = reversed_n * 10 + digit // Missing semicolon here
        n /= 10;
    }
    return reversed_n;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverseNumber(n) << std::endl;
    return 0;
}