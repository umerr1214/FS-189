#include <iostream> // For std::cin, std::cout, std::endl

// Renamed main for testing purposes
int solution_main() {
    int X;
    // Prompt for input
    std::cout << "Enter a number: ";
    std::cin >> X;

    for (int i = 1; i <= 10; ++i) {
        // Potential for integer overflow if X is large enough.
        // For example, if X = 250,000,000, then X * 10 = 2,500,000,000,
        // which exceeds the typical INT_MAX (2,147,483,647) on most systems.
        // This will result in an incorrect (overflowed) value being printed
        // for products that exceed INT_MAX.
        std::cout << X << " * " << i << " = " << X * i << std::endl;
    }
    return 0;
}

// The actual main function that calls the solution logic
int main() {
    return solution_main();
}