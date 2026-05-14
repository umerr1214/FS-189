#include <iostream>
#include <cstring> // For strlen, strcpy

class FileManager {
public:
    char* filePath;

    FileManager(const char* path) {
        if (path) {
            filePath = new char[strlen(path) + 1];
            strcpy(filePath, path);
            std::cout << "FileManager created for: " << filePath << " (address: " << (void*)filePath << ")" << std::endl;
        } else {
            filePath = nullptr;
            std::cout << "FileManager created with null path." << std::endl;
        }
    }

    // Destructor correctly deallocates memory
    ~FileManager() {
        if (filePath) {
            std::cout << "FileManager destroying path: " << filePath << " (address: " << (void*)filePath << ")" << std::endl;
            delete[] filePath;
            filePath = nullptr;
        } else {
            std::cout << "FileManager destroying null path." << std::endl;
        }
    }
    
    void printPath() const {
        if (filePath) {
            std::cout << "Current file path: " << filePath << std::endl;
        } else {
            std::cout << "Current file path: (null)" << std::endl;
        }
    }
    // No user-defined copy constructor or copy assignment operator
    // The default implicitly generated ones will perform shallow copies.
};

void demonstrateDoubleFree() {
    std::cout << "Inside demonstrateDoubleFree function." << std::endl;
    FileManager fm1("original.txt"); // Allocates memory for "original.txt"
    fm1.printPath();

    // SEMANTIC ERROR: Implicit copy constructor performs a shallow copy.
    // fm2's filePath now points to the SAME memory location as fm1's filePath.
    FileManager fm2 = fm1; 
    fm2.printPath();

    std::cout << "Exiting demonstrateDoubleFree function. Destructors will be called." << std::endl;
    // When fm2 goes out of scope, its destructor is called, freeing the memory.
    // When fm1 goes out of scope, its destructor is called, attempting to free the SAME memory again.
    // This results in a "double free" error, which is a severe semantic error leading to undefined behavior/crash.
} // fm2 and fm1 go out of scope here

int main() {
    std::cout << "--- Starting Semantic Error Demonstration (Double Free) ---" << std::endl;
    demonstrateDoubleFree();
    std::cout << "--- Double Free Demonstration Finished ---" << std::endl;
    
    // If the program hasn't crashed, this object will be created and destroyed safely.
    FileManager fm_safe("safe.log");
    fm_safe.printPath();

    return 0;
}