#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool areAnagrams(const char* str1, const char* str2) {
    // Efficiency/Readability: Sorting strings to compare.
    // O(N log N) time complexity.
    // Frequency map is O(N).
    // Sorting is a valid approach but less efficient for simple character sets.
    // Also using std::string conversion overhead.
    
    if (!str1 || !str2) return false;
    
    string s1(str1);
    string s2(str2);
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}

int main() {
    cout << areAnagrams("listen", "silent") << endl;
    return 0;
}
