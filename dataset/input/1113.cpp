#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Required for the driver function

// Abstract base class
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default; // Correct: virtual destructor ensures proper cleanup
};

class Document : public Printable {
private:
    std::string title;
public:
    // Correct: Constructor takes const std::string& for efficiency and to prevent unnecessary copies
    Document(const std::string& title) : title(title) {}
    void print() override { // Correct: using 'override' keyword for clarity and compile-time checks
        std::cout << "Printing Document: " << title << '\n'; // Efficient: using '\n' instead of std::endl
    }
};

class Image : public Printable {
private:
    std::string filename;
public:
    // Correct: Constructor takes const std::string& for efficiency and to prevent unnecessary copies
    Image(const std::string& filename) : filename(filename) {}
    void print() override { // Correct: using 'override' keyword
        std::cout << "Printing Image: " << filename << '\n'; // Efficient: using '\n'
    }
};

// Driver code to run test cases and capture output
std::string run_test_cases() {
    std::stringstream ss;
    std::streambuf* old_cout_buf = std::cout.rdbuf(); // Save original cout buffer
    std::cout.rdbuf(ss.rdbuf()); // Redirect cout to stringstream

    // Test case 1: Document object on stack
    Document doc1("Report_Q1");
    doc1.print();

    // Test case 2: Image object on stack
    Image img1("sunset.jpg");
    img1.print();

    // Test case 3: Document with empty title
    Document doc2("");
    doc2.print();

    // Test case 4: Image with long filename
    Image img2("very_long_and_descriptive_image_filename_from_camera_2023_10_27_15_30_00.png");
    img2.print();

    // Test case 5 & 6: Polymorphic calls with heap allocation and proper cleanup
    Printable* doc_ptr = new Document("Memo_to_staff");
    doc_ptr->print();
    delete doc_ptr; // Correctly calls ~Document() then ~Printable() due to virtual destructor

    Printable* img_ptr = new Image("logo.svg");
    img_ptr->print();
    delete img_ptr; // Correctly calls ~Image() then ~Printable() due to virtual destructor

    std::cout.rdbuf(old_cout_buf); // Restore original cout buffer
    return ss.str(); // Return captured output
}

int main() {
    // The main function simply calls the driver and prints its captured output.
    std::cout << run_test_cases();
    return 0;
}