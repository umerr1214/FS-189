#include <iostream>

int main() {
    int N;
    std::cout << "Enter the number of rows: ";
    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        // Logical error: The inner loop iterates N times instead of i times,
        // causing it to print a square pattern instead of a triangle.
        for (int j = 1; j <= N; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}