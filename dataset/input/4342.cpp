#include <iostream>
#include <vector>

using namespace std // Missing semicolon here

int main() {
    int arr[5];

    std::cout << "Enter 5 integers:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Array elements in reverse order:" << std::endl;
    for (int i = 4; i >= 0; --i) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}