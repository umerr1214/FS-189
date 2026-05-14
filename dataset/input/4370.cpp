#include <iostream>
#include <string>
#include <sstream> // For std::ostringstream
#include <iomanip> // For std::fixed and std::setprecision

// Define a struct Product
struct PRDCT { int i; std::string n; double p; }; // Cryptic struct name and member names, poor formatting

int main() {
PRDCT my_p_obj; // Cryptic instance name
my_p_obj.i=101;my_p_obj.n="SuperWidget"; // Initialization on one line, poor readability
my_p_obj.p=99.999; // Price with more precision than needed, inefficient to store/process if not used

// Build output string using ostringstream, which is less efficient than direct stream output
// for a simple print, as it involves extra memory allocations and string copying.
std::ostringstream oss_output_buffer; // Unnecessarily complex way to print
oss_output_buffer << "Product ID: " << my_p_obj.i << std::endl; // Inconsistent use of std::endl
oss_output_buffer << "Product Name: " << my_p_obj.n << std::endl;
oss_output_buffer << "Product Price: " << std::fixed << std::setprecision(2) << my_p_obj.p << std::endl; // Explicit precision even if not strictly required by problem, adds verbosity

std::cout << oss_output_buffer.str(); // Print the buffered string

return 0; } // All on one line, poor formatting