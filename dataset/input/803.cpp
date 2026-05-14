#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void mergeArrays(const int arr1[], int n1, const int arr2[], int n2, int result[]) {
    // Efficiency Issue: Concatenating and then sorting O((N+M) log (N+M))
    // instead of merging in O(N+M).
    // This defeats the purpose of the input being sorted.
    
    int k = 0;
    for(int i=0; i<n1; i++) result[k++] = arr1[i];
    for(int i=0; i<n2; i++) result[k++] = arr2[i];
    
    // Sorting again
    sort(result, result + n1 + n2);
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int result[8];
    
    mergeArrays(arr1, 4, arr2, 4, result);
    
    for(int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
