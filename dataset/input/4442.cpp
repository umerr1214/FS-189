#include <iostream>
#include <vector>

// Readability / Efficiency Issue:
// 1. Inefficient: It continues to iterate through the entire array even after finding the target.
//    A standard linear search should return immediately upon finding the first occurrence.
// 2. Behavior deviation: Because it continues searching, it effectively returns the index
//    of the *last* occurrence if the target appears multiple times, which might not be
//    the expected behavior for a simple "find the index" function (usually implies the first).
int linearSearch(int arr[], int size, int target) {
    int foundIndex = -1; // Stores the index of the last found target
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            foundIndex = i; // Update foundIndex. Does not return or break.
        }
    }
    return foundIndex;
}

int main() {
    struct TestCase {
        std::vector<int> arr_vec;
        int size;
        int target;
        int expected;
        const char* description;
    };

    std::vector<TestCase> testCases = {
        {{1, 5, 2, 8, 3}, 5, 8, 3, "Target found in middle"},
        {{10, 20, 30, 40}, 4, 10, 0, "Target found at beginning"},
        {{5, 4, 3, 2, 1}, 5, 1, 4, "Target found at end"},
        {{7, 8, 9}, 3, 10, -1, "Target not found"},
        {{}, 0, 5, -1, "Empty array"},
        {{1}, 1, 1, 0, "Single element array, target found"},
        {{1}, 1, 2, -1, "Single element array, target not found"},
        {{1, 2, 3, 2, 4}, 5, 2, 3, "Target with duplicates (returns last occurrence)"},
        {{5, 5, 5}, 3, 5, 2, "All elements are target (returns last occurrence)"}
    };

    for (const auto& tc : testCases) {
        int result = linearSearch(tc.arr_vec.data(), tc.size, tc.target);
        std::cout << "Test Case: " << tc.description << std::endl;
        std::cout << "  Array: [";
        if (tc.size > 0) {
            for (int i = 0; i < tc.size; ++i) {
                std::cout << tc.arr_vec[i] << (i == tc.size - 1 ? "" : ", ");
            }
        }
        std::cout << "], Size: " << tc.size << ", Target: " << tc.target << std::endl;
        std::cout << "  Expected: " << tc.expected << ", Got: " << result << std::endl;
        std::cout << (result == tc.expected ? "  PASS" : "  FAIL") << std::endl << std::endl;
    }

    return 0;
}