
#include <bits/stdc++.h>
using namespace std;

#define n 5

class Stack
{
    int* arr;
    int top;
    
    public:
    Stack()
    {
    arr=new int[n];
    top=-1;
    }
    
    
    void push(int val)
{
    if(top==n-1)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top]=val;
    
}

void pop()
{
    if(top==-1)
    {
        cout<<"No elments to remove! Its already Empty"<<endl;
        return;
    }
    top--; 
}

int TOP()
{
    if(top==-1)
    {
        cout<<"Your stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}

bool empty()
{
    cout<<"Is the Stack empty? --  "<<endl;
    if(top==0){
    return true; 
    }
    return false;
}
};



int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(100);
    cout<<"Top = "<<st.TOP()<<endl;
    
    return 0;
}

