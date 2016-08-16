//Print Left View of a Binary Tree. Solved by Level-Order Traversal.
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
  
void leftView(node* root)
{
    if(root==NULL)
        return;
    
    queue<node *> q;
    
    q.push(root);
    int count;
    bool check;
    while(q.size())
    {
        count=q.size();
        check=true;
        while(count--)
        {
            if(check)
            {
                cout<<root->data<<" ";
                check=false;
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            q.pop();
            root=q.front();
        }
    }
    return;
}
 
int main()
{ 
 struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
  
    leftView(root);
 
    return 0;
}
