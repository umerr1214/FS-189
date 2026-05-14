#include <iostream>
#include <vector> // Unnecessary header for this simple function, adds slight overhead

// Function with poor readability:
// - Cryptic parameter names (p1, p2, ps)
// - Inconsistent indentation in the function body
// - Uses unnecessary intermediate variables
void addNumbers(int* p1, int* p2, int* ps) {
    // This function calculates the sum.
    // The names of the parameters are not descriptive.
    // Unnecessary intermediate variables are used, which don't improve clarity or efficiency.
    int val1 = *p1;   // Get value from first pointer
    int val2 = *p2;   // Get value from second pointer
    int res = val1 + val2; // Calculate sum
    *ps = res;        // Store result at location pointed to by ps
}

int main() {
    int   a = 10; // Poor variable naming and inconsistent alignment
    int     b = 20;
    int        c = 0;

    // Call the function with non-descriptive variable names
    addNumbers(&a, &b, &c);

    std::cout << "Sum is: " << c << std::endl; // Generic and uninformative output message

    // Another case with different numbers and similarly poor naming
    int valA = -5;
    int valB = 15;
    int valC = 0;
    addNumbers(&valA, &valB, &valC);
    std::cout << "Another sum: " << valC << std::endl;

    return 0;
}