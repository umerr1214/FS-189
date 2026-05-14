#include <iostream>

// Function to sum elements of a specified row
int sumRow(int matrix[4][3], int row_index)
{
    int sum = 0;
    for (int j = 0; j < 3; j++) 
    {
        sum += matrix[row_index][j];
    }
    return sum;
}

int main()
{
    int matrix[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    int target_row = 1; // Second row (index 1)

    int result = sumRow(matrix, target_row);

    std::cout << "Sum of elements in row " << target_row << ": " << result << std::endl
    return 0;
}