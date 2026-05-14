#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> nums(3);
    std::cin >> nums[0] >> nums[1] >> nums[2];

    // Sort the vector to easily find the middle element.
    // For three distinct numbers, the middle element will always be at index 1 after sorting.
    std::sort(nums.begin(), nums.end());

    std::cout << nums[1] << std::endl;

    return 0;
}