#include <iostream>
#include <cstring> // For strlen, memcpy
#include <algorithm> // For std::swap

class FileManager {
private:
    char* filePath;
    size_t pathLength;

    // Helper function for allocation and copying
    void allocateAndCopy(const char* sourcePath) {
        if (sourcePath) {
            pathLength = std::strlen(sourcePath);
            filePath = new char[pathLength + 1];
            std::memcpy(filePath, sourcePath, pathLength + 1); // Safe and efficient copy
        } else {
            // Handle nullptr input by creating an empty string
            pathLength = 0;
            filePath = new char[1];
            filePath[0] = '\0';
        }
    }

public:
    // Constructor
    FileManager(const char* path = nullptr) : filePath(nullptr), pathLength(0) {
        allocateAndCopy(path);
        std::cout << "FileManager created for path: " << filePath << std::endl;
    }

    // Destructor
    ~FileManager() {
        if (filePath) {
            std::cout << "Deallocating memory for path: " << filePath << std::endl;
            delete[] filePath;
            filePath = nullptr; // Good practice to nullify after delete
        }
    }

    // Copy Constructor (Deep Copy) - Rule of Three/Five
    FileManager(const FileManager& other) : filePath(nullptr), pathLength(0) {
        allocateAndCopy(other.filePath);
        std::cout << "FileManager copy constructed for path: " << filePath << std::endl;
    }

    // Copy Assignment Operator (Deep Copy with self-assignment check) - Rule of Three/Five
    FileManager& operator=(const FileManager& other) {
        std::cout << "FileManager copy assignment operator called for path: " << (filePath ? filePath : "[empty]") << std::endl;
        if (this == &other) { // Self-assignment check
            return *this;
        }

        // Deallocate existing memory
        delete[] filePath;
        filePath = nullptr; // Ensure nullptr safety before re-allocation

        // Allocate and copy new memory
        allocateAndCopy(other.filePath);

        return *this;
    }

    // Move Constructor (C++11 Rule of Five)
    FileManager(FileManager&& other) noexcept : filePath(nullptr), pathLength(0) {
        std::cout << "FileManager move constructed for path: " << other.filePath << std::endl;
        // Steal resources from 'other'
        filePath = other.filePath;
        pathLength = other.pathLength;
        // Nullify 'other's pointers to prevent double-free
        other.filePath = nullptr;
        other.pathLength = 0;
    }

    // Move Assignment Operator (C++11 Rule of Five)
    FileManager& operator=(FileManager&& other) noexcept {
        std::cout << "FileManager move assignment operator called for path: " << (filePath ? filePath : "[empty]") << std::endl;
        if (this == &other) { // Self-assignment check
            return *this;
        }

        delete[] filePath; // Deallocate current resources

        // Steal resources from 'other'
        filePath = other.filePath;
        pathLength = other.pathLength;
        // Nullify 'other's pointers
        other.filePath = nullptr;
        other.pathLength = 0;

        return *this;
    }

    void displayPath() const {
        std::cout << "Current file path: " << (filePath ? filePath : "[empty]") << std::endl;
    }
};

// Function taking FileManager by value to test copy constructor
void processFileManagerByValue(FileManager fm) {
    std::cout << "  Inside processFileManagerByValue (copy created):" << std::endl;
    fm.displayPath();
    std::cout << "  Exiting processFileManagerByValue (copy destroyed)." << std::endl;
}

// Function returning FileManager by value to test move constructor/RVO
FileManager createFileManager(const char* path) {
    std::cout << "  Inside createFileManager:" << std::endl;
    FileManager temp(path);
    std::cout << "  Exiting createFileManager." << std::endl;
    return temp; // Return by value will trigger move constructor (or RVO/NRVO)
}

int main() {
    std::cout << "--- Correct Version (3141) ---" << std::endl;

    // Test Constructor
    FileManager fm1("data/document.pdf");
    fm1.displayPath();

    // Test Copy Constructor
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    FileManager fm2 = fm1; // Calls copy constructor
    fm2.displayPath();
    fm1.displayPath(); // Ensure fm1 is unchanged

    std::cout << "\n--- Testing Copy Constructor (function parameter) ---" << std::endl;
    processFileManagerByValue(fm1);
    fm1.displayPath(); // Ensure fm1 is unchanged

    // Test Copy Assignment Operator
    std::cout << "\n--- Testing Copy Assignment Operator ---" << std::endl;
    FileManager fm3("temp/old_file.txt");
    fm3.displayPath();
    fm3 = fm1; // Calls copy assignment operator
    fm3.displayPath();
    fm1.displayPath(); // Ensure fm1 is unchanged

    // Test self-assignment
    std::cout << "\n--- Testing Self-Assignment ---" << std::endl;
    fm3 = fm3;
    fm3.displayPath();

    // Test Move Constructor
    std::cout << "\n--- Testing Move Constructor ---" << std::endl;
    FileManager fm4 = createFileManager("new/report.xlsx"); // Calls move constructor (or RVO)
    fm4.displayPath();

    // Test Move Assignment Operator
    std::cout << "\n--- Testing Move Assignment Operator ---" << std::endl;
    FileManager fm5("another/temp.txt");
    fm5.displayPath();
    fm5 = createFileManager("moved/path.csv"); // Calls move assignment operator (or RVO for temporary)
    fm5.displayPath();

    std::cout << "\nAll objects going out of scope. Proper deallocations will occur." << std::endl;
    return 0;
}