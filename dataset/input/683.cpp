#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

void removeDuplicates(char arr[]) {
    // Efficiency Issue: Using O(N) space (unordered_set) and O(N) allocations
    // while O(1) space is possible (using boolean map for ASCII or nested loops O(N^2)).
    // Actually, O(N^2) in-place without extra space is often preferred for constraints where space is tight,
    // OR O(1) space using bool map[256].
    // Here using unordered_set is readable but uses dynamic memory allocation for each insert.
    
    if (arr == nullptr) return;
    
    int n = strlen(arr);
    unordered_set<char> seen;
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            arr[index++] = arr[i];
        }
    }
    arr[index] = '\0';
}

int main() {
    char arr[] = "programming";
    removeDuplicates(arr);
    cout << "Unique characters: " << arr << endl;
    return 0;
}
