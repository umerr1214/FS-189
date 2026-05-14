#include <iostream>
#include <vector> // Included for general C++ practice, though not strictly used with fixed array.

const int MAX_SIZE = 10; // Fixed size for the array

void solve(std::istream& is, std::ostream& os) {
    int n;
    is >> n;

    // Robustness issue: No check if n exceeds MAX_SIZE.
    // This will lead to a buffer overflow if n > MAX_SIZE,
    // as elements will be written outside the allocated memory.
    int arr[MAX_SIZE]; 
    for (int i = 0; i < n; ++i) { 
        is >> arr[i];
    }

    int target;
    is >> target;

    int count = 0;
    // If n > MAX_SIZE, this loop might access out-of-bounds memory
    // that was previously written to, or entirely uninitialized memory,
    // leading to undefined behavior or a crash.
    for (int i = 0; i < n; ++i) { 
        if (arr[i] == target) {
            count++;
        }
    }
    os << count;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}