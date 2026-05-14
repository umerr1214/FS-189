#include <iostream>

class ResourceTracker {
public:
    int* data;
    int size;

    ResourceTracker(int s) : size(s), data(nullptr) {
        if (size > 0) {
            data = new int[size];
            std::cout << "ResourceTracker(size=" << size << ") constructed, memory allocated at " << data << std::endl;
            for (int i = 0; i < size; ++i) {
                data[i] = i * 10 + 1;
            }
        } else {
            std::cout << "ResourceTracker(size=0) constructed, no memory allocated." << std::endl;
        }
    }

    // Logical Error: No custom copy constructor or copy assignment operator is provided.
    // The default compiler-generated versions perform shallow copies, leading to
    // multiple ResourceTracker objects owning the same dynamic memory.

    ~ResourceTracker() {
        if (data != nullptr) {
            std::cout << "ResourceTracker(size=" << size << ") destructed, memory at " << data << " deallocated" << std::endl;
            delete[] data;
            data = nullptr; // Good practice after deallocation
        } else {
            std::cout << "ResourceTracker(size=" << size << ") destructed, no memory to deallocate (or already deallocated)." << std::endl;
        }
    }

    void printData() const {
        if (data == nullptr || size == 0) {
            std::cout << "Data: (empty or invalid)" << std::endl;
            return;
        }
        std::cout << "Data: [";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << (i == size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

void demonstrateCopyIssue() {
    std::cout << "\n--- Creating originalTracker ---" << std::endl;
    ResourceTracker originalTracker(3);
    originalTracker.printData();

    std::cout << "\n--- Creating copiedTracker (shallow copy) ---" << std::endl;
    ResourceTracker copiedTracker = originalTracker; // Calls default copy constructor
    copiedTracker.printData();

    // Modify originalTracker's data to show they point to the same memory
    if (originalTracker.data != nullptr) {
        originalTracker.data[0] = 999;
        std::cout << "\n--- Modified originalTracker's data[0] ---" << std::endl;
        originalTracker.printData();
        copiedTracker.printData(); // Will show the modification because of shallow copy
    }

    std::cout << "\n--- copiedTracker scope ending ---" << std::endl;
    // copiedTracker's destructor will be called here, freeing the memory.
    // originalTracker's data pointer will become dangling.
} // copiedTracker destructs here

int main() {
    std::cout << "Program start" << std::endl;
    demonstrateCopyIssue(); // This function will cause a double-free when originalTracker destructs
    std::cout << "Program end" << std::endl;
    // originalTracker destructs here, attempting to deallocate memory already freed by copiedTracker.
    return 0;
}