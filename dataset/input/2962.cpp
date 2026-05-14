#include <iostream>

// Base class Document with a virtual destructor
class Document {
public:
    Document() {
        std::cout << "Document constructor called." << std::endl;
    }
    virtual ~Document() { // Virtual destructor
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
}; // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::cout << "Creating PdfDocument via Document pointer..." << std::endl;
    Document* docPtr = new PdfDocument(); // Polymorphic creation
    std::cout << "Deleting PdfDocument via Document pointer..." << std::endl;
    delete docPtr; // This should correctly call PdfDocument's destructor, then Document's
    std::cout << "Demonstration complete." << std::endl;
    return 0;
}