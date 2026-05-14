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

    int total_size = n1 + n2;
    std::vector<int> concatenated_arr(total_size);

    // Logical error: The second array elements are copied starting from index 0
    // instead of n1, overwriting the elements of the first array.
    for (int i = 0; i < n1; ++i) {
        concatenated_arr[i] = arr1[i];
    }

    for (int i = 0; i < n2; ++i) {
        concatenated_arr[i] = arr2[i]; // Should be concatenated_arr[n1 + i] = arr2[i];
    }

    std::cout << "Concatenated array: ";
    for (int i = 0; i < total_size; ++i) {
        std::cout << concatenated_arr[i] << (i == total_size - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}