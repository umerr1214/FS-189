#include <iostream>
#include <string> // Included for general C++ program, not strictly used by printArray

// Function template to print elements of a 1D array
template <typename T>
void printArray(const T theArray[], int cnt) { // Readability: 'theArray' and 'cnt' are less descriptive than 'arr' and 'size'
    std::cout << "Array elements: [";
    // Readability/Efficiency Issue: The 'if (cnt > 0)' check is not strictly necessary.
    // The 'for' loop condition 'i < cnt' would naturally handle 'cnt <= 0' correctly.
    // It slightly reduces readability and adds an unnecessary branch.
    if (cnt > 0) {
        for (int i = 0; i < cnt; ++i) {
            std::cout << theArray[i];
            // Readability Issue: 'i != cnt - 1' is functionally correct but 'i < cnt - 1' is more idiomatic
            // and often clearer for loop-based conditional formatting.
            if (i != cnt - 1) {
                std::cout << ", ";
            }
        }
    }
    // Efficiency Issue: Uses std::endl, which flushes the output buffer.
    // For simple newline characters, '\n' is generally more efficient as it
    // doesn't force a flush, allowing the system to buffer output more effectively.
    std::cout << "]" << std::endl;
}

int main() {
    // Test case 1: int array
    int someInts[] = {11, 22, 33};
    int countInts = sizeof(someInts) / sizeof(someInts[0]);
    std::cout << "Testing int array:\n";
    printArray(someInts, countInts); // Expected: Array elements: [11, 22, 33]

    std::cout << "\n";

    // Test case 2: char array
    char letters[] = {'W', 'o', 'r', 'l', 'd'};
    int countLetters = sizeof(letters) / sizeof(letters[0]);
    std::cout << "Testing char array:\n";
    printArray(letters, countLetters); // Expected: Array elements: [W, o, r, l, d]

    std::cout << "\n";

    // Test case 3: Empty array (size 0)
    int emptyContainer[] = {};
    int emptyCount = 0;
    std::cout << "Testing empty array:\n";
    printArray(emptyContainer, emptyCount); // Expected: Array elements: []

    return 0;
}