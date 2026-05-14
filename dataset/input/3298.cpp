#include <iostream>

int main() {
    int N // Syntax Error: Missing semicolon
    std::cin >> N;
    long long sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}