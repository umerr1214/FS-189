#include <iostream>
#include <vector>
// No <algorithm> included to avoid using std::swap, contributing to readability issue

// Function with Readability / Efficiency Issue
// It's functionally correct but uses obscure variable names,
// a slightly convoluted loop structure (do-while), and lacks clarity.
void reverseArray(int* p_data_elements, int element_count) {
    // Handle edge cases explicitly, which is good, but the variable names are poor.
    if (element_count <= 1) {
        return; // No reversal needed for 0 or 1 element
    }

    int left_index_tracker = 0;
    int right_index_tracker = element_count - 1;

    // Using a 'do-while' loop, which is less idiomatic and potentially less clear
    // for this common two-pointer reversal pattern compared to a simple 'for'
    // or 'while (left < right)' loop.
    // The variable names like 'p_data_elements' and 'temporary_holder' are verbose and less readable.
    do {
        // Manual swap implementation instead of using std::swap, adding verbosity.
        int temporary_holder = p_data_elements[left_index_tracker];
        p_data_elements[left_index_tracker] = p_data_elements[right_index_tracker];
        p_data_elements[right_index_tracker] = temporary_holder;

        // Increment and decrement trackers
        left_index_tracker++;
        right_index_tracker--;

        // The loop condition is checked at the end, which can sometimes be less
        // immediately obvious than a pre-check loop.
    } while (left_index_tracker < right_index_tracker);
}

// Helper function to print the contents of a vector
void printArray(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Testing reverseArray with Readability / Efficiency Issue:" << std::endl;

    // Test Case 1: Standard odd number of elements
    std::vector<int> my_array_1 = {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    printArray(my_array_1);
    reverseArray(my_array_1.data(), my_array_1.size());
    std::cout << "Reversed: ";
    printArray(my_array_1);
    std::cout << std::endl;

    // Test Case 2: Even number of elements
    std::vector<int> my_array_2 = {10, 20, 30, 40};
    std::cout << "Original: ";
    printArray(my_array_2);
    reverseArray(my_array_2.data(), my_array_2.size());
    std::cout << "Reversed: ";
    printArray(my_array_2);
    std::cout << std::endl;

    // Test Case 3: Single element array
    std::vector<int> my_array_3 = {100};
    std::cout << "Original: ";
    printArray(my_array_3);
    reverseArray(my_array_3.data(), my_array_3.size());
    std::cout << "Reversed: ";
    printArray(my_array_3);
    std::cout << std::endl;

    // Test Case 4: Empty array
    std::vector<int> my_array_4;
    std::cout << "Original (empty): ";
    printArray(my_array_4);
    reverseArray(my_array_4.data(), my_array_4.size());
    std::cout << "Reversed (empty): ";
    printArray(my_array_4);
    std::cout << std::endl;

    // Test Case 5: Two elements
    std::vector<int> my_array_5 = {55, 66};
    std::cout << "Original: ";
    printArray(my_array_5);
    reverseArray(my_array_5.data(), my_array_5.size());
    std::cout << "Reversed: ";
    printArray(my_array_5);
    std::cout << std::endl;

    return 0;
}