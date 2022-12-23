#include <bits/stdc++.h>
using namespace std;

int BinarySearch (int arr[], int n, int key)
{
    int mid,start,end;
    start=0; 
    end=n;
    while(start<=end)
    {
        mid=(start+end)/2;
        
        if(arr[mid]==key)
        {
            cout<<"Element found at index: ";
            return mid;
            break;
        }
        
        else if(arr[mid]>key)
        end=mid-1;
        
        else
        start=mid+1;
    }
    return -1;
}

//Driver Code
int main()
{
    int n,key;
    cout<<"Enter the desired array size:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the array elements in ASCENDING order only: "<<endl;
    for(int i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element that you want to find: "<<endl;
    cin>>key;
    
    cout<<BinarySearch(arr, n, key);
}
