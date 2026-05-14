#include <iostream>
#include <vector>
// Readability: using namespace std; in global scope
using namespace std;

class Matrix {
private:
    int r; // Readability: Poor variable name: 'r' instead of 'rows'
    int c; // Readability: Poor variable name: 'c' instead of 'cols'
    vector<vector<int>> dat; // Readability: Poor variable name: 'dat' instead of 'data'

public:
    // Constructor
    Matrix(int rows_val, int cols_val) : r(rows_val), c(cols_val) {
        // No input validation for simplicity, assuming positive dimensions for this error type.
        dat.resize(r, vector<int>(c));
    }

    // Method to input values
    void inputValues() {
        cout << "Enter " << r << "x" << c << " matrix values:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << "Enter val for [" << i << "][" << j << "]: "; // Readability: shorthand 'val'
                cin >> dat[i][j];
            }
        }
    }

    // Method to display matrix - Efficiency & Readability Issue: uses endl in inner loop
    // Also, not const-correct, which is a minor quality issue.
    void display() { 
        cout << "Matrix:\n";
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << dat[i][j] << "\t"; // Prints element
                cout << endl; // Efficiency: 'endl' flushes buffer for EACH element, very inefficient.
                               // Readability: Each element on a new line, making output hard to read.
            }
        }
    }

    // Overload + operator - Efficiency Issue: passes 'other' by value, causing unnecessary copy
    Matrix operator+(Matrix other) { // Efficiency: 'other' is passed by value, creating a full copy
        // For simplicity, assume compatible dimensions for this error type.
        Matrix res(r, c); // Readability: Poor variable name: 'res' instead of 'result'
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res.dat[i][j] = this->dat[i][j] + other.dat[i][j];
            }
        }
        return res;
    }
};

int main() {
    // Readability: Poor variable names
    int r1 = 2, c1 = 2;
    Matrix m1(r1, c1);
    cout << "Input for M1:\n";
    m1.inputValues(); // Input: 1 2 3 4

    int r2 = 2, c2 = 2;
    Matrix m2(r2, c2);
    cout << "Input for M2:\n";
    m2.inputValues(); // Input: 5 6 7 8

    cout << "\nAdding M1 and M2:\n";
    Matrix sum = m1 + m2; // Efficiency: This involves copying m2 to operator+
    sum.display(); // Efficiency: This involves copying 'sum' to display, and uses endl repeatedly
                   // Readability: Output format is messy due to `endl` in inner loop.

    return 0;
}