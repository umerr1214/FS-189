#include <iostream>
#include <limits> // Required for std::numeric_limits

int student_main() {
    int arr[10] = {5, 2, 9, 1, 7, 3, 8, 4, 6, 10};
    int minVal = std::numeric_limits<int>::max();
    int maxVal = std::numeric_limits<int>::min();

    for (int i = 0; i < 10; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    std::cout << "Minimum value: " << minVal << std::endl
    std::cout << "Maximum value: " << maxVal << std::endl;
    return 0;
}