#include <iostream>

// Base class Document without a virtual destructor
class Document {
public:
    Document() {
        std::cout << "Document constructor called." << std::endl;
    }
    ~Document() { // LOGICAL ERROR: Destructor is NOT virtual
        std::cout << "Document destructor called." << std::endl;
    }
};

// Derived class PdfDocument
class PdfDocument : public Document {
public:
    PdfDocument() {
        std::cout << "PdfDocument constructor called." << std::endl;
    }
    ~PdfDocument() { // This destructor will not be called when deleted via a base pointer
        std::cout << "PdfDocument destructor called." << std::endl;
    }
};

int main() {
    std::cout << "Creating PdfDocument via Document pointer..." << std::endl;
    Document* docPtr = new PdfDocument(); // Polymorphic creation
    std::cout << "Deleting PdfDocument via Document pointer..." << std::endl;
    delete docPtr; // This will only call Document's destructor, leading to a memory leak for PdfDocument's specific resources.
    std::cout << "Demonstration complete (with a memory leak for PdfDocument's parts)." << std::endl;
    return 0;
}