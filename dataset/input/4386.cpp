#include <iostream>
#include <string> // Required for std::string

void printPattern(int N) {
    for (int i = 1; i <= N; ++i) {
        // Semantic error: Uses std::string constructor instead of a nested 'for' loop
        // The problem explicitly asks for "nested 'for' loops".
        std::cout << std::string(i, '*') << "\n"; 
    }
}

int main() {
    int N;
    std::cout << "Enter the number of rows: ";
    std::cin >> N;
    printPattern(N);
    return 0;
}