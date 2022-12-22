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

/* METHOD 1: Iterative way, Here we need 3 pointers where initially,
curr_ptr points the 1st/head element of the LL
prev_ptr is NULL, (will point previous of curr_prt)
next_ptr points to the next of curr_ptr and stors the link*/                             
node* reverse(node* &head)
{
    node* prev_ptr = NULL;
    node* curr_ptr = head;
    node* next_ptr ;

    while (curr_ptr != NULL)
    {
        next_ptr = curr_ptr->next; // Functioning just like temp for storing the next link.
        curr_ptr->next = prev_ptr; // Reversing the link to point its prev element !

        // Moving the pointers one element ahead. next_ptr will move at the begining only!
        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    
    return prev_ptr; // Now after reversion this will be our new HEAD.

}




                         /*METHOD 2: By using Recurrsion*/

node* reverseRecursive(node* &head)
{

// BASE CASE: If the LL is empty or it has only 0 or 1 element then just return same !
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    /* Reversing the LL starting from 2nd node! 
    After which the newhead will reach the end of original LL and will become the HEAD of rev. LL 
    and the LL will get reversed from 2nd to last . In later steps will just change the link of the
    2nd and Original HEAD node to be the 2nd last and Last of out Rev. LL*/
    node* newhead = reverseRecursive(head->next); 

    head->next->next = head;// Reversing the link of the 2node to the HEAD(last of this Rev.LL) OF original LL. (This becomes 2nd last node)
    head->next = NULL; // Now, this becomes the last node

    return newhead;
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

                    /* *** OPEN ANY ONE METHOD AT A TIME !!! ELSE ERROR */

    /*node* reverse_METHOD_1 = reverse(head);
    cout<<"Reversion using Iteration : ";
    display(reverse_METHOD_1);
    cout<<"\n"; */


    node* reverse_METHOD_2 = reverseRecursive(head);
    cout<<"Reversion using Recurrsion: ";
    display(reverse_METHOD_2);
    cout<<"\n";



}