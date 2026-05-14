#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

void transposeMatrix(char matrix[][COLS]) {
    cout << "Transpose:" << endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            // Semantic Error: Assigning value to cout? 
            // Or using pointer dereference incorrectly?
            
            // Let's use assignment in output?
            // cout << (matrix[j][i] = 'X') << " "; // Modifies matrix but valid C++
            
            // Let's use bitwise shift for output stream?
            // cout >> matrix[j][i]; // Semantic error: extracting to cout?
            // "binary '>>': no operator found which takes a left-hand operand of type 'std::ostream'"
            
            // Let's try to print the address of the char but imply it's the char?
            // cout << &matrix[j][i] << " ";
            // This prints the string starting at that character (rest of row).
            // This is semantically valid but logically wrong for "printing the char".
            // It treats the char as a C-string.
            
            cout << &matrix[j][i] << " "; 
        }
        cout << endl;
    }
}

int main() {
    char matrix[ROWS][COLS] = {
        {'A', 'B', 'C', '\0'}, // Null term to make semantic error visible safely?
        {'E', 'F', 'G', '\0'},
        {'I', 'J', 'K', '\0'}
    };
    
    // Expected: A E I ...
    // Actual: "ABC" "EFG" "IJK" ... prints strings instead of chars
    transposeMatrix(matrix);
    return 0;
}
