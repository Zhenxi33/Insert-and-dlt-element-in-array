#include <iostream>
using namespace std;


void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << endl;
}


int insertElement(int arr[], int size, int index, int value) {
   
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[index] = value;
    return size + 1;
}

int deleteElement(int arr[], int size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    return size - 1;
}

int main() {
    int arr[100]; 
    int size;
    
    cout << "Enter the number of elements in array: ";
    cin >> size;
    
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }
    
    cout << "\n";
    printArray(arr, size);
    
    int choice;
    cout << "\nChoose operation:\n";
    cout << "1. Insert element\n";
    cout << "2. Delete element\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    
    if (choice == 1) {
        
        int value;
        cout << "Enter value to insert: ";
        cin >> value;
        
        arr[size] = value;  
        size++;
        
        cout << "\nAfter insertion:\n";
        printArray(arr, size);
        
    } else if (choice == 2) {
        
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