#include <iostream>

void incrementValue(int* ptr) {
    // Semantic error: Instead of incrementing the value *at* ptr,
    // this code reassigns the local 'ptr' variable to point to a newly allocated integer.
    // This results in the original value in main remaining unchanged and causes a memory leak.
    if (ptr != nullptr) {
        int* new_val = new int(*ptr + 1); // Allocate new memory and initialize it
        ptr = new_val; // Reassign local ptr. This does not affect the caller's pointer.
        // The memory pointed to by new_val is not deallocated, leading to a leak.
    }
}

int main() {
    int value = 10;
    std::cout << "Original value: " << value << std::endl;
    incrementValue(&value); // Calls the function, but 'value' in main remains unchanged
    std::cout << "Incremented value: " << value << std::endl; // Will output 10 instead of 11
    return 0;
}