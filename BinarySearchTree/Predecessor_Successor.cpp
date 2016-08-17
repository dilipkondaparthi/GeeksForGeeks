// Find Inorder predecessor and successor for a given key in BST.
// Approach: By converting BST to DoubleLinkedList and then traversing through the list.

#include <iostream> 
#include <stack> 
using namespace std;

/* Author : Dilip.K */
struct node
{
    node* left;
    node* right; 
    int data;
};

node* newNode(int x)
{
    node* temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=x;
    return temp;
}

struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
 
    /* Otherwise, recur down the tree */
    if (data <= node->data)
        node->left  = insert(node->left, data);
    else
        node->right = insert(node->right, data);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
 void convertBSTtoDLL(node* root,node* &head,node* &tail)
{
 if(root==NULL)
     return;
 
 convertBSTtoDLL(root->left,head,tail);
 
 if(tail)
     tail->right=root;
 else
     head=root;
 
 root->left=tail;
 tail=root;
 
 convertBSTtoDLL(root->right,head,tail);
 
} 
 
 void findPreSuc(node* root,node* &pre, node* &suc,int key)
 {
     node* head=NULL,*tail=NULL;
     
     convertBSTtoDLL(root,head,tail); // first convert binary search tree to double linked list
    
     while(head!=NULL)     // Traverse through the DLL till the end.
     {
         if(head->data==key) // for eg: DLL is 20 30 40 50, and key=30, then for 30==30(i.e,head->data==key), the next node is the succesor.
         {
             suc=head->right;
             return;
         }
         else if(head->data<key) 
         {
             pre=head;
             head=head->right;
         }
         else  // for eg: DLL is 20 30 40 50, and key=35, then for 40>35(i.e,head->data>key) this condition becomes true.
         {
             printf("Node with %d value not found, but it lies between (%d,%d)\n",key,pre->data,head->data);
             pre=NULL;
             return;
         }
     }
    
 }

int main()
{
    node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc,80);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor\n";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data<<endl;
    else
      cout << "No Successor\n";
    return 0;
}
