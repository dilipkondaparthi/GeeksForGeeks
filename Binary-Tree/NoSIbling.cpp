Print all nodes that don’t have sibling. Solved by using Level-Order Traversal.
#include<iostream> 
#include<queue> 
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


void printSinglesIterative(node* root)
{
    if(root==NULL)
        return;
    
    queue<node*>q;
    q.push(root);
    bool x,y;
      while(q.size())
   { 
       if(root->left)
       {
           q.push(root->left);
           x=true;
       } 
       else 
           x=false; 
       
       if(root->right)
       { 
           q.push(root->right);
           y=true; 
       }
        else 
           y=false; 
        
       if(x&&!y) 
           cout<<root->left->data<<" "; 
       else if(!x&&y) 
           cout<<root->right->data<<" "; 
       
       q.pop();
       root=q.front();
   }
}


int main()
{ 
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    printSinglesIterative(root);
    return 0;
}
