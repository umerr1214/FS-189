#include <iostream>

int main() {
    int v[5] = {10, 20, 30, 40, 50}; // Poor variable name 'v' for array
    int s; // Poor variable name 's' for search number
    bool f = false; // Poor variable name 'f' for found flag
    int idx = -1; // Poor variable name 'idx' for index

    std::cout << "Enter a number to search for: ";
    std::cin >> s;

    // Efficiency Issue: The loop continues to iterate through the entire array
    // even after the target number has been found. It does not use 'break'.
    for (int i = 0; i < 5; ++i) {
        if (v[i] == s) {
            f = true;
            idx = i;
            // Missing 'break;' statement here
        }
    }

    if (f == true) { // Readability Issue: Redundant comparison '== true'
        std::cout << "Number found at index: " << idx << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}