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

node* reverse_Knodes(node* &head, int k)
{

// BASE CASE: If the LL is empty or it has only 0 or 1 element then just return same !
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node* prev_ptr=NULL;
    node* curr_ptr=head;
    node* next_ptr;

    // Reversing First K-nodes by Iterative method.
    int counter=1;
    while (curr_ptr != NULL && counter<=k)
    {
        next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;

        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
        counter++;
    }

    /* Reversing the rest of the LL by using Recursive method. Here we are just joinnig the reversed 1st
    half with the reversed rest half! By pointing the head from the 1st half*/
    if (next_ptr != NULL)
    {
    head->next = reverse_Knodes(next_ptr, k);
    }

    return prev_ptr;

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
    
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 70);
    insertAtHead(head, 80);
    insertAtHead(head, 90); 
    insertAtHead(head, 100); 

    cout<<"Original LL: ";
    display(head);  
    cout<<"\n";

    int K;
    cout<<"Enter the value of K which must be greater than 0 : ";
    cin>>K;
    node* Knodes_rev = reverse_Knodes (head, K);
    cout<<"K-nodes reversion : ";
    display(Knodes_rev);
    cout<<"\n";

}

// TIME COMPLEXCITY: O(n) , as we are traversing once only!