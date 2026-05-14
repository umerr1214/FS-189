#include <iostream>

int main() {
    int N;
    std::cout << "Enter the number of rows: ";
    std::cin >> N // Missing semicolon here, causing a syntax error

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}