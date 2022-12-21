#include <bits/stdc++.h>
using namespace std;

// Node is not built-in so we are defining it.
class node{
    public:
    int data;
    node* next; //Pointer for the newnode.

    //Defining a constructor for passing the values in data fields of newnode.
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

// Using the reference of head, as we need to modify the values!
void insertAtTail(node* &head, int val)
{
    /*Creating a new node by calling the node constructor. After which 
    the newnode will have val in the data field & NULL in the next */
    node* newnode = new node(val);

    //If the LL is empty then we can insert the value directly at head, else we need to traverse the LL!
    if(head==NULL)
    {
        head=newnode;
        return;
    }

    else
    {
    /* We need to traverse the Linked List from start(head) to end(NULL)
    Creating a temporary pointer (temp) for the traversing purpose */
    node* temp= head;
    while(temp->next!= NULL) 
    {
        temp=temp->next;
    }
    // Now after the loop we are at the end of the LL.Now, we can add the newnode.
    temp->next=newnode;

    } 
} 


void insertAtHead(node* &head, int val)
{
    node* newnode = new node(val);
    newnode->next=head; //cz by constructor it will get assigned to NULL bt here we need to insert at start, and its next should be head!
    head=newnode;
}



//Taking head by value not by reference because we are not modifying the value. 
void display(node* head)
{
    node* temp=head; //we could also have taken head as a pointer instead of temp.
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


bool search(node* head, int key)
{
    node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp=temp->next;
    }
    //if (temp->next == NULL)
    return false;
}



void deletion(node* &head, int val)
{
    //CASE 1: Checking if the LL is empty, then we will do nothing!
    if (head==NULL)
    {
        return;
    }

    /*CASE 2: If there is only 1 element present, then it must be the head element
      CASE 3: The LL has more than 1 element but the value to be deleted is present at the HEAD
              condition (2ND ONE).  */

    else if ( (head->next==NULL) || (head->data == val)) 
    {
        node* todelectnode=head;
        head=head->next;

        delete todelectnode;
        return;
    }
    

    //CASE 4: Element to be deleted is present elsewhere in the MIDDLE OR END.
    else
    { 
     node* temp=head;
    while(temp->next->data != val) // Searching the node(n-1) just before of val (n) node!
    {
        temp=temp->next;     
    }
    //Storing Node(n) we want to delete for freeing it up at last after the new linkage formation!
    node* todeletenode= temp->next ;

    /*Moving the presrnt node (n-1) link 2times to point the node(n+1) just after the node(n) we want to delete !
    After 2 times next ( i.e temp->next->next ) it will point to node n+1 bypassing the n-1 to n linkage
    Thus, we will obtain new linkage directly from n-1 to n+1 . 
    After which we can just delete the old linkage from n-1 to n*/
    temp->next= temp->next->next ;

    delete  todeletenode;
    }       

}


int main() 
{

    node* head=NULL;  // Defining this, means our LL is empty!

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    insertAtHead(head, 50);
    insertAtHead(head, 60);
    insertAtHead(head, 100); 

    //insertAtTail(head, 40);

    display(head);  // Displaying the output LL ops.

 /* Open this Section for Searching ops
    int key;
    cout<<"Enter the value you want to search in the LL"<<endl;
    cin>>key;
    cout <<"Search result: "<< search(head, key)<<endl;
 */


    int deletenode;
    cout<<"Enter the value you want to delete from the LL"<<endl;
    cin>>deletenode;   
    deletion(head, deletenode);
    cout<<"Result after Deletion: "<<endl;
    display(head);    
    
    return 0;
 }
