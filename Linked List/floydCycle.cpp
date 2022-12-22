#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next; 

    node(int val)
    {
        data=val;
        next=NULL;
    }
};


void insertAtHead(node* &head, int val)
{
    node* newnode = new node(val);
    newnode->next=head; 
    head=newnode;
}

                   /*FLOYD'S CYCLE ALGO   OR    HARE-TORTOSIE ALGO*/


bool detectCycle(node* &head)
{
    node* slow_ptr=head; //slow_ptr is tortoise
    node* fast_ptr=head; //fast_ptr is hare
   
    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next; // fast_ptr will move by 2steps whereas slow_ptr will move by 1step!

        if(fast_ptr == slow_ptr)
        {
            return true; //If both pointers meet that means we have a cycle!
        }
    }
    return false;
}


void createCycle(node* &head, int pos)
{
    node* temp=head;
    node* startCycle;

    int counter=1;
    while (temp->next != NULL)
    {
        if(counter == pos)
        {
            startCycle = temp;
        }
        temp=temp->next;
        counter++;
    }
    temp->next = startCycle; // Pointing back the next of last node in LL to the Start of the cylce at position pos. Thus completing a cycle!
}


void removeCycle(node* &head)
{
    node* slow_ptr=head;
    node* fast_ptr=head;

    do
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    } while (slow_ptr != fast_ptr);

// CASE 1: If the cycle starts from the HEAD in our LL.

    if(fast_ptr==head){
        while(slow_ptr->next!=head)
        {
        slow_ptr=slow_ptr->next ;
        }
        slow_ptr->next=NULL ;
        return ;
    }

//CASE 2:If the cycle starts from anywhere except the HEAD of LL.
    fast_ptr=head;
    while (slow_ptr->next != fast_ptr->next)   
    {
        slow_ptr= slow_ptr->next;
        fast_ptr= fast_ptr->next;
    }
    /*When the above loop will end it means both pointers are pointing to the same node which is nothing but
    the starting point of our Cycle! Now, we will simple break the link by pointing it to NULL*/
    slow_ptr->next = NULL;  
    
}


 
void display(node* head)
{
    node* temp=head; 
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main() 
{

    node* head=NULL;  
    
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50); 
    insertAtHead(head, 60); 

    cout<<"Origianl LL: ";
    display(head);

    // Creating a Cycle
    cout<<"Creating a Cycle..... "<<endl;
    createCycle(head, 4);
    
/* CAUTION: Don't open this piece of code its a infinite cycle 
    cout<<"After creating Cycle: ";
    display(head);    */

    cout<<"Cycle Detected : "<<detectCycle(head)<<endl;
    cout<<"Calling the removeCycle()......."<<endl;
    removeCycle(head);

    cout<<"Cycle Detected after calling : "<<detectCycle(head)<<endl;

    cout<<"Current LL: ";
    display(head);

    return 0;
}

