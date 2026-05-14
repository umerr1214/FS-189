#include <iostream>
#include <array>

int main() {
    std::array<int, 5> arr = {10, 20, 30, 40, 50};
    int searchNum;
    bool found = false;
    int index = -1;

    std::cout << "Enter a number to search for: ";
    std::cin >> searchNum

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == searchNum) {
            found = true;
            index = i;
            break;
        }
    }

    if (found) {
        std::cout << index << std::endl;
    } else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}