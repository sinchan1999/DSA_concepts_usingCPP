#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next; 
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

    void insertAtHead(node* &head, int val)
    {
        node* newnode=new node(val);        
        if(head != NULL)
        {
            head->prev=newnode; 
        }             
        newnode->next=head; 
        head=newnode;     
    }


    void insertAtTail(node* &head, int val)
    {
        if(head == NULL)
        {
            insertAtHead(head, val);
            return;
        }
        node* newnode=new node(val);
        node* temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        //newnode->next is already pointing towards NULL bcz of our constructor!

    }

    void display(node* head)
    {   
    node* temp=head; 
    cout<<"NULL<-";
    while(temp!=NULL)
    {        
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"-->NULL"<<endl;
    cout<<"***Remember the nodes in btw two NULL are connected in both ways i.e -><- cz this is Double LL "<<endl;
    }


    int main() 
{

    node* head=NULL;  
    
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50); 
    insertAtHead(head, 100); 

    cout<<"The Double LL : ";
    display(head);


};