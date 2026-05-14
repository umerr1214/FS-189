#include <iostream>
#include <cstring> // For strlen, strcpy

class FileManager {
public:
    char* filePath;

    FileManager(const char* path) {
        if (path) {
            // LOGICAL ERROR: Allocating strlen(path) instead of strlen(path) + 1
            // This means there is no space for the null terminator.
            // strcpy will write past the allocated memory, leading to a buffer overflow.
            filePath = new char[strlen(path)]; // Should be strlen(path) + 1
            strcpy(filePath, path); // This operation causes a buffer overflow
            std::cout << "FileManager created for: " << filePath << std::endl;
        } else {
            filePath = nullptr;
            std::cout << "FileManager created with null path." << std::endl;
        }
    }

    ~FileManager() {
        if (filePath) {
            std::cout << "FileManager destroying path: " << filePath << std::endl;
            delete[] filePath;
            filePath = nullptr;
        } else {
            std::cout << "FileManager destroying null path." << std::endl;
        }
    }
    
    void printPath() const {
        if (filePath) {
            std::cout << "Current file path: " << filePath << std::endl;
            // The actual length of the string might be longer than allocated due to overflow
            // std::cout << "String length (potentially incorrect due to overflow): " << strlen(filePath) << std::endl;
        } else {
            std::cout << "Current file path: (null)" << std::endl;
        }
    }
};

int main() {
    std::cout << "--- Demonstrating Logical Error (Buffer Overflow) ---" << std::endl;
    // For a short string, the overflow might not immediately crash,
    // but it's undefined behavior and can corrupt memory.
    FileManager fm1("short.txt"); // strlen is 9. Allocates 9 bytes. strcpy writes 10 bytes including null terminator.
    fm1.printPath();

    FileManager fm2("another_long_file_path_name.docx"); // More likely to cause noticeable issues or crash
    fm2.printPath();

    FileManager fm3(nullptr);
    fm3.printPath();
    std::cout << "--- End Demonstration ---" << std::endl;

    return 0;
}