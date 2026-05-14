#include <iostream>

void printPattern(int N) {
    for (int i = 1; i <= N; ++i) {
        // Logical error: The inner loop prints N stars instead of 'i' stars
        for (int j = 1; j <= N; ++j) { 
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main() {
    int N;
    std::cout << "Enter the number of rows: ";
    std::cin >> N;
    printPattern(N);
    return 0;
}