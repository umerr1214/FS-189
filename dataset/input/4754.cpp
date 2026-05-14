#include <iostream>

// Readability / Efficiency Issue: Convoluted loop structure and minor inefficiency.
void printFibonacci(int n) {
    if (n <= 0) {
        return; // No output for non-positive n.
    }

    long long first_num = 0;
    long long second_num = 1;
    int current_count = 0; // An unnecessary counter for a simple sequence generation

    while (current_count < n) {
        if (current_count == 0) {
            std::cout << first_num;
        } else if (current_count == 1) {
            // This logic is a bit clunky as it prints 'second_num' directly
            // and relies on 'first_num' and 'second_num' holding the correct values
            std::cout << " " << second_num;
        } else {
            // Calculate and print subsequent numbers
            long long temp_sum = first_num + second_num;
            std::cout << " " << temp_sum;
            first_num = second_num;
            second_num = temp_sum;
        }
        current_count++;
    }
    std::cout << std::endl; // Using std::endl flushes the buffer, which is less efficient than '\n'.
}

int main() {
    // Driver code for testing
    // The actual test cases are in the JSON file.
    // This main function is just to make the CPP file a complete program.
    printFibonacci(5); // Example call
    return 0;
}