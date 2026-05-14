#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for the driver function

// Abstract base class with a robustness issue: non-virtual destructor
class Printable {
public:
    virtual void print() = 0;
    // Robustness Issue: Non-virtual destructor.
    // When a derived object is deleted through a base class pointer,
    // the derived class's destructor will not be called, leading to resource leaks
    // or undefined behavior if derived classes manage unique resources.
    ~Printable() {
        // In a real scenario, this could lead to memory leaks if Document/Image
        // had specific resources to free and their destructors were not called.
    }
};

class Document : public Printable {
private:
    std::string title;
public:
    Document(const std::string& t) : title(t) {}
    void print() override {
        std::cout << "Printing Document: " << title << "\n";
    }
    ~Document() {
        // This destructor will NOT be called if a Document object is deleted
        // via a Printable* pointer due to the non-virtual base destructor.
        // std::cout << "Document destructor called for '" << title << "'\n";
    }
};

class Image : public Printable {
private:
    std::string filename;
public:
    Image(const std::string& fn) : filename(fn) {}
    void print() override {
        std::cout << "Printing Image: " << filename << "\n";
    }
    ~Image() {
        // This destructor will NOT be called if an Image object is deleted
        // via a Printable* pointer due to the non-virtual base destructor.
        // std::cout << "Image destructor called for '" << filename << "'\n";
    }
};

// Driver code to run test cases and capture output
std::string run_test_cases() {
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf(); // Save original cout buffer
    std::cout.rdbuf(ss.rdbuf()); // Redirect cout to stringstream

    // Test case 1: Document object
    Document doc1("Report_Q1");
    doc1.print();

    // Test case 2: Image object
    Image img1("sunset.jpg");
    img1.print();

    // Test case 3: Document with empty title
    Document doc2("");
    doc2.print();

    // Test case 4: Image with long filename
    Image img2("very_long_and_descriptive_image_filename_from_camera_2023_10_27_15_30_00.png");
    img2.print();

    // Test case 5 & 6: Polymorphic calls demonstrating the robustness issue
    // When these are deleted, only Printable's destructor will be called,
    // leading to potential resource leaks or undefined behavior for derived parts.
    Printable* p_doc = new Document("Memo_to_staff");
    p_doc->print();
    delete p_doc; // Only ~Printable() is called

    Printable* p_img = new Image("logo.svg");
    p_img->print();
    delete p_img; // Only ~Printable() is called

    std::cout.rdbuf(old_cout_buf); // Restore original cout buffer
    return ss.str(); // Return captured output
}

int main() {
    // The main function simply calls the driver and prints its captured output.
    std::cout << run_test_cases();
    return 0;
}