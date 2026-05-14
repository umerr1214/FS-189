#include <iostream>

int main() {
    int N;
    std::cout << "Enter a positive integer N: ";
    std::cin >> N; // No input validation or error checking for cin failure

    long long sum_even = 0; // Use long long for sum to prevent potential overflow for very large N, though N's range isn't specified.

    // The loop naturally handles N <= 1 by not executing, resulting in sum_even = 0.
    // However, it doesn't explicitly inform the user if N is not positive as required.
    for (int i = 2; i <= N; i += 2) {
        sum_even += i;
    }

    std::cout << "The sum of even numbers between 1 and " << N << " is: " << sum_even << std::endl;

    return 0;
}