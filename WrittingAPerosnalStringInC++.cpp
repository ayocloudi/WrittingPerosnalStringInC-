#include <iostream>
using namespace std;

// This function calculates and returns the length of the given string str, excluding the '\0' character.
// Function to calculate the length of a string

unsigned int length(const char* str) {
    unsigned int len = 0;  // Initialize length variable to 0
    while(str[len] != '\0') {  // Loop until the null terminator is encountered
        len++;  // Increment length variable for each character
    }
    return len;  // Return the length of the string
}


// This function copies the string from src to dest and returns the copied string.
// If the destination string is not large enough to store the source string, it returns NULL.
// Function to copy one string to another

char* copy(char* dest, const char* src) {
    unsigned int lenSrc = length(src);  // Get the length of the source string
    unsigned int lenDest = length(dest);  // Get the length of the destination string
    if(lenDest < lenSrc) {  // Check if destination string has enough space
        return NULL;  // If not, return NULL
    }
    for(unsigned int i = 0; i <= lenSrc; i++) {  // Loop through the source string including the null terminator
        dest[i] = src[i];  // Copy each character from source to destination
    }
    return dest;  // Return the copied string
}


// This function searches for the first occurrence of character c in the string str.
// If found, it returns the index of the character. Otherwise, it returns -1.
// Function to find the index of a character in a string

int indexOf(char c, const char* str) {
    for(unsigned int i = 0; i < length(str); i++) {  // Loop through the string
        if(str[i] == c) {  // If the character is found
            return i;  // Return the index of the character
        }
    }
    return -1;  // If the character is not found, return -1
}


// This function extracts a substring from the string str starting at index i and ending at index j-1.
// If the indices are invalid, it returns NULL.
// Function to extract a substring from a string

char* substring(int i, int j, const char* str) {
    if(i < 0 || j > length(str) || i > j) {  // Check if indices are in valid range
        return NULL;  // If not, return NULL
    }
    char* subStr = new char[j-i+1];  // Allocate memory for substring
    for(int k = i; k < j; k++) {  // Loop through the specified range
        subStr[k-i] = str[k];  // Copy characters to the substring
    }
    subStr[j-i] = '\0';  // Add null terminator to the end of the substring
    return subStr;  // Return the substring
}


// This function creates and returns a new string derived from str by replacing every occurrence of character c with character p.
// Function to replace occurrences of a character with another character in a string

char* replace(char c, char p, const char* str) {
    char* newStr = new char[length(str)+1];  // Allocate memory for the new string
    for(unsigned int i = 0; i < length(str); i++) {  // Loop through the string
        newStr[i] = (str[i] == c) ? p : str[i];  // Replace character if found, else keep the original character
    }
    newStr[length(str)] = '\0';  // Add null terminator to the end of the new string
    return newStr;  // Return the new string
}

void length_test_case_1() {
    const char* testStr = "hello";
    if (length(testStr) == 5) {
        cout << "Length Test Case 1 Passed!" << endl;
    } else {
        cout << "Length Test Case 1 Failed." << endl;
    }
}

void copy_test_case_1() {
    const char* src = "source";
    char dest[10];
    char* result = copy(dest, src);
    if (result && strcmp(dest, "source") == 0) {
        cout << "Copy Test Case 1 Passed!" << endl;
    } else {
        cout << "Copy Test Case 1 Failed." << endl;
    }
}

void indexOf_test_case_1() {
    const char* testStr = "hello";
    if (indexOf('e', testStr) == 1) {
        cout << "IndexOf Test Case 1 Passed!" << endl;
    } else {
        cout << "IndexOf Test Case 1 Failed." << endl;
    }
}

void substring_test_case_1() {
    const char* testStr = "hello";
    char* result = substring(1, 4, testStr);
    if (result && strcmp(result, "ell") == 0) {
        cout << "Substring Test Case 1 Passed!" << endl;
        delete[] result;
    } else {
        cout << "Substring Test Case 1 Failed." << endl;
        delete[] result;
    }
}

void replace_test_case_1() {
    const char* testStr = "hello";
    char* result = replace('l', 'x', testStr);
    if (result && strcmp(result, "hexxo") == 0) {
        cout << "Replace Test Case 1 Passed!" << endl;
        delete[] result;
    } else {
        cout << "Replace Test Case 1 Failed." << endl;
        delete[] result;
    }
}

int main() {
    const char* str = "string";
    char dest[10] = {}; // Initialize the destination string
    
    cout << "Length: " << length(str) << endl;  // Output: Length: 6
    cout << "Copy: " << copy(dest, str) << endl;  // Output: Copy: string
    cout << "Index of 'i': " << indexOf('i', str) << endl;  // Output: Index of 'i': 3
    cout << "Substring: " << substring(0, 3, str) << endl;  // Output: Substring: str
    cout << "Replace: " << replace('i', 'x', str) << endl;  // Output: Replace: strxng

    //Also I must not forget to delete dynamically allocated memory
   //If you don't release this memory, it will remain allocated for the duration of your program's execution, which is not a good practice

    delete[] substring(0, 3, str);
    delete[] replace('i', 'x', str);

    length_test_case_1();
    copy_test_case_1();
    indexOf_test_case_1();
    substring_test_case_1();
    replace_test_case_1();

    return 0;
}