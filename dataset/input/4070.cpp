#include <iostream>

int main() {
    int i; // Input number
    std::cout << "Enter an integer: ";
    std::cin >> i;

    long long o = 0; // Output (reversed number). Using long long potentially for larger numbers,
                     // but question implies int. This is an overkill if int is sufficient for the reversed value.
    bool n = false; // Is negative flag

    if (i < 0) {
        n = true;
        i = -i; // Convert to positive for reversal logic
    }

    // This loop handles 0 correctly as well (o remains 0).
    while (i > 0) {
        int d = i % 10; // Current digit
        o = o * 10 + d;
        i /= 10;
    }

    if (n) {
        std::cout << "-";
    }
    std::cout << o << std::endl; // Print the result

    return 0;
}