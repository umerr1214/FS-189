#include <iostream>
#include <vector>
#include <string>

// Function containing the main logic for testing
int solve_and_print() {
    int data_elements[8] = {10, 20, 5, 30, 40, 50, 60, 70};
    int search_val;
    int result_idx = -1; // Stores the index if found
    bool found_flag = false; // Flag to indicate if the value was found

    std::cout << "Enter the integer to search: ";
    std::cin >> search_val;

    // Readability/Efficiency issue:
    // 1. Uses a boolean flag and iterates through the entire array even after finding the element.
    //    A simple 'break' would suffice and improve efficiency slightly for larger arrays.
    // 2. Variable names like `data_elements`, `search_val`, `result_idx`, `found_flag` are okay,
    //    but could be more concise or consistent (e.g., `arr`, `target`, `index`, `found`).
    // 3. Magic number '8' is used directly instead of a named constant.
    // 4. Poor formatting (e.g., inconsistent spacing, lack of empty lines).
    
    for (int loop_counter = 0; loop_counter < 8; ++loop_counter) {
        if (data_elements[loop_counter] == search_val) {
            result_idx = loop_counter;
            found_flag = true; // Set flag but continue iterating
        }
    }

    if (found_flag) {
        std::cout << "Found at index " << result_idx << std::endl;
    } else {
        std::cout << "Not present" << std::endl;
    }

    return 0;
}

int main() {
    return solve_and_print();
}