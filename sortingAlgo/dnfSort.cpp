
//Sort an array in a waveform:(Wave sort)

#include<bits/stdc++.h>
using namespace std;

/*Efficient Solution using the single scan — Incrementing the loop by two
In this approach, we compare adjacent elements at odd and even places at every iteration. The idea is to make sure that all elements at even positions are greater (or smaller) than their adjacent elements.

Algorithm Steps:
>> Iterate over even positioned elements at every step.
     >> If the current element is smaller than the last odd element, then swap the current element with the last element.
     >> If the current element is smaller than the next odd element, then swap the current element with the last element.*/


void sortInWave(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i+=2)
    {
        // If current even element is smaller than previous
        if (i>0 && arr[i-1] > arr[i] )
            swap(arr[i], arr[i-1]);
  
        // If current even element is smaller than next
        if (i<n-1 && arr[i] < arr[i+1] )
            swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,0,7,9,8,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}


/*Algorithm Analysis
The time complexity for the above algorithm would be O(n) because we are linearly traversing the elements of the array.

Space Complexity: O(1) as no extra memory is being used.*/
