#include <iostream>

// Base class `Document` with a virtual destructor
class Document {
public:
    Document() {
        std::cout << "Document: Constructor called.\n";
    }
    // The virtual destructor ensures that the correct destructor (PdfDocument's)
    // is called when deleting through a base class pointer.
    virtual ~Document() {
        std::cout << "Document: Destructor called.\n";
    }
};

// Derived class `PdfDocument`
class PdfDocument : public Document {
private:
    // Simulate a resource that needs explicit cleanup
    int* dataBuffer;
    static const int BUFFER_SIZE = 10;

public:
    PdfDocument() : dataBuffer(new int[BUFFER_SIZE]) {
        std::cout << "PdfDocument: Constructor called, allocated data buffer.\n";
        // Initialize buffer to prevent uninitialized memory access
        for(int i = 0; i < BUFFER_SIZE; ++i) {
            dataBuffer[i] = i;
        }
    }

    // The 'override' keyword is good practice for virtual functions
    ~PdfDocument() override {
        std::cout << "PdfDocument: Destructor called, freeing data buffer.\n";
        delete[] dataBuffer;
    }
};

int main() {
    std::cout << "--- Demonstrating Virtual Destructor Importance ---\n";

    // Create a PdfDocument object and point to it with a Document pointer
    std::cout << "Creating a PdfDocument object via Document* pointer...\n";
    Document* docPtr = new PdfDocument();

    // Perform some hypothetical operations (not relevant for this demo, but common)
    // ...

    std::cout << "Deleting PdfDocument object via Document* pointer...\n";
    // Because Document's destructor is virtual, this call will correctly
    // invoke PdfDocument's destructor first, then Document's destructor,
    // ensuring proper cleanup of `dataBuffer`.
    delete docPtr;

    std::cout << "--- Demonstration Complete: Proper cleanup observed ---\n";

    return 0;
}