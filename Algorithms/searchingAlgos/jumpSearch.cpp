/*Like Binary Search, Jump Search is a searching algorithm for sorted arrays. 
The basic idea is to check fewer elements (than linear search) by jumping ahead 
by fixed steps or skipping some elements in place of searching all elements.

**** Performance in comparison to linear and binary search:
If we compare it with linear and binary search then it comes out then it is better than 
linear search but not better than binary search.

The increasing order of performance is:
linear search  <  jump search  <  binary search


What is the optimal block size to be skipped? 
In the worst case, we have to do n/m jumps, and if the last checked value is greater than 
the element to be searched for, we perform m-1 comparisons more for linear search. 
Therefore, the total number of comparisons in the worst case will be ((n/m) + m-1). 
The value of the function ((n/m) + m-1) will be minimum when m = √n. 
Therefore, the best step size is m = √n.

FOR MORE DETAILS:   https://www.geeksforgeeks.org/jump-search/
*/


// C++ program to implement Jump Search

#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
	// Finding block size to be jumped
	int step = sqrt(n);

	// Finding the block where element is
	// present (if it is present)
	int prev = 0;
	while (arr[min(step, n)-1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	// Doing a linear search for x in block
	// beginning with prev.
	while (arr[prev] < x)
	{
		prev++;

		// If we reached next block or end of
		// array, element is not present.
		if (prev == min(step, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

// Driver program to test function
int main()
{
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
				34, 55, 89, 144, 233, 377, 610 };
	int x = 144;
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Find the index of 'x' using Jump Search
	int index = jumpSearch(arr, x, n);

	// Print the index where 'x' is located
	cout << "\nNumber " << x << " is at index " << index;
	return 0;
}

// Contributed by nuclode
