#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> // For std::remove_if, std::isspace

// Function to find a pointer to the maximum element in an integer array.
// This version has a robustness issue: it does not handle size <= 0 or arr == nullptr gracefully.
// It attempts to dereference `*arr` for initialization, leading to undefined behavior or a crash
// (segmentation fault) if `arr` is nullptr or `size` is 0.
int* findMaxPointer(int* arr, int size) {
    // Robustness issue: This line will cause a crash (segmentation fault) or undefined behavior
    // if `arr` is a nullptr or if `size` is 0 (accessing arr[0] out of bounds for an empty array).
    int max_val = *arr; // Problematic if arr is nullptr or size is 0
    int* current_max_ptr = arr;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max_val) {
            max_val = *(arr + i);
            current_max_ptr = arr + i;
        }
    }
    return current_max_ptr;
}

// Helper function to parse input string "{val1,val2,...}:size" or "null:size"
// and run a test, returning the result as a string.
std::string run_test_and_get_output(const std::string& input_str, int* (*func_ptr)(int*, int)) {
    std::vector<int> arr_vec_storage; // Use a vector to manage memory for non-null arrays
    int* arr_ptr = nullptr;
    int size_val = 0;
    bool is_null_input_arr = false;

    size_t colon_pos = input_str.find(':');
    if (colon_pos == std::string::npos) {
        return "ERROR: Invalid input format (missing colon)";
    }

    std::string arr_part = input_str.substr(0, colon_pos);
    std::string size_part = input_str.substr(colon_pos + 1);

    try {
        size_val = std::stoi(size_part);
    } catch (const std::exception& e) {
        return "ERROR: Invalid size in input: " + std::string(e.what());
    }

    if (arr_part == "null") {
        is_null_input_arr = true;
        arr_ptr = nullptr; // Explicitly set to nullptr
    } else {
        if (arr_part.length() < 2 || arr_part[0] != '{' || arr_part.back() != '}') {
            return "ERROR: Invalid array part format (missing braces)";
        }
        std::string content = arr_part.substr(1, arr_part.length() - 2);
        if (!content.empty()) {
            std::stringstream ss(content);
            std::string item;
            while (std::getline(ss, item, ',')) {
                item.erase(0, item.find_first_not_of(" \t\n\r\f\v"));
                item.erase(item.find_last_not_of(" \t\n\r\f\v") + 1);
                try {
                    arr_vec_storage.push_back(std::stoi(item));
                } catch (const std::exception& e) {
                    return "ERROR: Invalid array element: " + std::string(e.what());
                }
            }
        }
        if (!arr_vec_storage.empty()) {
            arr_ptr = arr_vec_storage.data();
        }
        // If arr_vec_storage is empty (e.g., input "{}"), arr_ptr remains nullptr.
        // The problem statement implies `arr` points to the *first element* of an array of `size`.
        // If size > 0, it expects valid elements. If arr_vec_storage is empty and size_val > 0,
        // this represents an inconsistent state for the underlying array data.
        // For testing robustness issues, we let the `findMaxPointer` function behave as written.
    }

    // Call the user's function and attempt to catch crashes/UB
    try {
        int* result_ptr = func_ptr(arr_ptr, size_val);

        if (result_ptr == nullptr) {
            return "nullptr";
        } else {
            // Validation: Ensure the returned pointer is within the bounds of the original array
            if (is_null_input_arr) {
                return "ERROR: Returned non-nullptr for null input";
            }
            if (arr_ptr == nullptr && size_val > 0) {
                return "ERROR: Returned non-nullptr for empty array (size > 0)";
            }
            if (arr_ptr != nullptr && (result_ptr < arr_ptr || result_ptr >= arr_ptr + size_val)) {
                return "ERROR: Pointer out of bounds";
            }
            return std::to_string(*result_ptr);
        }
    } catch (const std::exception& e) {
        return "runtime error (exception: " + std::string(e.what()) + ")";
    } catch (...) {
        return "runtime error (unknown)";
    }
}

int main() {
    std::cout << "Test Case 1: Array {10, 5, 20, 15, 30}, Size 5" << std::endl;
    std::cout << "Expected: 30" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{10,5,20,15,30}:5", findMaxPointer) << std::endl << std::endl;

    std::cout << "Test Case 2: Array {-1, -5, -2, -8}, Size 4" << std::endl;
    std::cout << "Expected: -1" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{-1,-5,-2,-8}:4", findMaxPointer) << std::endl << std::endl;

    std::cout << "Test Case 3: Array {7}, Size 1" << std::endl;
    std::cout << "Expected: 7" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{7}:1", findMaxPointer) << std::endl << std::endl;

    std::cout << "Test Case 4: Array {5, 5, 5}, Size 3" << std::endl;
    std::cout << "Expected: 5" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{5,5,5}:3", findMaxPointer) << std::endl << std::endl;

    std::cout << "Test Case 5: Array {1, 2, 3, 4, 5}, Size 5" << std::endl;
    std::cout << "Expected: 5" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{1,2,3,4,5}:5", findMaxPointer) << std::endl << std::endl;

    std::cout << "Test Case 6: Empty Array {}, Size 0 (Robustness Issue)" << std::endl;
    std::cout << "Expected: runtime error" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("{}:0", findMaxPointer) << std::endl << std::endl; // Expects crash

    std::cout << "Test Case 7: Null Pointer Array, Size 5 (Robustness Issue)" << std::endl;
    std::cout << "Expected: runtime error" << std::endl;
    std::cout << "Actual: " << run_test_and_get_output("null:5", findMaxPointer) << std::endl << std::endl; // Expects crash

    return 0;
}