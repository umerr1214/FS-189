#include <iostream>
#include <vector>
#include <limits> // Required for std::numeric_limits

// This program attempts to find the second largest element
// but contains a robustness issue that causes it to fail
// on certain inputs, particularly when the largest element
// appears multiple times or when all elements are identical.
int user_main() {
    std::vector<int> arr(5);
    for (int i = 0; i < 5; ++i) {
        std::cin >> arr[i];
    }

    int first_max = std::numeric_limits<int>::min();
    int second_max = std::numeric_limits<int>::min();

    for (int i = 0; i < 5; ++i) {
        if (arr[i] > first_max) {
            // New largest element found
            second_max = first_max;
            first_max = arr[i];
        } else if (arr[i] > second_max) {
            // Robustness issue: This condition should ideally also check
            // that arr[i] is NOT equal to first_max to find a *distinct*
            // second largest. Without it, if first_max appears again and is
            // greater than the current second_max, second_max gets incorrectly
            // updated to the value of first_max.
            second_max = arr[i];
        }
    }

    // If, after the loop, second_max is still INT_MIN, it implies either
    // all elements were INT_MIN, or all elements were the same positive value.
    // In the latter case, the largest element itself can be considered the
    // "second largest" by some interpretations. However, the current flawed
    // logic might leave second_max as INT_MIN for "all same" cases, or
    // incorrectly update it to first_max for duplicate largest values.
    // Example failure: Input `50 40 30 50 20`, Expected `40`, Actual `50`.
    // Example failure: Input `10 10 10 10 10`, Expected `10`, Actual `INT_MIN` (or a very small number).
    // The current logic will output INT_MIN for `10 10 10 10 10` if `first_max` gets 10,
    // and subsequent 10s are not `> first_max`, and also not `> second_max` (if second_max is still INT_MIN).
    // Let's verify `10 10 10 10 10`:
    // 1. arr[0]=10: first_max=10, second_max=INT_MIN
    // 2. arr[1]=10: 10 is not > first_max (10). 10 is > second_max (INT_MIN). second_max becomes 10.
    // 3. arr[2]=10: 10 is not > first_max (10). 10 is not > second_max (10).
    // So, for 10 10 10 10 10, it outputs 10, which is correct.
    // The primary robustness issue is `50 40 30 50 20` -> 50.

    std::cout << second_max << std::endl;

    return 0;
}

// Wrapper main for standalone compilation and execution
int main() {
    return user_main();
}