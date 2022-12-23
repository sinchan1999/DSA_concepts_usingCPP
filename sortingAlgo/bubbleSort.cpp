#include <bits/stdc++.h>
using namespace std;

//Driver Code
int main()
{
    int n,i,counter,temp;
    
    cout<<"Enter the desired array size:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the array elements: "<<endl;
    for(i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    
    counter=1;
    while(counter<n)
    {
    for(i=0; i<n-counter; i++)
    {
        if(arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    counter++;
    }
    
    cout<<"Array in Ascending order: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i];
        cout<<"  ";
    }
    
}
