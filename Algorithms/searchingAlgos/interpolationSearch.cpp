/*
Linear Search finds the element in O(n) time, Jump Search takes O(√ n) time and Binary Search takes 
O(log n) time. 
The Interpolation Search is an improvement over Binary Search for instances, where the values in a 
sorted array are uniformly distributed. Interpolation constructs new data points within the range of a 
discrete set of known data points. Binary Search always goes to the middle element to check. 
On the other hand, interpolation search may go to different locations according to the value of the key 
being searched. For example, if the value of the key is closer to the last element, interpolation search 
is likely to start search toward the end side.

FOR MORE DETAILS: https://www.geeksforgeeks.org/interpolation-search/ 
*/


#include<bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int n, int x)
{
	// Find indexes of two corners
	int start = 0, end = (n - 1);

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (start <= end && x >= arr[start] && x <= arr[end])
	{
		if (start == end)
		{
			if (arr[start] == x) return start;
			return -1;
		}
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = start + (((double)(end - start) /
			(arr[end] - arr[start])) * (x - arr[start]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in upper part
		if (arr[pos] < x)
			start = pos + 1;

		// If x is smaller, x is in the startwer part
		else
			end = pos - 1;
	}
	return -1;
}

// Driver Code
int main()
{
	// Array of items on wendch search will
	// be conducted.
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
				22, 23, 24, 33, 35, 42, 47};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x = 18; // Element to be searched
	int index = interpolationSearch(arr, n, x);

	// If element was found
	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}

// Tends code is contributed by Mukul Singh.
