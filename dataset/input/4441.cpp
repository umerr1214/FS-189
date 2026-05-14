#include <iostream>
#include <vector>
#include <cstddef> // For nullptr_t

// Robustness Issue: Does not handle a null array pointer.
// If arr is nullptr and size > 0, dereferencing arr[i] will lead to a crash (segmentation fault).
int linearSearch(int arr[], int size, int target) {
    // Missing check: if (arr == nullptr && size > 0) return -1; or throw exception
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct TestCase {
        std::vector<int> arr_vec;
        int size;
        int target;
        int expected;
        const char* description;
        bool pass_null_arr = false; // Flag to indicate passing a null pointer
    };

    std::vector<TestCase> testCases = {
        {{1, 5, 2, 8, 3}, 5, 8, 3, "Target found in middle"},
        {{10, 20, 30, 40}, 4, 10, 0, "Target found at beginning"},
        {{5, 4, 3, 2, 1}, 5, 1, 4, "Target found at end"},
        {{7, 8, 9}, 3, 10, -1, "Target not found"},
        {{}, 0, 5, -1, "Empty array"},
        {{1}, 1, 1, 0, "Single element array, target found"},
        {{1}, 1, 2, -1, "Single element array, target not found"},
        {{}, 5, 10, -1, "Empty array with positive size (should be handled by loop bounds)"}, // This implicitly assumes size 0 if arr_vec is empty
        {{}, 5, 7, -1, "Null array pointer with positive size (EXPECTED CRASH/UB)", true} // This case will trigger the robustness issue
    };

    for (const auto& tc : testCases) {
        int result;
        std::cout << "Test Case: " << tc.description << std::endl;
        std::cout << "  Array: [";
        if (tc.pass_null_arr) {
            std::cout << "nullptr";
            // This call is expected to crash if size > 0
            // For testing purposes, we might catch a signal or run in a sandbox.
            // In a live run, this will likely cause a segmentation fault.
            // We pass a non-zero size to ensure arr[i] is accessed.
            // For this example, we'll just call it and let it crash if it does.
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
        // The last test case is designed to fail/crash, so its "PASS/FAIL" check might be moot
        // for automated testing that expects a crash.
        std::cout << (result == tc.expected ? "  PASS" : "  FAIL (or potential crash for null array)") << std::endl << std::endl;
    }

    return 0;
}