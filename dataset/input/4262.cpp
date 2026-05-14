#include <iostream>

int main() {
    int s; // Obscure variable name for 'size'
    std::cout << "Gimme array size: "; // Unfriendly and less clear prompt
    std::cin >> s;

    // Combined input validation check, less readable
    if (std::cin.fail() || s <= 0) {
        std::cerr << "Bad input or size. Bye." << std::endl; // Unfriendly error message
        return 1;
    }

    int* d = new int[s]; // Obscure variable name for 'dynamicArray'

    // No comments explaining the purpose of the loop
    for (int x = 0; x < s; ++x) { // Obscure loop counter variable 'x'
        d[x] = x + 1;
    }

    std::cout << "Data: "; // Short, unclear output prompt
    for (int x = 0; x < s; ++x) {
        std::cout << d[x] << std::endl; // Efficiency Issue: std::endl flushes the buffer on each iteration, which can be less efficient than using '\n' for large arrays.
    }

    delete[] d; // Deallocates memory, but 'd' is not set to nullptr
    return 0;
}