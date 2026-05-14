#include <iostream>
#include <limits> // Required for std::numeric_limits

void solve(std::istream& in, std::ostream& out) {
    int N;
    out << "Enter a positive integer N: ";
    
    // Robust input validation loop:
    // 1. Checks if the input operation was successful (`in >> N`).
    // 2. If not, clears error flags and discards invalid input.
    // 3. Checks if N is positive as required by the problem statement.
    // 4. Reprompts the user until valid input is received.
    while (!(in >> N) || N <= 0) {
        if (in.fail()) {
            out << "Invalid input. Please enter an integer: ";
            in.clear(); // Clear error flags
            // Discard all characters in the input buffer until a newline is found
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        } else { // N was an integer but not positive
            out << "N must be a positive integer. Please enter a positive integer N: ";
        }
    }

    long long sum = 0;
    // Efficient and readable approach: iterate directly over even numbers.
    // Starts from 2 and increments by 2, ensuring only even numbers are processed.
    // Correctly handles N=1 (loop doesn't run, sum remains 0).
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    out << "The sum of even numbers is: " << sum << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}