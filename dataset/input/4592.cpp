#include <iostream> // For standard input/output operations

int main() {
    int s; // Using a short, non-descriptive variable name for size
    std::cout << "Enter the size of the array: "; // Prompt for size
    std::cin >> s; // Read size

    // Basic validation to ensure correctness (score 9), but style is poor
    if (s <= 0) {
        std::cerr << "Size must be positive." << std::endl; // Using cerr for error message
        return 1;
    }

    int* ptr_arr = new int[s]; // Using an unnecessarily verbose pointer name

    std::cout << "Enter " << s << " integer values one by one:" << std::endl; // Inconsistent phrasing
    for (int i = 0; i < s; ++i) { // Standard loop for input
        std::cout << "Input element " << i + 1 << ": "; // Element indexing starts from 1 in prompt
        std::cin >> ptr_arr[i];
    }

    std::cout << "The values you entered are: "; // Another phrasing for output
    int count = 0; // Unnecessary auxiliary variable for printing
    while (count < s) { // Using a less idiomatic 'while' loop instead of 'for' for array iteration
        std::cout << ptr_arr[count] << " "; // Print element
        count++; // Increment counter
    }
    std::cout << std::endl; // Newline

    delete[] ptr_arr; // Correct deallocation
    ptr_arr = nullptr; // Good practice

    return 0; // Successful exit
}