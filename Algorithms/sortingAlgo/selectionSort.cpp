#include <bits/stdc++.h>
using namespace std;


//Driver Code
int main()
{
    int n,i,j,temp;
    
    cout<<"Enter the desired array size:";
    cin>>n;
    int arr[n];
    cout<<"\n Enter the array elements: "<<endl;
    for(i=0; i<n;i++)
    {
        cin>>arr[i];
    }
    
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout<<"Array in Ascending order: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i];
        cout<<"  ";
    }
    
}
