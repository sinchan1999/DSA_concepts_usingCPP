#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int start, int mid, int end)
{
    int i,j,k,L,R;
    L=mid-start+1;
    R=end-mid;

// Creating two temporary arrays for storing the elements after diving from mid.
    int temp_leftarr[L];
    int temp_rightarr[R];

    for(i=0; i<L; i++)
    {
        temp_leftarr[i]=arr[start+i];
    }
    
    for(j=0; j<R; j++)
    {
        temp_rightarr[j]=arr[mid+1+j];
    }

//Let's now merge the two temp arrays (i.e Left and Right array) in a sorted fashion and get our final sorted array!
i=0;
j=0;
k=start;

//We will pick the smallest, after comparing both the halves (i.e temp arrays!)
while (i<L && j<R)
{
    if(temp_leftarr[i]<=temp_rightarr[j])
    {
        arr[k]=temp_leftarr[i];
        k++;
        i++;
    }
    else
    {
        arr[k]=temp_rightarr[j];
        k++;
        j++;
    }
}

/* It is obvious that either of the halves/temp arrays may reach their max (L/R) while the case may differ for the other!
 So, for handling such situtation we will simply push the elements which are all ready being sorted in the temp arrays! */
while(i<L)
{
    arr[k]=temp_leftarr[i];
    k++;
    i++;
}

while(j<R)
{
    arr[k]=temp_rightarr[j];
    k++;
    j++;
}

}



void mergeSort(int arr[], int start, int end)  
{  
    if (start < end)   
    {  
        int mid = (start + end) / 2;  
        mergeSort(arr, start, mid);  
        mergeSort(arr, mid + 1, end);  

        //Calling the merge function for merging the divide halves!
        merge(arr, start, mid, end);  
    }  
}  


/* Function to print the final/sorted array */  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<arr[i]<<" ";  
}  



//DRIVER CODE
int main()
{
    int n,i;
    cout<<"Enter the no. of Elements you want to enter: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the Array elements: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }


    cout<<"Before sorting array elements are - \n";  
    printArray(arr, n);  

    mergeSort(arr, 0, n - 1);  

    cout<<"\nAfter sorting array elements are - \n";  
    printArray(arr, n);  
    return 0;  
}