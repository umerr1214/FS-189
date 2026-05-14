#include <iostream>
#include <string>

// Readability/Efficiency Issue: Using namespace std; globally in a header-like fashion.
// This pollutes the global namespace and can lead to name collisions.
using namespace std;

class Printer
{
public:
    // Readability Issue: Poor parameter name 'a' for an integer.
    void print(int a)
    {
        // Readability Issue: Redundant use of 'this->'.
        this->cout << "Int value: " << a << endl;
    }

    // Efficiency Issue: Passing std::string by value ('string b') causes an
    // unnecessary copy of the string object for every call, which can be
    // inefficient for large strings. It should be passed by 'const std::string&'.
    // Readability Issue: Poor parameter name 'b' for a string.
    void print(string b)
    {
        // Readability Issue: Redundant use of 'this->'.
        this->cout << "String data: " << b << endl;
        // Efficiency Issue: Unnecessary explicit flush. 'endl' already flushes the buffer.
        this->cout.flush();
    }

    // Readability Issue: Poor parameter name 'c' for a character.
    void print(char c)
    {
        // Readability Issue: Redundant use of 'this->'.
        this->cout << "Char symbol: " << c << endl;
    }
};

int main()
{
    Printer my_printer_obj; // Readability Issue: Slightly verbose and inconsistent object name.
    my_printer_obj.print(12345);
    my_printer_obj.print("Hello World from inefficient code!");
    my_printer_obj.print('Z');
    my_printer_obj.print('7');
    return 0;
}