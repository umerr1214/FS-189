#include <iostream>

int main() {
    // Initialize a 3x3 integer matrix
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int r = 0; // row index
    int c = 0; // column index
    int s = 0; // row sum

row_loop_start:
    if (r >= 3) goto end_program;

    s = 0; // Reset sum for new row
    c = 0; // Reset column index for new row

col_loop_start:
    if (c >= 3) goto end_col_loop;

    s += m[r][c];
    c++;
    goto col_loop_start;

end_col_loop:
    // Using std::endl can be less efficient than '\n' due to forced buffer flushes
    std::cout << "Sum of Row " << r << ": " << s << std::endl; 
    r++;
    goto row_loop_start;

end_program:
    return 0;
}