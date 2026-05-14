#include <iostream>

float calculateAverage(float arr[], int size) {
    if (size <= 0) {
        return 0.0f;
    }
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    // Logical Error: Dividing by size + 1 instead of size
    return sum / (size + 1);
}

int main() {
    float myArray[] = {10.0f, 20.0f, 30.0f};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    float average = calculateAverage(myArray, size);
    std::cout << "The average is: " << average << std::endl;

    return 0;
}