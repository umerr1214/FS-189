#include <iostream>
#include <algorithm> // For std::swap

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5; // Missing semicolon here, will cause a compilation error

    int start = 0;
    int end = n - 1;

    while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }

    std::coutt << "Reversed array: "; // Typo: std::coutt instead of std::cout
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}