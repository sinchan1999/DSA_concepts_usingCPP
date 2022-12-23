#include <bits/stdc++.h>
using namespace std;

#define n 5
class Queue
{
    int* arr;
    int front;
    int back;
    
    public:
    Queue()
    {
        arr=new int[n];
        front= -1;
        back= -1;
    }
    
    void push(int x)
    {
        if(back == n-1)
        {
            cout<<"Queue Overflow !!!"<<endl;
            return;
        }
        
        back++;
        arr[back]=x;
        
        if(front == -1)
        {
        front++;  //Just for first time
        }
    }
    
    void pop()
    {
        if(front == -1 || front>back)
        {
            cout<<"Queue is Empty !"<<endl;
            return;
        }
        front++; //Just keep on moving front every time pop()is called.
    }
    
    int peek()
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue is Empty !"<<endl;
            return -1;
        }
        
        return arr[front];
    }
    
    bool empty()
    {
        if(front==-1 || front>back)
        {
            return true;
        }
        
        return false;
    }
};

int main()
{
    Queue Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(100);
    Q.push(200);

    for(int i =0; i<= n+2; i++)
    {    
    cout<<"\nITERATION: "<<i<<endl;
    cout<<"Current peek() after prev Iteration ---> "<<Q.peek()<<endl;
    cout<<"Calling pop()....."<<endl;
    Q.pop();
    }    
        
}
