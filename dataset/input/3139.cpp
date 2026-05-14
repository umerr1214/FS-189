#include <iostream>
#include <cstring> // For strlen, memcpy

// Function that takes FileManager by value (forward declaration)
class FileManager;
void processFileManager(FileManager fm);

class FileManager {
public:
    char* filePath;

    // Constructor
    FileManager(const char* path) : filePath(nullptr) {
        if (path) {
            size_t len = std::strlen(path);
            filePath = new char[len + 1];
            std::memcpy(filePath, path, len + 1); // Copy including null terminator
        } else {
            // Handle nullptr path by allocating an empty string
            filePath = new char[1];
            filePath[0] = '\0';
        }
        std::cout << "FileManager created for path: " << (filePath ? filePath : "[nullptr input]") << " (internal addr: " << static_cast<void*>(filePath) << ")" << std::endl;
    }

    // Destructor
    ~FileManager() {
        if (filePath) {
            std::cout << "Deallocating memory for path: " << filePath << " (internal addr: " << static_cast<void*>(filePath) << ")" << std::endl;
            delete[] filePath;
            filePath = nullptr;
        }
    }

    // CRITICAL ROBUSTNESS ISSUE:
    // No copy constructor or copy assignment operator implemented.
    // The compiler will generate default shallow copy semantics.
    // This means when a FileManager object is copied, only the 'filePath' pointer is copied,
    // not the memory it points to. Both objects will then point to the same memory.
    // When one object is destroyed, it deallocates the shared memory.
    // When the second object is destroyed, it attempts to deallocate the already freed memory,
    // leading to a double-free error and undefined behavior/crash.

    void displayPath() const {
        std::cout << "Displaying path: " << (filePath ? filePath : "[empty]") << " (internal addr: " << static_cast<void*>(filePath) << ")" << std::endl;
    }
};

// Function that takes FileManager by value, triggering a copy
void processFileManager(FileManager fm) {
    std::cout << "  Inside processFileManager (copy created):" << std::endl;
    fm.displayPath();
    std::cout << "  Exiting processFileManager (copy destroyed)." << std::endl;
}

int main() {
    std::cout << "--- Robustness Issue: Missing Rule of Three (3139) ---" << std::endl;

    FileManager fm1("initial/path/file1.txt");
    fm1.displayPath();

    std::cout << "\nCreating fm2 as a copy of fm1 (shallow copy occurs):" << std::endl;
    FileManager fm2 = fm1; // Default copy constructor called, fm2.filePath points to fm1.filePath's memory
    fm2.displayPath();

    std::cout << "\nPassing fm1 to a function by value (another shallow copy occurs):" << std::endl;
    processFileManager(fm1); // Default copy constructor called for function parameter 'fm'

    std::cout << "\n--- Using a block scope to control destruction order for another pair ---" << std::endl;
    {
        FileManager block_fm("block/scope/file.log");
        block_fm.displayPath();

        FileManager block_fm_copy = block_fm; // Shallow copy
        block_fm_copy.displayPath();

        std::cout << "Exiting block scope. block_fm_copy and block_fm will be destroyed." << std::endl;
        // When block_fm_copy is destroyed, it frees memory.
        // When block_fm is destroyed, it attempts to free the SAME memory again (double-free).
    } // Destructors for block_fm_copy and block_fm are called here. Expect a crash or UB.

    std::cout << "\nMain function ending. fm2 and fm1 will be destroyed." << std::endl;
    // When fm2 is destroyed, it frees memory.
    // When fm1 is destroyed, it attempts to free the SAME memory again (double-free).
    // This will likely cause another crash or UB.

    return 0;
}