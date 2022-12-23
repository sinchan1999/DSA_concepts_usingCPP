/*FOR MORE DETAILS:    https://takeuforward.org/data-structure/radix-sort-explained/
*/

#include <iostream>

using namespace std;

void countSort(int arr[], int n, int place) {
  int count[10];
  for (int i = 0; i < 10; i++) count[i] = 0;
  for (int i = 0; i < n; i++) count[(arr[i] / place) % 10]++; // building the count array
  for (int i = 1; i < 10; i++) count[i] = count[i - 1] + count[i]; // modifying the count array

  // building the output array
  int res[n];
  for (int i = n - 1; i >= 0; i--) {
    res[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }
  for (int i = 0; i < n; i++) arr[i] = res[i];
}
void radixSort(int arr[], int n) {
  // finding the maxElement
  int maxElement = arr[0];
  for (int i = 0; i < n; i++) {
    maxElement = max(maxElement, arr[i]);
  }

  // for every digit in the maxElement, running count sort
  for (int place = 1; maxElement / place > 0; place *= 10) {
    countSort(arr, n, place);
  }
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
int main() {
  int arr [] = { 326, 311, 3, 4, 120, 65}; 
  int n = 6;
  radixSort(arr, n);
  return 0;
}