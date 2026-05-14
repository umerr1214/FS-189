#include <iostream>

void solve(std::istream& in, std::ostream& out) {
    int N;
    out << "Enter a positive integer N: ";
    in >> N; // No input validation for type or value

    long long sum = 0;
    // The loop correctly handles N <= 0 by not executing, resulting in sum = 0.
    // However, it does not explicitly validate N as positive as implied by the prompt.
    // More importantly, it does not handle non-integer input gracefully.
    // If 'in >> N' fails (e.g., input is "abc"), N's value is indeterminate (often 0),
    // and the stream's failbit is set. The loop won't run, and 'sum' will be 0,
    // which is misleading for an invalid input.
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    out << "The sum of even numbers is: " << sum << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}