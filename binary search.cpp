#include <iostream> 
using namespace std;
int main() {
int n, key, low, high, mid, index = -1;
cout << "Enter number of elements: "; 
cin >> n;
int arr[n];
cout << "Enter " << n << " elements in sorted order: "; 
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
cout << "Enter the element to search: "; 
cin >> key;
low = 0; 
high = n - 1;
// Binary Search
while (low <= high) {
mid = (low + high) / 2;
if (arr[mid] == key) { 
index = mid;
break;
}
else if (arr[mid] < key) { 
low = mid + 1;
}
else {
high = mid - 1;
}
}
if (index != -1) {
cout << "Element found at index " << index << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
