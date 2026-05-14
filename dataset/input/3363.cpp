#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for using std::vector to store integers dynamically
#include <algorithm> // Required for std::count, though a manual loop is also clear

// Encapsulates the core logic to allow for easy testing with redirected I/O.
void solve(std::istream& is, std::ostream& os) {
    int arraySize;
    // Read the size of the array from the input stream.
    is >> arraySize;

    // Handle edge case: if arraySize is negative, it's an invalid input for an array size.
    // Treat it as an empty array, resulting in 0 occurrences.
    if (arraySize < 0) {
        os << 0;
        return;
    }

    // Declare a std::vector to store the integers. std::vector handles dynamic sizing.
    std::vector<int> numbers(arraySize);
    // Loop to read each integer into the vector.
    for (int i = 0; i < arraySize; ++i) {
        is >> numbers[i];
    }

    int targetNumber;
    // Read the target number to count its occurrences.
    is >> targetNumber;

    int occurrenceCount = 0;
    // Iterate through the vector using a range-based for loop (modern C++ style)
    // to count how many times the target number appears.
    for (int num : numbers) {
        if (num == targetNumber) {
            occurrenceCount++;
        }
    }
    // Alternatively, using std::count from <algorithm> for conciseness:
    // int occurrenceCount = std::count(numbers.begin(), numbers.end(), targetNumber);

    // Output the total count of occurrences to the output stream.
    os << occurrenceCount;
}

int main() {
    // Call the solve function with standard input and output streams.
    solve(std::cin, std::cout);
    return 0; // Indicate successful execution.
}