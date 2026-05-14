#include <iostream>

int main() {
    int N;
    std::cin >> N;
    long long sum = 0;
    // Logical Error: Sums all numbers from 1 to N, instead of only even numbers.
    for (int i = 1; i <= N; ++i) { 
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}