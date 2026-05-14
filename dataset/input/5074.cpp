#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    int sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }

    // Syntax Error: Missing semicolon after sum
    std::cout << "Sum of even numbers between 1 and " << N << " is: " << sum std::endl;
    return 0;
}