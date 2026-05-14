#include <iostream>
#include <vector> // Using std::vector but with poor readability choices

void solve(std::istream& is, std::ostream& os) {
    int sz; // Variable for array size
    is >> sz; // Read the size from input

    std::vector<int> ar(sz); // Create a vector to store array elements
    for (int idx = 0; idx < sz; ++idx) { // Loop through indices to fill the vector
        is >> ar[idx]; // Read each element into the vector
    }

    int t; // Variable for the target number
    is >> t; // Read the target number from input

    int cnt = 0; // Counter for occurrences
    for (int idx = 0; idx < sz; ++idx) { // Loop through the vector again
        if (ar[idx] == t) { // Check if the current element matches the target
            cnt++; // Increment counter if it matches
        }
    }
    os << cnt; // Output the final count
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}