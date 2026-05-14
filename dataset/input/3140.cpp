#include <iostream>
#include <cstring> // For strlen

class FileManager {
private:
    char* filePath;
    size_t pathLength; 

public:
    // Constructor
    FileManager(const char* path) : filePath(nullptr), pathLength(0) {
        if (path) {
            pathLength = std::strlen(path);
            filePath = new char[pathLength + 1];

            // READABILITY / EFFICIENCY ISSUE:
            // Manual character-by-character copy loop instead of using standard library functions
            // like std::strcpy, std::strncpy, std::memcpy, or simply std::string.
            // This is less readable, more verbose, and potentially less efficient for large strings
            // compared to optimized library implementations.
            for (size_t i = 0; i <= pathLength; ++i) { // Copy including null terminator
                filePath[i] = path[i];
            }
            std::cout << "FileManager created with path: " << filePath << std::endl;
        } else {
            // Even for an empty path, allocate minimal memory for null terminator
            filePath = new char[1];
            filePath[0] = '\0';
            std::cout << "FileManager created with an empty path." << std::endl;
        }
    }

    // Destructor
    ~FileManager() {
        if (filePath) {
            std::cout << "Deallocating memory for path: " << filePath << std::endl;
            delete[] filePath;
            filePath = nullptr;
        }
    }

    // For simplicity and to focus on the constructor's issue,
    // copy constructor and copy assignment operator are omitted.
    // If they were present, they would likely repeat the same inefficient copy logic.

    void displayPath() const {
        std::cout << "Current file path: " << (filePath ? filePath : "[empty]") << std::endl;
    }
};

int main() {
    std::cout << "--- Readability / Efficiency Issue (3140) ---" << std::endl;

    FileManager fm1("documents/report_final.txt");
    fm1.displayPath();

    FileManager fm2("logs/system_events.log");
    fm2.displayPath();

    FileManager fm3(nullptr); // Test with nullptr path
    fm3.displayPath();

    std::cout << "\nObjects will now go out of scope." << std::endl;

    return 0;
}