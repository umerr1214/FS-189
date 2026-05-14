#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N;

    // Semantic Error: 'sum' is declared inside the loop,
    // making it local to the loop's scope.
    // It will be re-initialized in each iteration and will be out of scope
    // when std::cout tries to use it after the loop.
    // This will cause a compilation error (undeclared identifier 'sum').
    for (int i = 2; i <= N; i += 2) {
        int sum = 0; // 'sum' is local to this block
        sum += i;
    }

    std::cout << "Sum of even numbers between 1 and " << N << " is: " << sum << std::endl; // Error: 'sum' is undeclared here
    return 0;
}