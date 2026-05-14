#include <iostream>

void strConcatenate(char* dest, const char* src) {
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    // Semantic error: Misuse of dest_len as the loop counter for src.
    // This logic attempts to copy characters from src based on the original length of dest.
    // If src is longer than dest_len, it will only copy a portion of src.
    // If src is shorter, the loop might still run unnecessarily or cause issues depending on content.
    // The loop condition `i < dest_len` is incorrect for iterating through `src`.
    for (int i = 0; i < dest_len; ++i) { 
        if (src[i] == '\0') { // This check prevents reading past src's null, but the loop bound is still incorrect for src's actual length.
            break;
        }
        dest[dest_len + i] = src[i];
    }
    // Semantic error in null termination placement.
    // The null terminator is placed at dest[dest_len + dest_len], which is a fixed offset
    // based on the original dest_len, not the actual concatenated length.
    // This can lead to incorrect termination (too early, too late, or missing if dest_len is 0).
    dest[dest_len + dest_len] = '\0'; 
}

int main() {
    char buffer1[100] = "Hello";
    const char* src1 = " World"; // dest_len is 5. src length is 6. Loop runs for i=0 to 4. Copies " Worl". Null at buffer1[10].
    strConcatenate(buffer1, src1);
    std::cout << "Test 1 Output: \"" << buffer1 << "\"" << std::endl; // Expected: "Hello World", Actual: "Hello Worl" (truncated)

    char buffer2[100] = "First";
    const char* src2 = " Second"; // dest_len is 5. src length is 7. Loop runs for i=0 to 4. Copies " Seco". Null at buffer2[10].
    strConcatenate(buffer2, src2);
    std::cout << "Test 2 Output: \"" << buffer2 << "\"" << std::endl; // Expected: "First Second", Actual: "First Seco" (truncated)

    char buffer3[100] = "Base";
    const char* src3 = ""; // dest_len is 4. src length is 0. Loop runs for i=0 to 3. src[0] is '\0', breaks. Null at buffer3[8].
    strConcatenate(buffer3, src3);
    std::cout << "Test 3 Output: \"" << buffer3 << "\"" << std::endl; // Expected: "Base", Actual: "Base" (accidentally correct due to src being empty)

    char buffer4[100] = "";
    const char* src4 = "Append"; // dest_len is 0. src length is 6. Loop condition `i < dest_len` (i < 0) is false. Loop doesn't run. Null at buffer4[0].
    strConcatenate(buffer4, src4);
    std::cout << "Test 4 Output: \"" << buffer4 << "\"" << std::endl; // Expected: "Append", Actual: "" (incorrectly empty)

    return 0;
}