/*NOTE: Counting sort makes assumptions about the data, for example, it assumes that values 
are going to be in the range of 0 to 10 or 10 – 99, etc, 
Some other assumption counting sort makes is input data will be all real numbers.
*/

#include <iostream>    
using namespace std;  
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
}  
  
void printArr(int a[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}  
  
// DRIVER CODE

int main() {  

    int n,i;
    cout<<"Enter the no. of Elements you want to enter: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter Only REAL numbers as array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //int arr[] = { 31, 11, 42, 7, 30, 11 };  
    //For determing the size of array a: int n = sizeof(a)/sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(arr, n);  
    countSort(arr, n);  
    cout<<"\nAfter sorting array elements are - \n";    
    printArr(arr, n);  
    return 0;  
}  