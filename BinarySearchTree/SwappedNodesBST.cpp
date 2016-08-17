//Two nodes of a BST are swapped, correct the BST. Solved by using 2 pointers.
#include <iostream>  
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
 
void isBST(node* root,node* &prev,node* &first,node* &last)
 {
     if(root==NULL)
      return;  
    
     isBST(root->left,prev,first,last); 
    
     if(prev!=NULL && prev->data>root->data) // If not BST, then store nodes accordingly in first and last.
     {
         if(last)
             last=root;
         else
         {
          first=prev;
          last=root;
         }
     }   
   
     prev=root; 
   
    isBST(root->right,prev,first,last); 
 }
 
// Utility function to traverse the binary tree after conversion
void inorderTraversal(node* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
    return;
}

void correctBST(node* root)
{
    node* prev=NULL,*first=NULL,*last=NULL; 
    
    isBST(root,prev,first,last);   // to find the nodes swapped and storing them in first and last.
    swap(first->data,last->data);  // swapping the values of the swapped nodes.
    return;
}

int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    inorderTraversal(root);
 
    correctBST(root);
 
    printf("\nInorder Traversal of the corrected tree \n");
    inorderTraversal(root);
 
    return 0;
}
