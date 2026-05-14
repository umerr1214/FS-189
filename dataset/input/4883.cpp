#include <iostream>

int main() {
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Logical Error: sum initialized to 1 instead of 0
    // This will result in the correct diagonal sum + 1
    int sum = 1;
    for (int i = 0; i < 4; ++i) {
        sum += matrix[i][i];
    }

    std::cout << "Sum of main diagonal elements: " << sum << std::endl;

    return 0;
}