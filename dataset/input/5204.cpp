#include <iostream>
#include <iomanip> // Needed for std::fixed and std::setprecision

// This program calculates the average of positive integers.
// It exhibits readability and potential efficiency issues.
int main() {
    long long s = 0; // 's' for sum - not very descriptive
    int c = 0;       // 'c' for count - not very descriptive
    int val;         // 'val' for value - generic

    // Less professional and clear prompt
std::cout << "Gimme numbers (stop with -1):" << std::endl;

    // The loop structure is slightly less direct than 'while (cin >> val && val != -1)'
    while (true) {
        std::cin >> val; // Read input
        if (val == -1) { // Check for sentinel value
            break;       // Exit the loop
        }
        // Conditional check for positive numbers
        if (val > 0) {
            s += val; // Add to sum
            c++;      // Increment count
        }
    }

    // Proper handling for division by zero, but output prompt is terse
    if (c > 0) {
        double avg = static_cast<double>(s) / c;
        std::cout << "Avg: " << std::fixed << std::setprecision(1) << avg << std::endl;
    } else {
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0;
}