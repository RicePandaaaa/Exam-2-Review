#include <iostream>

using std::cout, std::endl, std::string;

int main() {
    // Pointer example
    int number = 42;
    int* ptr = &number;          // Set pointer to address
    int other = *ptr;            // Dereference

    *ptr = 9;                    // Set value of pointer
    ptr = nullptr;               // Point the pointer to null

    cout << number << endl;      // 9
    cout << other << endl;       // 42

    // Dynamic memory is ALLOCATED ON THE HEAP!

    // Dynamic array stuff
    // 1D arrays
    int cap = 5;   // Only dynamic arrays can have variable sizes
    int* row = new int[cap]{};  // Array of 5 values
    int* newRow = new int(5); // Array with just the number 5
    int* nums = new int[cap]{1, 2, 3, 4, 5}; // Array with 1, 2, 3, 4, 5

    delete[] row; // Deallocation
    delete[] newRow;
    delete[] nums;

    row = nullptr;  // Unnecessary but eh
    newRow = nullptr;
    nums = nullptr;

    // 2D arrays
    int rows = 5;
    int cols = 6;
    int** map = new int*[rows];
    
    // Create the 2D array
    for (int i = 0; i < rows; ++i) {
        // Create the inner array
        map[i] = new int[cols];

        // Insert values
        for (int c = 0; c < cols; ++c) {
            map[i][c] = c;
        }
    }

    // Brute force search (row major) + traversal
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            cout << map[r][c] << endl;
        }
    }

    // Deallocate the 2D array
    for (int i = 0; i < rows; ++i) {
        delete[] map[i];
    }
    delete[] map;
}