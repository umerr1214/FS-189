#include <iostream>

class ResourceTracker {
public:
    int* data;
    int size;

    ResourceTracker(int s) : size(s), data(nullptr) {
        if (s > 0) {
            data = new int[s];
            std::cout << "ResourceTracker(size=" << size << ") constructed, memory allocated at " << data << std::endl;
            for (int i = 0; i < size; ++i) {
                data[i] = i * 10 + 2;
            }
        } else {
            std::cout << "ResourceTracker(size=0) constructed, no memory allocated." << std::endl;
        }
    }

    ~ResourceTracker() {
        if (data != nullptr) {
            std::cout << "ResourceTracker(size=" << size << ") destructed, memory at " << data << " deallocated" << std::endl;
            delete[] data;
            // The pointer 'data' is not set to nullptr after deletion in destructor.
            // This is generally fine if the object is truly being destroyed,
            // but combined with the 'reset_and_leak_dangling' method, it leads to a double-free.
        } else {
            std::cout << "ResourceTracker(size=" << size << ") destructed, no memory to deallocate (or already deallocated)." << std::endl;
        }
    }

    // Semantic Error: This method deallocates memory but leaves the 'data' pointer dangling
    // and modifies 'size' without setting 'data' to nullptr, setting up a double-free.
    void reset_and_leak_dangling() {
        if (data != nullptr) {
            std::cout << "Resetting ResourceTracker, deallocating memory at " << data << " (leaving dangling pointer)" << std::endl;
            delete[] data;
            // 'data' is now a dangling pointer. It is NOT set to nullptr.
            // This is the core semantic error that leads to a double-free when the destructor runs.
        }
        size = 0; // Setting size to 0 makes subsequent printData calls safe,
                  // but 'data' itself is still a dangling pointer.
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

void demonstrateSemanticIssue() {
    std::cout << "\n--- Creating tracker_sem ---" << std::endl;
    ResourceTracker tracker_sem(4);
    tracker_sem.printData();

    std::cout << "\n--- Calling reset_and_leak_dangling() ---" << std::endl;
    tracker_sem.reset_and_leak_dangling(); // Frees memory, leaves 'data' dangling, sets size to 0.

    std::cout << "Attempting to print data after reset (should be empty/invalid):" << std::endl;
    tracker_sem.printData(); // This is safe because size is 0.

    std::cout << "\n--- tracker_sem scope ending (destructor will cause double-free) ---" << std::endl;
} // tracker_sem destructs here, attempting to delete the dangling pointer 'data' again.

int main() {
    std::cout << "Program start" << std::endl;
    demonstrateSemanticIssue();
    std::cout << "Program end" << std::endl;
    return 0;
}