#include <iostream> // Included but not fully utilized for output
#include <vector>
#include <cstdio>   // For printf, used for output

int main() {
    // Readability Issue: Obscure variable names, verbose initialization logic,
    // and extensive use of goto statements for loop control which makes the code
    // significantly harder to read, understand, and maintain.
    // Also, using printf instead of iostream manipulators for formatting
    // is less idiomatic C++ for new code.

    std::vector<std::vector<int>> twoDeeArray(3, std::vector<int>(3)); // Matrix declaration

    int k = 1; // Used for initialization values, not very descriptive
    int row_idx = 0;
    INIT_LOOP_ROW:
        if (row_idx >= 3) goto PRINT_LOOP_ROW;
        int col_idx = 0;
        INIT_LOOP_COL:
            if (col_idx >= 3) {
                row_idx++;
                goto INIT_LOOP_ROW;
            }
            twoDeeArray[row_idx][col_idx] = k * (col_idx + 1); // Arbitrary initialization logic
            k += 10;
            col_idx++;
            goto INIT_LOOP_COL;

    row_idx = 0; // Reset row_idx for printing loop
    PRINT_LOOP_ROW:
        if (row_idx >= 3) goto END_PROGRAM;
        int c_idx = 0; // Column index for printing, similar to col_idx but separate
        PRINT_LOOP_COL:
            if (c_idx >= 3) {
                printf("\n"); // New line for each row using printf
                row_idx++;
                goto PRINT_LOOP_ROW;
            }
            // Using printf for formatting, which is less C++ idiomatic
            // and requires manual width specification (e.g. %4d)
            printf("%4d", twoDeeArray[row_idx][c_idx]);
            c_idx++;
            goto PRINT_LOOP_COL;

    END_PROGRAM:
        return 0;
}