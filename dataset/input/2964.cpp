#include <iostream>

// Base class Document with a virtual destructor
class Document {
public:
    Document() {
        std::cout << "Document constructor called." << std::endl;
    }
    virtual ~Document() { // Correctly virtual destructor
        std::cout << "Document destructor called." << std::endl;
    }
};

// Derived class PdfDocument
class PdfDocument : public Document {
public:
    PdfDocument() {
        std::cout << "PdfDocument constructor called." << std::endl;
    }
    ~PdfDocument() override {
        std::cout << "PdfDocument destructor called." << std::endl;
    }
};

int main() {
    std::cout << "Creating an array of PdfDocument via Document pointer..." << std::endl;
    // Allocate an array of PdfDocument objects
    Document* docPtr = new PdfDocument[2]; 
    
    std::cout << "Deleting PdfDocument array via Document pointer (incorrectly using 'delete' instead of 'delete[]')..." << std::endl;
    // SEMANTIC ERROR: Deleting an array allocated with `new[]` using `delete` (single object delete).
    // This leads to undefined behavior, typically only the first object's destructor is called,
    // and memory for subsequent objects in the array is leaked, potentially corrupting the heap.
    delete docPtr; 
    
    std::cout << "Demonstration complete (but with potential issues due to incorrect array deletion)." << std::endl;
    return 0;
}