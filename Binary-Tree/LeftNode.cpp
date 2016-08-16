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
 
void nextleftnode(node* root,int key)
{
    if(root==NULL)
        return;
    
    int level=0;
    queue<node* >q;
    queue<int>l;
    q.push(root);
    l.push(level); 
    while(q.size())
    {
        
        level=l.front();
        l.pop();
      if(q.front()->data==key)
      {
         if( q.size()==1 || level!=l.front() )
        {
            cout<<"No next left node found for "<<key<<endl;
            return;
        }
        
         else  
        {
            q.pop();
            cout<<q.front()->data<<endl;
            return;
        }
      }
        
        if(root->right)
        {
            q.push(root->right);
            l.push(level+1);
        }
        
        if(root->left)
        {
            q.push(root->left);
            l.push(level+1);
        } 
        
        q.pop();
        root=q.front();
        
    } 
    return;
}

int main()
{
 node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
 
    nextleftnode(root, 10);
    nextleftnode(root, 2);
    nextleftnode(root, 6);
    nextleftnode(root, 5);
    nextleftnode(root, 8);
    nextleftnode(root, 4);
 
    return 0;
}
