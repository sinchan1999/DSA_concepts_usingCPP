#include <bits/stdc++.h>
using namespace std;

//Driver Code
int main()
{
    int n,i,current,j;
    
    cout<<"Enter the desired array size:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the array elements: "<<endl;
    for(i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(i=1; i<n; i++)
    {
        current=arr[i];
        j=i-1;
        while(arr[j]>current && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
    
    
    cout<<"Array in Ascending order: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i];
        cout<<"  ";
    }
    
}
