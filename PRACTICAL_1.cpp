// Experiment No.1
// Title:Write a program to perform insertion, deletion, searching and transversal
// in 1D array.
// Objective: To demonstrate basic operations on a one-dimensional array such as
// adding, removing, finding, and displaying elements, enabling efficient data
// manipulation and understanding fundamental array handling concepts in C++
// programming.
// Program:
#include <iostream>
using namespace std;
void traverseArray(int arr[], int size)
{
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void insertElement(int arr[], int &size, int capacity, int element, int position)
{
    if (size == capacity || position < 0 || position > size)
    {
        cout << "Insertion failed!" << endl;
        return;
    }
    for (int i = size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = element;
    size++;
    cout << "Element inserted successfully!" << endl;
}
void deleteElement(int arr[], int &size, int position)
{
    if (position < 0 || position >= size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = position; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    cout << "Element deleted successfully!" << endl;
}
void searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << "Element " << element << " found at position " << i << "." << endl;
            return;
        }
    }
    cout << "Element not found." << endl;
}
int main()
{
    const int capacity = 100;
    int arr[capacity], size = 0, choice, element, position;
    do
    {
        cout << "\nMenu:\n1.Traverse 2.Insert 3.Delete 4.Search 5.Exit\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            traverseArray(arr, size);
            break;
        case 2:
            cout << "Element to insert: ";
            cin >> element;
            cout << "Position (0-based): ";
            cin >> position;
            insertElement(arr, size, capacity, element, position);
            break;
        case 3:
            cout << "Position to delete: ";
            cin >> position;
            deleteElement(arr, size, position);
            break;
        case 4:
            cout << "Element to search: ";
            cin >> element;
            searchElement(arr, size, element);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}

// Output:
// Menu:
// 1.Traverse 2.Insert 3.Delete 4.Search 5.Exit
// Enter choice: 2
// Element to insert: 99
// Position (0-based): 0
// Element inserted successfully!
// Menu:
// 1.Traverse 2.Insert 3.Delete 4.Search 5.Exit
// Enter choice: 2
// Element to insert: 33
// Position (0-based): 1
// Element inserted successfully!
// Menu:
// 1.Traverse 2.Insert 3.Delete 4.Search 5.Exit
// Enter choice: 1
// Array elements: 99 33
