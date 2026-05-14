#include <iostream>
#include <vector>

// Function to calculate and print the sum of the main diagonal of a 4x4 matrix.
// Readability/Efficiency Issue: This version suffers from poor readability due to
// cryptic variable names, verbose initialization, inconsistent formatting, and
// inefficient diagonal sum calculation using a nested loop.
void calculateAndPrintDiagonalSum() {
    std::vector<std::vector<int>> m; // Cryptic variable name 'm'
    m.resize(4); // Inefficient and verbose way to initialize a fixed-size matrix
    for(int i=0; i<4; ++i) { m[i].resize(4); }

    // Overly verbose and poorly formatted initialization, reducing readability
    m[0][0]=1;m[0][1]=2;m[0][2]=3;m[0][3]=4;
    m[1][0]=5;m[1][1]=6;m[1][2]=7;m[1][3]=8;
    m[2][0]=9;m[2][1]=10;m[2][2]=11;m[2][3]=12;
    m[3][0]=13;m[3][1]=14;m[3][2]=15;m[3][3]=16;

    int s=0; // Cryptic variable name 's' for sum

    // Inefficient loop for calculating diagonal sum: uses a nested loop and a conditional check
    // where a single loop accessing matrix[i][i] would be sufficient and more efficient.
    for(int i=0;i<4;++i) { // Poor formatting, inconsistent indentation
        for(int j=0;j<4;++j) {
            if(i==j) { // Unnecessary condition check in every inner loop iteration
                s+=m[i][j];
            }
        }
    }

    std::cout<<"Sum of main diagonal elements: "<<s<<std::endl; // Lack of clear message, poor formatting
} // Poor formatting