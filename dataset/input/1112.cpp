#include <iostream>
#include <string>
#include <vector> // Included for completeness, not strictly used in core logic
#include <sstream> // Required for the driver function

// Abstract base class with correct virtual destructor
class Printable
{
public:
    virtual void print() = 0;
    virtual ~Printable() = default; // Correct: virtual destructor
};

class Document : public Printable
{
private:
    std::string doc_title; // Readability Issue: Poor variable name
public:
    // Readability/Efficiency Issue: Takes std::string by value, causing unnecessary copy
    Document(std::string t) : doc_title(t) {}
    void print() override
    {
        // Readability/Efficiency Issue: Uses std::endl, which flushes the buffer,
        // potentially less efficient than '\n' when a flush is not explicitly needed.
        std::cout << "Printing Document: " << this->doc_title << std::endl;
    }
};

class Image : public Printable
{
private:
    std::string img_file; // Readability Issue: Poor variable name
public:
    // Readability/Efficiency Issue: Takes std::string by value, causing unnecessary copy
    Image(std::string fn) : img_file(fn) {}
    void print() override
    {
        // Readability Issue: Inconsistent use of newline characters (std::endl vs '\n')
        std::cout << "Printing Image: " << img_file << "\n";
    }
};

// Driver code to run test cases and capture output
std::string run_test_cases() {
    std::stringstream s_s; // Readability Issue: Poor variable name
    std::streambuf* old_buf = std::cout.rdbuf(); // Readability Issue: Poor variable name
    std::cout.rdbuf(s_s.rdbuf()); // Redirect cout to stringstream

    // Readability Issue: Poor variable names
    Document d_obj("Report_Q1");
    d_obj.print();

    Image i_obj("sunset.jpg");
    i_obj.print();

    Document d_obj_empty("");
    d_obj_empty.print();

    Image i_obj_long("very_long_and_descriptive_image_filename_from_camera_2023_10_27_15_30_00.png");
    i_obj_long.print();

    Printable* p_doc_ptr = new Document("Memo_to_staff"); // Readability Issue: Poor variable name
    p_doc_ptr->print();
    delete p_doc_ptr;

    Printable* p_img_ptr = new Image("logo.svg"); // Readability Issue: Poor variable name
    p_img_ptr->print();
    delete p_img_ptr;

    std::cout.rdbuf(old_buf); // Restore original cout buffer
    return s_s.str(); // Return captured output
}

int main() {
    // The main function simply calls the driver and prints its captured output.
    std::cout << run_test_cases();
    return 0;
}