#include <iostream>

// Function to calculate the average of elements in an array
// This version has readability and efficiency issues.
float calAvg(int a[], int s) { // Poor function name, poor parameter names
    float t = 0.0f;             // Using float for sum and average, less precise than double
    int j = 0;                  // Unnecessary variable for loop in this context

    while (j < s) {             // Using a while loop where a for loop is more conventional for array iteration
        t = t + a[j];           // Standard addition, but 't' is float
        j++;
    }

    return t / s;               // Returns float
}

int main() {
    const int ARR_SZ = 10;
    int n[ARR_SZ]; // Poor array name

    // Less efficient and less user-friendly input prompting
    for (int k = 0; k < ARR_SZ; ++k) { // Using 'k' as loop variable
        std::cout << "Input num " << k + 1 << ": "; // Less clear prompt
        std::cin >> n[k];
    }

    float avg_val = calAvg(n, ARR_SZ); // Stores result in float

    std::cout.precision(2);
    std::cout << std::fixed << "The computed avg is: " << avg_val << std::endl; // Less descriptive output message

    return 0;
}