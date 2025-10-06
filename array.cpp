#include <iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}

// Function to insert element at given index
int insertElement(int arr[], int size, int index, int value) {
    // Shift elements to the right
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[index] = value;
    
    // Return new size
    return size + 1;
}

// Function to delete element at given index
int deleteElement(int arr[], int size, int index) {
    // Shift elements to the left
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Return new size
    return size - 1;
}

int main() {
    int arr[100]; // Array with space for up to 100 elements
    int size;
    
    // Input array size
    cout << "Enter the number of elements in array: ";
    cin >> size;
    
    // Input array elements
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }
    
    // Display original array
    cout << "\n";
    printArray(arr, size);
    
    // Menu
    int choice;
    cout << "\nChoose operation:\n";
    cout << "1. Insert element\n";
    cout << "2. Delete element\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    
    if (choice == 1) {
        // Insert operation - add to end of array
        int value;
        cout << "Enter value to insert: ";
        cin >> value;
        
        arr[size] = value;  // Add to the end
        size++;
        
        cout << "\nAfter insertion:\n";
        printArray(arr, size);
        
    } else if (choice == 2) {
        // Delete operation
        int index;
        cout << "\nEnter index to delete (0 to " << size - 1 << "): ";
        cin >> index;
        
        if (index >= 0 && index < size) {
            size = deleteElement(arr, size, index);
            cout << "\nAfter deletion:\n";
            printArray(arr, size);
        } else {
            cout << "Invalid index!\n";
        }
        
    } else {
        cout << "Invalid choice!\n";
    }
    
    return 0;
}