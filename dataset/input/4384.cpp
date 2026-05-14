#include <iostream>

void printPattern(int N) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main() {
    int N;
    std::cout << "Enter the number of rows: ";
    std::cin >> N // Missing semicolon here, causing a syntax error
    printPattern(N);
    return 0;
}