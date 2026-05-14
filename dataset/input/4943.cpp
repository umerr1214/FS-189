#include <iostream>

int main()
{
    int limit;
    long long sum = 0;
    std::cout << "Enter a positive integer limit: ";
    std::cin >> limit;

    if (limit <= 0) {
        std::cout << "Limit must be a positive integer." << std::endl;
        return 1; // Indicate error
    }

    for (int i = 1; i <= limit; ++i) {
        // Logical error: Summing ALL numbers, not just even ones.
        sum += i;
    }

    std::cout << "The sum of even numbers from 1 to " << limit << " is: " << sum << std::endl;

    return 0;
}