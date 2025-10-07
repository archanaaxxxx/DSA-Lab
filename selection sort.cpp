#include <iostream> 
using namespace std;
int main() { 
int n;
cout << "Enter number of elements: "; 
cin >> n;
int arr[n];
cout << "Enter " << n << " elements: "; 
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
// Selection Sort
for (int i = 0; i < n - 1; i++) {
int minIndex = i; // Assume the current index is the smallest 
for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j; // Update minIndex if smaller element found
}
}
// Swap the found minimum with the first element 
int temp = arr[i];
arr[i] = arr[minIndex]; 
arr[minIndex] = temp;
}
cout << "Sorted array: "; 
for (int i = 0; i < n; i++) { 
cout << arr[i] << " ";
}
cout << endl;
return 0;
}
