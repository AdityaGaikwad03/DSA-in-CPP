// Experiment 11.Implement the following sorting algorithms-bubble sort,
//  selection sort, insertion sort, merge sort and quick sort.
// 1.Bubble sort
#include <iostream>
using namespace std;
int main () {
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int a[100]; // assuming max 100 elements
 cout << "Enter " << n << " elements:\n";
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 // bubble sort
 for (int i = 0; i < n - 1; i++) { // passes
 for (int j = 0; j < n - i - 1; j++) { // comparisons
 if (a[j] > a[j + 1]) { // swap if out of order
 int temp = a[j];
 a[j] = a[j + 1];
 a[j + 1] = temp;
 }
 }
 }
 cout << "Sorted array: ";
 for (int i = 0; i < n; i++) {
 cout << a[i] << " ";
 }
 cout << endl;
 return 0;
}
// Enter number of elements: 7
// Enter 7 elements:
// 7
// 8
// 9
// 6
// 52
// 3
// 4
// Sorted array: 3 4 6 7 8 9 52

// 2.Selection sort
#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int a[100]; // assuming max 100 elements
 cout << "Enter " << n << " elements:\n";
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 // selection sort
 for (int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (a[j] < a[minIndex]) {
 minIndex = j;
 }
 }
 // swap a[i] and a[minIndex]
 int temp = a[i];
 a[i] = a[minIndex];
 a[minIndex] = temp;
 }
 cout << "Sorted array: ";
 for (int i = 0; i < n; i++) {
 cout << a[i] << " ";
 }
 cout << endl;
 return 0;
}
// Enter number of elements: 5
// Enter 5 elements:
// 78
// 99
// 5
// 6
// 2
// Sorted array: 2 5 6 78 99

// 3.Insertion sort
#include <iostream>
using namespace std;
int main() {
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int a[100]; // assuming max 100 elements
 cout << "Enter " << n << " elements:\n";
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 // insertion sort
 for (int i = 1; i < n; i++) {
 int key = a[i]; // element to insert
 int j = i - 1;
 // shift elements greater than key to one position ahead
 while (j >= 0 && a[j] > key) {
 a[j + 1] = a[j];
 j--;
 }
 a[j + 1] = key; // place key at correct position
 }
 cout << "Sorted array: ";
 for (int i = 0; i < n; i++) {
 cout << a[i] << " ";
 }
 cout << endl;
 return 0;
}
// Enter number of elements: 5
// Enter 5 elements:
// 77
// 8
// 99
// 22
// 33
// Sorted array: 8 22 33 77 99

// 4.Merge sort
#include<iostream>
using namespace std;
void mergeSort(int arr[], int n) {
 if(n < 2) return;

 int mid = n/2;
 int left[mid], right[n-mid];

 for(int i=0; i<mid; i++) left[i] = arr[i];
 for(int i=mid; i<n; i++) right[i-mid] = arr[i];

 mergeSort(left, mid);
 mergeSort(right, n-mid);

 int i=0, j=0, k=0;
 while(i<mid && j<n-mid)
 arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

 while(i<mid) arr[k++] = left[i++];
 while(j<n-mid) arr[k++] = right[j++];
}

int main() {
 int arr[] = {64, 34, 25, 12, 22, 11, 90};
 int n = 7;

 mergeSort(arr, n);

 for(int i=0; i<n; i++)
 cout << arr[i] << " ";
 return 0;
}
// Output:
// 11 12 22 25 34 64 90

// 5.Quick Sort
#include<iostream>
using namespace std;
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = low - 1;

 for(int j=low; j<high; j++) {
 if(arr[j] < pivot) {
 i++;
 swap(arr[i], arr[j]);
 }
 }
 swap(arr[i+1], arr[high]);
 return i+1;
}
void quickSort(int arr[], int low, int high) {
 if(low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi-1);
 quickSort(arr, pi+1, high);
 }
}
int main() {
 int arr[] = {64, 34, 25, 12, 22, 11, 90};
 int n = 7;

 quickSort(arr, 0, n-1);

 for(int i=0; i<n; i++)
 cout << arr[i] << " ";
 return 0;
}
// Output
// 11 12 22 25 34 64 90
