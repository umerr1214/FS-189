#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n1;
    std::cout << "Enter the size of the first array: ";
    std::cin >> n1;

    std::vector<int> arr1(n1);
    std::cout << "Enter " << n1 << " elements for the first array: ";
    for (int i = 0; i < n1; ++i) {
        std::cin >> arr1[i];
    }

    int n2;
    std::cout << "Enter the size of the second array: ";
    std::cin >> n2;

    std::vector<int> arr2(n2);
    std::cout << "Enter " << n2 << " elements for the second array: ";
    for (int i = 0; i < n2; ++i) {
        std::cin >> arr2[i];
    }

    // Semantic error: The concatenated array is allocated with size n1,
    // but then attempts to write n1 + n2 elements into it, leading to
    // out-of-bounds access and undefined behavior.
    std::vector<int> concatenated_arr(n1); // Should be (n1 + n2)

    for (int i = 0; i < n1; ++i) {
        concatenated_arr[i] = arr1[i];
    }

    for (int i = 0; i < n2; ++i) {
        // This access (concatenated_arr[n1 + i]) will be out of bounds
        // for i > 0 if n2 > 0, as concatenated_arr only has size n1.
        concatenated_arr[n1 + i] = arr2[i];
    }

    std::cout << "Concatenated array: ";
    int total_size = n1 + n2; // total_size is correctly calculated but not used for vector capacity
    for (int i = 0; i < total_size; ++i) { // This loop might also access out of bounds if total_size > n1
        std::cout << concatenated_arr[i] << (i == total_size - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}