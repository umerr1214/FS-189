#include <iostream>

void solve(std::istream& in, std::ostream& out) {
    int N;
    out << "Enter a positive integer N: ";
    in >> N;

    long long sum = 0;
    // This approach iterates through all numbers from 1 to N,
    // and for each number, it performs a modulo operation to check if it's even.
    // While functionally correct, it's less efficient than directly iterating
    // over only the even numbers (e.g., starting from 2 and incrementing by 2).
    // For very large N, this difference in efficiency can be significant.
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    out << "The sum of even numbers is: " << sum << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}