#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left_child;
    struct Node* right_child;
    
    Node(int val)
    {
        data=val;
        left_child=NULL;
        right_child=NULL;
    }
};

int main() {
    struct Node* root=new Node(1);
    root->left_child =new Node(2);
    root->right_child=new Node(3);
/* After, this now out BT looks like below:
                 1
               / \
              2  3   */
    root->left_child->left_child=new Node(4);
    root->right_child->right_child=new Node(5);
/*               1
               / \
              2  3 
             /    \
            4      5 */
    return 0;
}
