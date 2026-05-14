#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but common for array fills

// Syntax Error: Missing closing parenthesis in function signature
void fill_array_sequential(int* arr, int size 
{
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}

int main() {
    // Test Case 1
    int size1 = 5;
    std::vector<int> vec1(size1);
    // The program will fail to compile due to the syntax error in fill_array_sequential
    // If it were to compile, it would be called like this:
    // fill_array_sequential(vec1.data(), size1);
    // for (int i = 0; i < size1; ++i) {
    //     std::cout << vec1[i] << (i == size1 - 1 ? "" : " ");
    // }
    // std::cout << std::endl;

    // Test Case 2
    int size2 = 3;
    std::vector<int> vec2(size2);
    // fill_array_sequential(vec2.data(), size2);
    // for (int i = 0; i < size2; ++i) {
    //     std::cout << vec2[i] << (i == size2 - 1 ? "" : " ");
    // }
    // std::cout << std::endl;

    std::cout << "This program contains a syntax error and will not compile." << std::endl;

    return 0;
}