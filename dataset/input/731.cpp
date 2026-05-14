#include <iostream>
#include <vector>
using namespace std;

bool Exists(int data[][6], int pattern[][3]) {
    // Efficiency/Readability: Copying the subgrid into a temporary buffer/vector to compare?
    // Using `vector` comparison is cleaner but allocating vectors inside nested loops is very inefficient.
    // O(N^2) allocations.
    
    // Instead of direct comparison, let's create a vector for pattern
    // and for every subgrid create a vector and compare.
    
    vector<vector<int>> p(3, vector<int>(3));
    for(int r=0; r<3; r++)
        for(int c=0; c<3; c++)
            p[r][c] = pattern[r][c];
            
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            vector<vector<int>> sub(3, vector<int>(3));
            for(int r=0; r<3; r++)
                for(int c=0; c<3; c++)
                    sub[r][c] = data[i+r][j+c];
            
            if (sub == p) return true;
        }
    }
    return false;
}

int main() {
    int data[6][6] = {
        {1, 2, 7, 8, 9, 6},
        {2, 2, 3, 4, 5, 6},
        {3, 2, 3, 4, 5, 6},
        {4, 2, 3, 4, 5, 6},
        {5, 2, 9, 8, 7, 6},
        {6, 2, 7, 4, 5, 6}
    };
    int pattern[3][3] = {
        {3, 4, 5},
        {3, 4, 5},
        {3, 4, 5}
    };
    
    if (Exists(data, pattern)) cout << "Found" << endl;
    return 0;
}
