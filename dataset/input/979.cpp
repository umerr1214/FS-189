#include <iostream>

class ResourceTracker {
public:
    int* data;
    int size // Missing semicolon here

    ResourceTracker(int s) : size(s) {
        data = new int[size];
        std::cout << "ResourceTracker(size=" << size << ") constructed, memory allocated at " << data << std::endl;
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10;
        }
    }

    ~ResourceTracker() {
        std::cout << "ResourceTracker(size=" << size << ") destructed, memory at " << data << " deallocated" << std::endl;
        delete[] data;
    }

    void printData() const {
        std::cout << "Data: [";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << (i == size - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl;
    }
};

void demonstrateLifecycle() {
    std::cout << "\n--- Creating tracker1 ---" << std::endl;
    ResourceTracker tracker1(5);
    tracker1.printData();
    std::cout << "--- tracker1 scope ending ---" << std::endl;
}

int main() {
    std::cout << "Program start" << std::endl;
    demonstrateLifecycle();
    std::cout << "Program end" << std::endl;
    return 0;
}