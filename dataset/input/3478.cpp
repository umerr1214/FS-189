#include <iostream>

float calculateAverage(float arr[], int size) {
    if (size <= 0) {
        return 0.0f;
    }
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    float myArray[] = {10.0f, 20.0f, 30.0f};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    float average = calculateAverage(myArray, size);
    std::cout << "The average is: " << average // Syntax Error: Missing semicolon
    return 0;
}