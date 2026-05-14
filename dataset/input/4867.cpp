#include <iostream> // Required for std::cout, std::endl

// Robustness Issue:
// This function does not handle null pointers for 'arr' or negative 'size' gracefully.
// Dereferencing a null 'arr' with a positive 'size' will lead to a crash (segmentation fault).
// A negative 'size' will result in the loop not executing, which is not a crash but also not
// explicitly handled as an invalid input.
void printArrayElements(int* arr, int size) {
    // No check for arr == nullptr
    // No explicit check for size <= 0 (though loop naturally handles size=0)
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " "; // Potential dereference of null pointer if arr is nullptr and size > 0
    }
    std::cout << std::endl; // Uses std::endl, which is less efficient than '\n' if not needed to flush
}

int main() {
    // Test Case 1: Valid array
    int myArr[] = {10, 20, 30, 40, 50};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    std::cout << "Test 1: Valid array: ";
    printArrayElements(myArr, arrSize); // Expected: 10 20 30 40 50

    // Test Case 2: Empty array (size 0)
    int emptyArr[] = {};
    int emptyArrSize = 0;
    std::cout << "Test 2: Empty array (size 0): ";
    printArrayElements(emptyArr, emptyArrSize); // Expected: (empty line)

    // Test Case 3: Null pointer with positive size (Robustness issue trigger - will likely crash)
    int* nullArr = nullptr;
    int nullArrSize = 3;
    std::cout << "Test 3: Null pointer (expected crash/undefined behavior): ";
    printArrayElements(nullArr, nullArrSize);

    // Test Case 4: Negative size (Robustness issue trigger - unexpected behavior, loop won't run)
    int anotherArr[] = {1, 2, 3};
    int negativeSize = -2;
    std::cout << "Test 4: Negative size (expected no output, but invalid input): ";
    printArrayElements(anotherArr, negativeSize);

    return 0;
}