#include <iostream>
#include <algorithm> // For std::fill_n

// Base class Document with a non-virtual destructor
class Document {
public:
    Document() {
        std::cout << "Document constructor\n";
    }
    // IMPORTANT: Destructor is NOT virtual, which is the robustness issue here.
    ~Document() {
        std::cout << "Document destructor\n";
    }
};

// Derived class PdfDocument
class PdfDocument : public Document {
private:
    char* buffer;
    static const int BUFFER_SIZE = 100;

public:
    PdfDocument() : buffer(new char[BUFFER_SIZE]) {
        std::cout << "PdfDocument constructor, allocated buffer\n";
        // Initialize buffer to avoid uninitialized memory warnings
        std::fill_n(buffer, BUFFER_SIZE, 'X');
    }

    ~PdfDocument() {
        std::cout << "PdfDocument destructor, freeing buffer\n";
        delete[] buffer;
    }
};

int main() {
    std::cout << "Creating a PdfDocument object via Document pointer...\n";
    Document* docPtr = new PdfDocument();

    std::cout << "Attempting to delete PdfDocument object via Document pointer...\n";
    // This will only call Document's destructor, leading to a memory leak
    // because PdfDocument's destructor (and thus its buffer deallocation)
    // will not be called.
    delete docPtr;

    std::cout << "Demonstration of potential memory leak complete.\n";
    // The buffer allocated in PdfDocument's constructor is leaked here.

    return 0;
}