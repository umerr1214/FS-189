#include <iostream>

float calculateAverage(float arr[], int size) {
    if (size <= 0) {
        return 0.0f;
    }
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        // This loop will read memory as float, but it contains int values passed from main
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    // Semantic Error: Declaring an int array but passing it to a function expecting float arr[]
    // The compiler might issue a warning about incompatible pointer types.
    // The function will interpret the int values in memory as floats, leading to incorrect results.
    int myArray[] = {10, 20, 30}; // These are integer values
    int size = sizeof(myArray) / sizeof(myArray[0]);

    float average = calculateAverage(myArray, size); // Implicit conversion/warning for int* to float*
    std::cout << "The average is: " << average << std::endl;

    return 0;
}