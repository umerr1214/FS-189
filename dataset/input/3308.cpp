#include <cstdio>   // For printf and scanf
#include <iostream> // Included but not used for I/O in solution_main, which is also an issue

// Renamed main for testing purposes
int solution_main() {
    int num; // Uninformative variable name
    
    // Using scanf for input, which is less C++ idiomatic and type-safe than std::cin
    printf("Enter a number: ");
    scanf("%d", &num);

    int idx = 1; // Manual initialization and increment for loop counter
    while (idx <= 10) { // Using a while loop where a for loop is more appropriate
        // Using printf, which can be less type-safe and harder to read/maintain for simple output
        // compared to std::cout in C++.
        printf("%d * %d = %d\n", num, idx, num * idx);
        idx++; // Manual increment
    }
    return 0;
}

// The actual main function that calls the solution logic
int main() {
    return solution_main();
}