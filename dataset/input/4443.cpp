#include <iostream>
#include <vector>
#include <cstddef> // For nullptr_t

// Correct Version: Implements linear search correctly and efficiently.
// Handles edge cases like empty arrays or null pointers gracefully.
int linearSearch(int arr[], int size, int target) {
    // Robustness check for null pointer or invalid size
    if (arr == nullptr || size <= 0) {
        return -1;
    }

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return immediately upon finding the first occurrence (efficient)
        }
    }
    return -1; // Target not found
}

int main() {
    struct TestCase {
        std::vector<int> arr_vec;
        int size;
        int target;
        int expected;
        const char* description;
        bool pass_null_arr = false; // Flag for null pointer test
    };

    std::vector<TestCase> testCases = {
        {{1, 5, 2, 8, 3}, 5, 8, 3, "Target found in middle"},
        {{10, 20, 30, 40}, 4, 10, 0, "Target found at beginning"},
        {{5, 4, 3, 2, 1}, 5, 1, 4, "Target found at end"},
        {{7, 8, 9}, 3, 10, -1, "Target not found"},
        {{}, 0, 5, -1, "Empty array"},
        {{1}, 1, 1, 0, "Single element array, target found"},
        {{1}, 1, 2, -1, "Single element array, target not found"},
        {{1, 2, 3, 2, 4}, 5, 2, 1, "Target with duplicates (returns first occurrence)"},
        {{5, 5, 5}, 3, 5, 0, "All elements are target (returns first occurrence)"},
        {{}, -5, 10, -1, "Negative size (robustness check)"},
        {{}, 0, 7, -1, "Null array pointer with size 0 (robustness check)", true},
        {{}, 5, 7, -1, "Null array pointer with positive size (robustness check)", true}
    };

    for (const auto& tc : testCases) {
        int result;
        std::cout << "Test Case: " << tc.description << std::endl;
        std::cout << "  Array: [";
        if (tc.pass_null_arr) {
            std::cout << "nullptr";
            result = linearSearch(nullptr, tc.size, tc.target);
        } else {
            if (tc.size > 0) {
                for (int i = 0; i < tc.size; ++i) {
                    std::cout << tc.arr_vec[i] << (i == tc.size - 1 ? "" : ", ");
                }
            }
            result = linearSearch(tc.arr_vec.data(), tc.size, tc.target);
        }
        std::cout << "], Size: " << tc.size << ", Target: " << tc.target << std::endl;
        std::cout << "  Expected: " << tc.expected << ", Got: " << result << std::endl;
        std::cout << (result == tc.expected ? "  PASS" : "  FAIL") << std::endl << std::endl;
    }

    return 0;
}