#include <iostream> // Required for std::cout

// Correct Version:
// - Handles null pointers and non-positive sizes gracefully.
// - Uses clear and concise variable names.
// - Efficient printing by using '\n' instead of `std::endl` for newline, avoiding unnecessary flushes.
// - Good, consistent code formatting and includes a brief comment.
// - Adheres to the requested function signature `int* arr, int size`.
void printArrayElements(int* arr, int size) {
    // Robustness check: Handle null pointer or non-positive size
    if (arr == nullptr || size <= 0) {
        std::cout << "(empty or invalid array)\n";
        return;
    }

    // Iterate through the array and print elements separated by spaces
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n"; // Use '\n' for efficiency, flushes only at the end
}

int main() {
    // Demonstrate with a valid array
    int myArr[] = {10, 20, 30, 40, 50};
    int arrSize = sizeof(myArr) / sizeof(myArr[0]);
    std::cout << "Printing myArr: ";
    printArrayElements(myArr, arrSize); // Expected: 10 20 30 40 50 \n

    // Demonstrate with an empty array
    int emptyArr[] = {};
    int emptyArrSize = 0;
    std::cout << "Printing emptyArr: ";
    printArrayElements(emptyArr, emptyArrSize); // Expected: (empty or invalid array)\n

    // Demonstrate with a null pointer
    int* nullArr = nullptr;
    int nullArrSize = 5; // Size doesn't matter if arr is null, should be handled
    std::cout << "Printing nullArr: ";
    printArrayElements(nullArr, nullArrSize); // Expected: (empty or invalid array)\n

    // Demonstrate with a negative size (should be handled as invalid)
    int anotherArr[] = {1, 2, 3};
    int negativeSize = -2;
    std::cout << "Printing anotherArr with negative size: ";
    printArrayElements(anotherArr, negativeSize); // Expected: (empty or invalid array)\n

    // Demonstrate with a single element array
    int singleElementArr[] = {100};
    int singleElementArrSize = 1;
    std::cout << "Printing singleElementArr: ";
    printArrayElements(singleElementArr, singleElementArrSize); // Expected: 100 \n

    return 0;
}