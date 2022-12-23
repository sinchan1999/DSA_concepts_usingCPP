#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[],int n,int key)
{
    for(int i=0; i<n; i++)
    {
        if (arr[i]==key)
        {
            cout<<"Element found at index: ";
            return i;
            break;
        }
        
    }
    return -1;
}

//Driver Code
int main()
{
    int n,key;
    cout<<"Enter the array length\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements:";
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the element you want to find: "<<endl;
    cin>>key;
    
    cout<<LinearSearch(arr, n, key)<<endl;
    return 0;
}

