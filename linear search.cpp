#include <iostream> 
using namespace std;
int main() {
int n, key, index = -1;
cout << "Enter number of elements: "; 
cin >> n;
int arr[n];
cout << "Enter " << n << " elements: "; 
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
cout << "Enter the element to search: "; 
cin >> key;
// Linear Search
for (int i = 0; i < n; i++) { 
if (arr[i] == key) {
index = i; 
break;
}
}
if (index != -1) {
cout << "Element found at index " << index << endl;
} else {
cout << "Element not found in the array" << endl;
}
return 0;
}
