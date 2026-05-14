#include <iostream>

int main() {
    int N;
    std::cin >> N;
    // Semantic Error: 'sum' is declared as 'int', which can lead to integer overflow
    // if N is large, as the sum of even numbers can exceed INT_MAX.
    int sum = 0; 
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}