// Print Right View of a Binary Tree. Solved by using Level-Order traversal.
#include<iostream> 
#include<queue> 
using namespace std;

/* Author : Dilip.K */
struct node
{
    node * left;
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


void rightView(node* root)
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    bool check=true;
    int count; 
    cout<<root->data<<" ";
    while(!q.empty())
    {
     count=q.size();
     check=true;
     while(count--)
     {
      if(root->right)
      {
          q.push(root->right);
          if(check)
          {
              cout<<root->right->data<<" ";
              check=false;
          }
      }
     
      if(root->left)
      {
          q.push(root->left);
           if(check)
          {
              cout<<root->left->data<<" ";
              check=false;
          }
      }
      
     q.pop();
     root=q.front();
     } 
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);  
    root->right->left->right = newNode(8);  
 
    rightView(root);
 
    return 0;
}
