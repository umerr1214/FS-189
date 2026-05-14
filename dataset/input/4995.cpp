#include <iostream>
#include <vector>
#include <algorithm> // Required for std::copy
#include <limits>    // Required for std::numeric_limits

// Function to get a positive integer size from the user with input validation
int get_array_size(const std::string& prompt) {
    int size;
    while (true) {
        std::cout << prompt;
        std::cin >> size;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (size < 0) {
            std::cout << "Array size cannot be negative. Please enter a non-negative integer." << std::endl;
        } else {
            // Valid size entered
            return size;
        }
    }
}

// Function to get array elements from the user
void get_array_elements(std::vector<int>& arr, int size, const std::string& array_name) {
    std::cout << "Enter " << size << " elements for " << array_name << ":" << std::endl;
    arr.resize(size); // Ensure the vector has the correct size
    for (int i = 0; i < size; ++i) {
        while (true) {
            std::cout << "Element " << i + 1 << ": ";
            std::cin >> arr[i];
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter an integer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break; // Valid integer entered
            }
        }
    }
}

// Function to print a vector
void print_array(const std::vector<int>& arr, const std::string& array_name) {
    std::cout << array_name << ": ";
    if (arr.empty()) {
        std::cout << "(empty)";
    } else {
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
        }
    }
    std::cout << std::endl;
}

int main() {
    // Get sizes for the two arrays with validation
    int array1_size = get_array_size("Enter the size of the first array: ");
    int array2_size = get_array_size("Enter the size of the second array: ");

    // Declare vectors for the two arrays
    std::vector<int> array1;
    std::vector<int> array2;

    // Get elements for the first array
    get_array_elements(array1, array1_size, "the first array");

    // Get elements for the second array
    get_array_elements(array2, array2_size, "the second array");

    // Create a third vector for the concatenated result
    // Reserve space to avoid multiple reallocations, improving efficiency
    std::vector<int> concatenated_array;
    concatenated_array.reserve(array1.size() + array2.size());

    // Concatenate array1 elements
    concatenated_array.insert(concatenated_array.end(), array1.begin(), array1.end());

    // Concatenate array2 elements
    concatenated_array.insert(concatenated_array.end(), array2.begin(), array2.end());

    // Print the original and concatenated arrays for clarity
    print_array(array1, "First array");
    print_array(array2, "Second array");
    print_array(concatenated_array, "Concatenated array");

    return 0;
}